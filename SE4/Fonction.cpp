#include "Fonction.h"

#include "Input.h"
#include "Var.h"
#include "App.h"
#include "Selec.h"
#include "Calque.h"
#include "Retour.h"
#include "Res.h"
#include "Copy.h"

bool CFonction::onSprite(const sf::Sprite* sprite)
{
	sf::FloatRect rect = sprite->getGlobalBounds();
	return rect.contains(IO->getPosition());
}

int CFonction::change_number()
{
	int incr = (IO->log(CInput::MLeft) || IO->again(CInput::MWAdd)) - (IO->log(CInput::MRight) || IO->again(CInput::MWSub));

	if (IO->pressed(CInput::Ctrl) && IO->pressed(CInput::Maj))
	{
		if (IO->log(CInput::MLeft) || IO->again(CInput::MWAdd)) incr = 255;
		if (IO->log(CInput::MRight) || IO->again(CInput::MWSub)) incr = -255;
	}
	else if (IO->pressed(CInput::Ctrl))
	{
		if (IO->log(CInput::MLeft) || IO->again(CInput::MWAdd)) incr = 5;
		if (IO->log(CInput::MRight) || IO->again(CInput::MWSub)) incr = -5;
	}
	else if (IO->pressed(CInput::Maj))
	{
		if (IO->log(CInput::MLeft) || IO->again(CInput::MWAdd)) incr = 50;
		if (IO->log(CInput::MRight) || IO->again(CInput::MWSub)) incr = -50;
	}
	return incr;
}

sf::Vector2f CFonction::selecPointRect(sf::Vector2f pos_ini, sf::Vector2f pos)
{
	float a = std::max(std::abs(pos.x - pos_ini.x), std::abs(pos.y - pos_ini.y));

	sf::Vector2f points[8];
	points[0] = sf::Vector2f(pos_ini.x - a, pos_ini.y - a);
	points[1] = sf::Vector2f(pos_ini.x, pos_ini.y - a);
	points[2] = sf::Vector2f(pos_ini.x + a, pos_ini.y - a);
	points[3] = sf::Vector2f(pos_ini.x + a, pos_ini.y);
	points[4] = sf::Vector2f(pos_ini.x + a, pos_ini.y + a);
	points[5] = sf::Vector2f(pos_ini.x, pos_ini.y + a);
	points[6] = sf::Vector2f(pos_ini.x - a, pos_ini.y + a);
	points[7] = sf::Vector2f(pos_ini.x - a, pos_ini.y);

	float distance[8];

	for (int i = 0; i < 8; i++)
		distance[i] = std::sqrt(std::pow(points[i].x - pos.x, 2) + std::pow(points[i].y - pos.y, 2));

	int j = 0;
	for (int i = 0; i < 8; i++)
		if (distance[i] < distance[j])
			j = i;

	return points[j] - pos_ini;
}

sf::Vector2f* CFonction::selecPoint(sf::Sprite* sprite, sf::Vector2f pos, float seuil)
{
	sf::FloatRect rect = sprite->getGlobalBounds();
	sf::Vector2f points[9];
	points[0] = sf::Vector2f(rect.left, rect.top);
	points[1] = sf::Vector2f(rect.left + rect.width, rect.top);
	points[2] = sf::Vector2f(rect.left, rect.top + rect.height);
	points[3] = sf::Vector2f(rect.left + rect.width, rect.top + rect.height);
	points[4] = sf::Vector2f(rect.left + rect.width / 2.f, rect.top + rect.height / 2.f);

	sf::FloatRect rect2 = sf::FloatRect(0, 0, sprite->getTextureRect().width * sprite->getScale().x, sprite->getTextureRect().height * sprite->getScale().y);
	points[5] = sf::Vector2f(0, 0);
	points[6] = sf::Vector2f(rect2.width, 0);
	points[7] = sf::Vector2f(0, rect2.height);
	points[8] = sf::Vector2f(rect2.width, rect2.height);

	float angle = -sprite->getRotation() / 180 * VAR->PI;
	for (int i = 5; i < 9; i++)
	{
		sf::Vector2f temp = points[i] - sf::Vector2f(sprite->getOrigin().x * sprite->getScale().x, sprite->getOrigin().y * sprite->getScale().y);
		points[i].x = temp.x*std::cos(angle) + temp.y*std::sin(angle);
		points[i].y = temp.y*std::cos(angle) - temp.x*std::sin(angle);

		points[i] += sprite->getPosition();
	}

	float distance[9];

	for (int i = 0; i < 9; i++)
		distance[i] = std::sqrt(std::pow(points[i].x - pos.x, 2) + std::pow(points[i].y - pos.y, 2));

	int j = 0;
	for (int i = 1; i < 9; i++)
		if (distance[i] < distance[j])
			j = i;
	if (distance[j] < seuil)
		return new sf::Vector2f(points[j]);
	return NULL;
}

