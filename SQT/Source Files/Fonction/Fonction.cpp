#include "Source Files/Fonction/Fonction.h"

#include "Source Files/Application/IO/Input.h"
#include "Source Files/Application/Var/Var.h"
#include "Source Files/Application/App.h"
#include "Source Files/Application/Selec/Selec.h"
#include "Source Files/Application/Layer/LayerController.h"
#include "Source Files/Retour/Retour.h"
#include "Source Files/Application/Res/Res.h"
#include "Source Files/Application/Copy/Copy.h"
#include "Source Files/Application/Brush/BrushController.h"

sf::Vector2f CFonction::rotationGlobal(sf::Vector2f toRot, sf::Vector2f center, double angle)
{
	double x = toRot.x;
	double y = toRot.y;
	double x_temp = x;

	x -= center.x;
	y -= center.y;
	x = x*std::cos(angle) - y*std::sin(angle);
	y = y*std::cos(angle) + x_temp*std::sin(angle);
	x += center.x;
	y += center.y;

	return sf::Vector2f(x, y);
}

sf::Vector2f CFonction::rotationLocal(sf::Vector2f toRot, double angle)
{
	double x = toRot.x;
	double y = toRot.y;
	double x_temp = x;

	x = x*std::cos(angle) - y*std::sin(angle);
	y = y*std::cos(angle) + x_temp*std::sin(angle);

	return sf::Vector2f(x, y);;
}

bool CFonction::onSprite(const sf::Sprite* sprite)
{
	sf::FloatRect rect = sprite->getGlobalBounds();
	return rect.contains(IO->getPosition());
}

bool CFonction::onSprite(const sf::Sprite& sprite, const sf::RenderWindow& fenetre) {
	sf::FloatRect rect = sprite.getGlobalBounds();
	sf::Vector2i pos = sf::Mouse::getPosition(fenetre);
	return rect.contains(pos.x, pos.y);
}

bool CFonction::onRect(sf::FloatRect rect) {
	return rect.contains(IO->getPosition());
}

bool CFonction::onRect(sf::FloatRect rect, const sf::RenderWindow& fenetre) {
	sf::Vector2i pos = sf::Mouse::getPosition(fenetre);
	return rect.contains(pos.x, pos.y);
}

int CFonction::change_number()
{
	int incr = (IO->log(Qt::LeftButton) || IO->scroll_up()) - (IO->log(Qt::RightButton) || IO->scroll_down());

	if (IO->pressed(Qt::Key_Control) && IO->pressed(Qt::Key_Shift))
	{
		if (IO->log(Qt::LeftButton) || IO->scroll_up()) incr = 255;
		if (IO->log(Qt::RightButton) || IO->scroll_down()) incr = -255;
	}
	else if (IO->pressed(Qt::Key_Control))
	{
		if (IO->log(Qt::LeftButton) || IO->scroll_up()) incr = 5;
		if (IO->log(Qt::RightButton) || IO->scroll_down()) incr = -5;
	}
	else if (IO->pressed(Qt::Key_Shift))
	{
		if (IO->log(Qt::LeftButton) || IO->scroll_up()) incr = 50;
		if (IO->log(Qt::RightButton) || IO->scroll_down()) incr = -50;
	}
	return incr;
}

CFonction::sl_PR CFonction::selecPointRect(sf::Vector2f pos_ini, sf::Vector2f pos, int only, double angle, float seuil)
{
	if (pos == pos_ini)
		return {sf::Vector2f(), -1};
	float a = CFonction::norme(pos_ini-pos);

	if (only == -1)
	{
		sf::Vector2f points[8];
		points[0] = sf::Vector2f(pos_ini.x - a/std::sqrt(2), pos_ini.y - a/std::sqrt(2));
		points[1] = sf::Vector2f(pos_ini.x, pos_ini.y - a);
		points[2] = sf::Vector2f(pos_ini.x + a/std::sqrt(2), pos_ini.y - a/std::sqrt(2));
		points[3] = sf::Vector2f(pos_ini.x + a, pos_ini.y);
		points[4] = sf::Vector2f(pos_ini.x + a/std::sqrt(2), pos_ini.y + a/std::sqrt(2));
		points[5] = sf::Vector2f(pos_ini.x, pos_ini.y + a);
		points[6] = sf::Vector2f(pos_ini.x - a/std::sqrt(2), pos_ini.y + a/std::sqrt(2));
		points[7] = sf::Vector2f(pos_ini.x - a, pos_ini.y);

		if (angle != 0)
			for (int i=0; i < 8; i++)
				points[i] = rotationGlobal(points[i], pos_ini, angle);

		float distance[8];

		for (int i = 0; i < 8; i++)
			distance[i] = std::sqrt(std::pow(points[i].x - pos.x, 2) + std::pow(points[i].y - pos.y, 2));

		int j = 0;
		for (int i = 0; i < 8; i++)
			if (distance[i] < distance[j])
				j = i;
		if (CFonction::norme(points[j] - pos_ini) < seuil)
			return {sf::Vector2f(), -1};
		return {points[j] - pos_ini, j};
	}
	switch (only)
	{
		case 0:	return {rotationGlobal(sf::Vector2f(pos_ini.x - a/std::sqrt(2), pos_ini.y - a/std::sqrt(2)), pos_ini, angle) - pos_ini, 0};
		case 1:	return {rotationGlobal(sf::Vector2f(pos_ini.x, pos_ini.y - a), pos_ini, angle) - pos_ini, 1};
		case 2:	return {rotationGlobal(sf::Vector2f(pos_ini.x + a/std::sqrt(2), pos_ini.y - a/std::sqrt(2)), pos_ini, angle) - pos_ini, 2};
		case 3:	return {rotationGlobal(sf::Vector2f(pos_ini.x + a, pos_ini.y), pos_ini, angle) - pos_ini, 3};
		case 4:	return {rotationGlobal(sf::Vector2f(pos_ini.x + a/std::sqrt(2), pos_ini.y + a/std::sqrt(2)), pos_ini, angle) - pos_ini, 4};
		case 5:	return {rotationGlobal(sf::Vector2f(pos_ini.x, pos_ini.y + a), pos_ini, angle) - pos_ini, 5};
		case 6:	return {rotationGlobal(sf::Vector2f(pos_ini.x - a/std::sqrt(2), pos_ini.y + a/std::sqrt(2)), pos_ini, angle) - pos_ini, 6};
		case 7:	return {rotationGlobal(sf::Vector2f(pos_ini.x - a, pos_ini.y), pos_ini, angle) - pos_ini, 7};
	}
	return {sf::Vector2f(), -1};
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
	vector.x = APP->getPositionCamera(1).x + vect.x / APP->zoom;
	vector.y = APP->getPositionCamera(1).y + vect.y / APP->zoom;

	return vector;
}

