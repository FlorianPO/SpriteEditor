#include "Fonction.h"

int Fonction::copy_to_clipboard(sf::Image *image) {
	sf::Uint8* buffer;
	HGLOBAL clipbuffer;

	int buflen = image->getSize().x*image->getSize().y * 4;

	//Header
	BITMAPINFOHEADER header;
	header.biSize = sizeof(BITMAPINFOHEADER);
	header.biWidth = image->getSize().x;
	header.biHeight = image->getSize().y;
	header.biPlanes = 1;
	header.biBitCount = 32;
	header.biCompression = BI_RGB;
	header.biSizeImage = 0;
	header.biXPelsPerMeter = 2835;
	header.biYPelsPerMeter = 2835;
	header.biClrUsed = 0;
	header.biClrImportant = 0;

	if (!OpenClipboard(NULL)) { return 1; }

	//BGR
	EmptyClipboard();
	clipbuffer = GlobalAlloc(GMEM_MOVEABLE, buflen + sizeof(BITMAPINFOHEADER));

	if ((buffer = static_cast<sf::Uint8*>(GlobalLock(clipbuffer))) == NULL) {
		GlobalUnlock(clipbuffer);
		CloseClipboard();
		return 2;
	}

	memcpy(buffer, &header, sizeof(BITMAPINFOHEADER));

	FOR_J (image->getSize().y)
		FOR_I (image->getSize().x) {
			sf::Color temp = image->getPixel(i, j);
			image->setPixel(i, j, sf::Color(temp.b, temp.g, temp.r, temp.a));
		}
	image->flipVertically();

	memcpy(buffer + sizeof(BITMAPINFOHEADER), image->getPixelsPtr(), buflen);

	GlobalUnlock(clipbuffer);
	SetClipboardData(CF_DIB, clipbuffer);

	CloseClipboard();
	GlobalFree(clipbuffer);
	return 0;
}

int Fonction::copy_to_clipboard(std::string string) {
	if (!OpenClipboard(NULL)) { return 1; }

	EmptyClipboard();
	HGLOBAL hg = GlobalAlloc(GMEM_MOVEABLE, string.size() + 1);
	if (!hg) {
		CloseClipboard();
		return 2;
	}
	memcpy(GlobalLock(hg), string.c_str(), string.size() + 1);
	GlobalUnlock(hg);
	SetClipboardData(CF_TEXT, hg);
	CloseClipboard();
	GlobalFree(hg);

	return 0;
}

sf::String Fonction::get_macro() {
	// Try opening the clipboard
	if (!OpenClipboard(nullptr))
		return sf::String();
	HANDLE hData = GetClipboardData(CF_TEXT);
	if (hData == nullptr)
		return sf::String();

	char* pszText = static_cast<char*>(GlobalLock(hData));
	if (pszText == nullptr)
		return sf::String();

	// Save text in a string class instance
	std::string text(pszText);
	GlobalUnlock(hData);
	CloseClipboard();

	return sf::String(text);
}

sf::Image* Fonction::get_clipboard() {
	sf::Uint8* buffer;
	HANDLE hData;

	if (!OpenClipboard(NULL)) { return NULL; }
	if ((hData = GetClipboardData(CF_DIB)) == NULL) { return NULL; }
	if ((buffer = static_cast<sf::Uint8*>(GlobalLock(hData))) == NULL) { return NULL; }

	int SIZE_HEADER = *reinterpret_cast<int*>(buffer);
	int NBR_BIT = *reinterpret_cast<int*>(buffer + 14);
	int width = *reinterpret_cast<int*>(buffer + 4);
	int height = *reinterpret_cast<int*>(buffer + 8);

	int buflen = width * std::abs(height)*(NBR_BIT / 8) + SIZE_HEADER;
	sf::Uint8* buffer2 = new sf::Uint8[buflen + sizeof(BITMAPFILEHEADER)];

	//Header
	BITMAPFILEHEADER header;
	header.bfType = 0x4D42;
	header.bfSize = 0;
	header.bfReserved1 = 0;
	header.bfReserved2 = 0;
	header.bfOffBits = sizeof(BITMAPFILEHEADER) + SIZE_HEADER;

	memcpy(buffer2, &header, sizeof(BITMAPFILEHEADER));
	memcpy(buffer2 + sizeof(BITMAPFILEHEADER), buffer, buflen);

	sf::Image* image = new sf::Image();
	image->loadFromMemory(buffer2, buflen + sizeof(BITMAPFILEHEADER));
	delete[] buffer2;

	GlobalUnlock(hData);
	CloseClipboard();

	return image;
}