sf::Vector2f CFonction::pointed(sf::Vector2i vect) //Retourne la coordonnée pointée
{
	sf::Vector2f vector;
	vector.x = APP->camera.getCenter().x - APP->camera.getSize().x / 2.f + vect.x / APP->zoom;
	vector.y = APP->camera.getCenter().y - APP->camera.getSize().y / 2.f + vect.y / APP->zoom;

	return vector;
}

bool CFonction::onCalque(sf::Vector2i vect, const sf::Image* image_courant)
{
	return vect.x >= 0 && vect.x < image_courant->getSize().x && vect.y >= 0 && vect.y < image_courant->getSize().y;
}

bool CFonction::onCalque(sf::Vector2i vect, const sf::Texture* texture_courant)
{
	if (vect.x < 0 || vect.x >= texture_courant->getSize().x || vect.y < 0 || vect.y >= texture_courant->getSize().y)
		return false;
	return true;
}

sf::Color CFonction::getColor(sf::Vector2i vect, const sf::Image* image_courant)
{
	if (onCalque(vect, image_courant))
		return image_courant->getPixel(vect.x, vect.y);

	return sf::Color::Black;
}

float CFonction::hypothenus(float cote1, float cote2)
{
	float hyp = cote1*cote1 + cote2*cote2;
	return std::sqrt(hyp);
}

float CFonction::norme(sf::Vector2f direction)
{
	return std::sqrt(std::pow(direction.x, 2) + std::pow(direction.y, 2));
}

float CFonction::norme(sf::Vector2i direction)
{
	return std::sqrt(std::pow(direction.x, 2) + std::pow(direction.y, 2));
}

sf::IntRect CFonction::FloatRectToIntRect(sf::FloatRect rect)
{
	return sf::IntRect(rect.left, rect.top, rect.width, rect.height);
}

sf::Vector2f CFonction::centerSprite(const sf::Sprite* sprite)
{
	sf::FloatRect rect = sprite->getGlobalBounds();
	return sf::Vector2f(rect.left + rect.width / 2.f, rect.top + rect.height / 2.f);
}

sf::Vector2f CFonction::cornerSprite(const sf::Sprite* sprite)
{
	sf::FloatRect rect = sprite->getGlobalBounds();
	return sf::Vector2f(rect.left, rect.top);
}

std::vector<sf::Vector2f>* CFonction::getPoints(sf::Sprite* sprite)
{
	std::vector<sf::Vector2f>* points = new std::vector<sf::Vector2f>();

	sf::FloatRect rect = sprite->getGlobalBounds();
	points->push_back(sf::Vector2f(rect.left, rect.top));
	points->push_back(sf::Vector2f(rect.left + rect.width, rect.top));
	points->push_back(sf::Vector2f(rect.left, rect.top + rect.height));
	points->push_back(sf::Vector2f(rect.left + rect.width, rect.top + rect.height));
	points->push_back(sf::Vector2f(rect.left + rect.width / 2.f, rect.top + rect.height / 2.f));

	points->push_back(sf::Vector2f(rect.left + rect.width / 2.f, rect.top));
	points->push_back(sf::Vector2f(rect.left + rect.width / 2.f, rect.top + rect.height));
	points->push_back(sf::Vector2f(rect.left, rect.top + rect.height / 2.f));
	points->push_back(sf::Vector2f(rect.left + rect.width, rect.top + rect.height / 2.f));

	return points;
}