sf::Vector2i CFonction::screened(sf::Vector2f vect)
{
	sf::Vector2i vector;
	vect -= APP->getPositionCamera(1);
	vector.x = vect.x * APP->zoom;
	vector.y = vect.y * APP->zoom;

	return vector;
}

bool CFonction::onCalque(sf::Vector2i vect, const sf::Image& image_courant) {
	return vect.x >= 0 && vect.x < image_courant.getSize().x && vect.y >= 0 && vect.y < image_courant.getSize().y;
}

bool CFonction::onCalque(sf::Vector2i vect, const sf::Texture& texture_courant) {
	return vect.x >= 0 && vect.x < texture_courant.getSize().x && vect.y >= 0 && vect.y < texture_courant.getSize().y;
}

sf::Color CFonction::getColor(sf::Vector2i vect, const sf::Image& image_courant) {
	if (onCalque(vect, image_courant))
		return image_courant.getPixel(vect.x, vect.y);

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

sf::Vector2f CFonction::centerCorner(const sf::Sprite& sprite) {
	sf::FloatRect rect = sprite.getGlobalBounds();
	return sf::Vector2f(rect.left + rect.width / 2.f, rect.top + rect.height / 2.f);
}

sf::Vector2f CFonction::centerCorner(const sf::Texture& texture) {
	return sf::Vector2f(texture.getSize().x / 2.f, texture.getSize().y / 2.f);
}

sf::Vector2f CFonction::centerCorner(const sf::Image& image) {
	return sf::Vector2f(image.getSize().x / 2.f, image.getSize().y / 2.f);
}

sf::Vector2f CFonction::centerCorner(sf::Vector2i size) {
	return sf::Vector2f(size.x / 2.f, size.y / 2.f);
}

sf::Vector2f CFonction::centerCorner(sf::Vector2u size) {
	return sf::Vector2f(size.x / 2.f, size.y / 2.f);
}

sf::Vector2f CFonction::centerCorner(sf::Vector2f size) {
	return sf::Vector2f(size.x / 2.f, size.y / 2.f); 
}

sf::Vector2f CFonction::centerCorner(sf::FloatRect rect) {
	return sf::Vector2f(rect.left + rect.width / 2.f, rect.top + rect.height / 2.f);
}

sf::Vector2f CFonction::centerCorner(sf::IntRect rect) {
	return sf::Vector2f(rect.left + rect.width / 2.f, rect.top + rect.height / 2.f);
}

sf::Vector2f CFonction::topLeftCorner(const sf::Sprite& sprite) {
	sf::FloatRect rect = sprite.getGlobalBounds();
	return sf::Vector2f(rect.left, rect.top);
}

sf::Vector2f CFonction::topRightCorner(const sf::Sprite& sprite) {
	sf::FloatRect rect = sprite.getGlobalBounds();
	return sf::Vector2f(rect.left + rect.width, rect.top);
}

sf::Vector2f CFonction::bottomRightCorner(const sf::Sprite& sprite) {
	sf::FloatRect rect = sprite.getGlobalBounds();
	return sf::Vector2f(rect.left + rect.width, rect.top + rect.height);
}

sf::Vector2f CFonction::bottomLeftCorner(const sf::Sprite& sprite) {
	sf::FloatRect rect = sprite.getGlobalBounds();
	return sf::Vector2f(rect.left, rect.top + rect.height);
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

		cadre.left -= LAYER->getPosition().x;
		cadre.top -= LAYER->getPosition().y;
		if (checkCadre(&cadre, sf::IntRect(0, 0, LAYER->getTexture().getSize().x, LAYER->getTexture().getSize().y)))
			return;

		//CCopy::pos_copy = sf::Vector2f(cadre.left, cadre.top) + LAYER->getPosition();

		sf::Texture texture;
		texture.loadFromImage(LAYER->getTexture().copyToImage(), cadre);

		sf::RenderTexture renderTexture; renderTexture.create(cadre.width, cadre.height);
		renderTexture.clear(sf::Color::Transparent);
		renderTexture.draw(sf::Sprite(texture), sf::BlendNone);
		renderTexture.display();

		sf::Texture tex = renderTexture.getTexture();
		RES->getShader(RES->cut)->setParameter("offset", SELEC->getPosition() - LAYER->getPosition());
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
			//RETOUR->avoid_next();
			SELEC->deleteSelection();
		}

	sf::Image* image = get_clipboard();
	if (image == NULL)
		return;

	COPY_CONTROLLER->new_copy(*image);

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