int CFonction::copy_to_clipboard(sf::Image *image)
{
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

	if ((buffer = (sf::Uint8*)GlobalLock(clipbuffer)) == NULL)
	{
		GlobalUnlock(clipbuffer);
		CloseClipboard();
		return 2;
	}

	memcpy(buffer, &header, sizeof(BITMAPINFOHEADER));

	for (int j = 0; j < image->getSize().y; j++)
		for (int i = 0; i < image->getSize().x; i++)
		{
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

int CFonction::copy_to_clipboard(std::string string)
{
	if (!OpenClipboard(NULL)) { return 1; }

	EmptyClipboard();
	HGLOBAL hg = GlobalAlloc(GMEM_MOVEABLE, string.size() + 1);
	if (!hg){
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


sf::String CFonction::get_macro()
{
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

sf::Image* CFonction::get_clipboard()
{
	sf::Uint8* buffer;
	HANDLE hData;

	if (!OpenClipboard(NULL)) { return NULL; }
	if ((hData = GetClipboardData(CF_DIB)) == NULL) { return NULL; }
	if ((buffer = (sf::Uint8*)GlobalLock(hData)) == NULL) { return NULL; }
	GlobalUnlock(hData);
	CloseClipboard();

	int* SIZE_HEADER = (int*)(buffer);
	int* NBR_BIT = (int*)(buffer + 14);
	int* width = (int*)(buffer + 4);
	int* height = (int*)(buffer + 8);

	int buflen = (*width)*std::abs(*height)*(*NBR_BIT / 8) + *SIZE_HEADER;
	sf::Uint8* buffer2 = new sf::Uint8[buflen + sizeof(BITMAPFILEHEADER)];

	//Header
	BITMAPFILEHEADER header;
	header.bfType = 0x4D42;
	header.bfSize = 0;
	header.bfReserved1 = 0;
	header.bfReserved2 = 0;
	header.bfOffBits = sizeof(BITMAPFILEHEADER) + *SIZE_HEADER;

	memcpy(buffer2, &header, sizeof(BITMAPFILEHEADER));
	memcpy(buffer2 + sizeof(BITMAPFILEHEADER), buffer, buflen);

	sf::Image* image = new sf::Image();
	image->loadFromMemory(buffer2, buflen + sizeof(BITMAPFILEHEADER));
	delete[] buffer2;

	return image;
}


void CFonction::copy()
{
	if (SELEC->isSelected())
	{
		sf::IntRect cadre = SELEC->getCadre();

		cadre.left -= CALQUE->getPosition().x;
		cadre.top -= CALQUE->getPosition().y;
		if (checkCadre(&cadre, sf::IntRect(0, 0, CALQUE->getTexture()->getSize().x, CALQUE->getTexture()->getSize().y)))
			return;

		CCopy::pos_copy = sf::Vector2f(cadre.left, cadre.top) + CALQUE->getPosition();

		sf::Texture texture;
		texture.loadFromImage(CALQUE->getTexture()->copyToImage(), cadre);

		sf::RenderTexture renderTexture; renderTexture.create(cadre.width, cadre.height);
		renderTexture.clear(sf::Color::Transparent);
		renderTexture.draw(sf::Sprite(texture), sf::BlendNone);
		renderTexture.display();

		sf::Texture tex = renderTexture.getTexture();
		RES->getShader(RES->cut)->setParameter("offset", SELEC->getPosition() - CALQUE->getPosition());
		RES->getShader(RES->cut)->setParameter("offset_image", sf::Vector2f(cadre.left, cadre.top));
		RES->getShader(RES->cut)->setParameter("background", tex);

		sf::Sprite spr(texture);
		renderTexture.draw(spr, *RES->getRender(RES->cut));
		renderTexture.display();

		copy_to_clipboard(&renderTexture.getTexture().copyToImage());
	}
}

void CFonction::paste()
{
	if (COPY != NULL)
		COPY->apply();
	else
		if (SELEC->isSelected())
		{
			RETOUR->avoid_next();
			SELEC->delete_selec();
		}

	sf::Image* image = get_clipboard();
	if (image == NULL)
		return;

	CCopy::new_copy(image);

	delete image;
}

void CFonction::increment(int* var, int incr, sf::Vector2i intervalle)
{
	*var += incr;
	if (*var < intervalle.x) { *var = intervalle.x; }
	else if (*var > intervalle.y) { *var = intervalle.y; }
}

void CFonction::increment(sf::Uint8* var, int incr)
{
	if (*var + incr > 255) { *var = 255; }
	else if (*var + incr < 0) { *var = 0; }
	else { *var += incr; }
}

bool CFonction::checkCadre(sf::IntRect* cadre, sf::IntRect cadre_in)
{
	if (cadre->left < cadre_in.left)
	{
		cadre->width += cadre->left;
		if (cadre->width <= 0)
			return true;
		cadre->left = cadre_in.left;
	}
	if (cadre->top < cadre_in.top)
	{
		cadre->height += cadre->top;
		if (cadre->height <= 0)
			return true;
		cadre->top = cadre_in.top;
	}
	if (cadre->left + cadre->width >= cadre_in.left + cadre_in.width)
	{
		cadre->width = cadre_in.left + cadre_in.width - cadre->left;
		if (cadre->width <= 0)
			return true;
	}
	if (cadre->top + cadre->height >= cadre_in.top + cadre_in.height)
	{
		cadre->height = cadre_in.top + cadre_in.height - cadre->top;
		if (cadre->height <= 0)
			return true;
	}
	return false;
}

void CFonction::line(sf::Vector2f pos_ini, sf::Vector2f pos_fin, CCalque* calque)
{
	float x1, x2, y1, y2;

	x1 = pos_ini.x; x2 = pos_fin.x;
	y1 = pos_ini.y; y2 = pos_fin.y;

	int delta_x = x2 - x1;
	signed char const ix = (delta_x > 0) - (delta_x < 0);
	delta_x = std::abs(delta_x) << 1;
	int delta_y = y2 - y1;
	signed char const iy = (delta_y > 0) - (delta_y < 0);
	delta_y = std::abs(delta_y) << 1;

	pos_fin = sf::Vector2f(x1, y1); calque->draw_brosse(pos_fin);
	if (delta_x >= delta_y)
	{
		int error(delta_y - (delta_x >> 1));
		while (x1 != x2)
		{
			if ((error >= 0) && (error || (ix > 0)))
				{error -= delta_x; y1 += iy;}
			error += delta_y; x1 += ix;
			pos_fin = sf::Vector2f(x1, y1); calque->draw_brosse(pos_fin);
		}
	}
	else
	{
		int error(delta_x - (delta_y >> 1));
		while (y1 != y2)
		{
			if ((error >= 0) && (error || (iy > 0)))
				{error -= delta_y; x1 += ix;}
			error += delta_x; y1 += iy;
			pos_fin = sf::Vector2f(x1, y1); calque->draw_brosse(pos_fin);
		}
	}
	IO->setExClick(pos_fin);
}

void CFonction::maj(sf::Vector2f* pos, sf::Vertex* line)
{
	sf::Vector2f cl = IO->getPreviousCenterClick();
	line[0].position = cl;
	if (IO->pressed(CInput::Ctrl))
	{
		float d_x = pos->x - cl.x;
		float d_y = pos->y - cl.y;

		float cos = d_x / CFonction::hypothenus(d_x, d_y);
		float sin = -d_y / CFonction::hypothenus(d_x, d_y);

		float hyp = floor(CFonction::hypothenus(d_x, d_y) / std::sqrt(2.f));

		if (cos >= std::cos(VAR->PIH))
			pos->y = cl.y;
		else if (cos <= std::cos(7 * VAR->PIH))
			pos->y = cl.y;
		else if (sin >= std::sin(3 * VAR->PIH))
			pos->x = cl.x;
		else if (sin <= std::sin(-3 * VAR->PIH))
			pos->x = cl.x;
		else if (cos >= 0)
		{
			if (sin >= 0)
				*pos = sf::Vector2f(cl.x + hyp, cl.y - hyp);
			else
				*pos = sf::Vector2f(cl.x + hyp, cl.y + hyp);
		}
		else
		{
			if (sin >= 0)
				*pos = sf::Vector2f(cl.x - hyp, cl.y - hyp);
			else
				*pos = sf::Vector2f(cl.x - hyp, cl.y + hyp);
		}
	}
	line[1].position = *pos;
}