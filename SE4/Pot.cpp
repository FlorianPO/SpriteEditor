#include "Pot.h"
#include "Calque.h"
#include "Var.h"
#include "Input.h"
#include "Fonction.h"
#include "Selec.h"
#include "App.h"

CPot::CPot(void)
{
	numero_outil = COutil::POT;
}

CPot::~CPot(void) {}

void CPot::ctrl(sf::Color* color)
{
	*color = CFonction::getColor(IO->getPixel() - CALQUE->getPosition_i(), CALQUE->getImage());
}

bool CPot::pixelCheck(sf::Color color)
{
	return std::abs(target_color.a - color.a) <= VAR->seuil
		&& std::abs(target_color.r - color.r) <= VAR->seuil
		&& std::abs(target_color.g - color.g) <= VAR->seuil
		&& std::abs(target_color.b - color.b) <= VAR->seuil;
}

void CPot::full_dessiner(sf::Color color)
{
	RES->getShader(CRes::pot)->setParameter("offset", SELEC->getPosition() - CALQUE->getPosition());
	RES->getShader(CRes::pot)->setParameter("background", *CALQUE->getTexture());
	RES->getShader(CRes::pot)->setParameter("couleur", color);

	sf::Texture texture = *CALQUE->getTexture();
	CALQUE->draw(&sf::Sprite(texture), RES->getRender(CRes::pot));
}

void CPot::dessiner()
{
	test_image = CALQUE->getImage();
	SELEC->initTest();

	if (!CFonction::onCalque(IO->getPixel() - CALQUE->getPosition_i(), CALQUE->getTexture()) || !SELEC->onSelec(IO->getPixel().x, IO->getPixel().y))
		return;

	image.create(test_image->getSize().x, test_image->getSize().y, sf::Color::Transparent);
	bit_image.create(test_image->getSize().x, test_image->getSize().y, sf::Color::Black);

	linearFill(IO->getPixel().x - CALQUE->getPosition_i().x, IO->getPixel().y - CALQUE->getPosition_i().y);
	while (!ranges.empty())
	{
		COutil::range_type range = ranges.front(); ranges.pop();

		for (int i = range.debutX; i <= range.finX; i++)
		{
			if (range.Y > 0 && bit_image.getPixel(i, range.Y - 1).r == 0 && SELEC->onSelec(i + CALQUE->getPosition_i().x, range.Y - 1 + CALQUE->getPosition_i().y) && pixelCheck(test_image->getPixel(i, range.Y - 1)))
				linearFill(i, range.Y - 1);

			if (range.Y < image.getSize().y - 1 && bit_image.getPixel(i, range.Y + 1).r == 0 && SELEC->onSelec(i + CALQUE->getPosition_i().x, range.Y + 1 + CALQUE->getPosition_i().y) && pixelCheck(test_image->getPixel(i, range.Y + 1)))
				linearFill(i, range.Y + 1);
		}
	}
	sf::Texture texture;
	texture.loadFromImage(image);

	CALQUE->draw(&sf::Sprite(texture), NULL);
}

void CPot::linearFill(int x, int y)
{
	int i_left = x;
	do
	{
		image.setPixel(i_left, y, fill_color);
		bit_image.setPixel(i_left, y, sf::Color::White);
		i_left--;

	} while (i_left >= 0 && bit_image.getPixel(i_left, y).r == 0 && SELEC->onSelec(i_left + CALQUE->getPosition_i().x, y + CALQUE->getPosition_i().y) && pixelCheck(test_image->getPixel(i_left, y)));
	i_left++;

	int i_right = x;
	do
	{
		image.setPixel(i_right, y, fill_color);
		bit_image.setPixel(i_right, y, sf::Color::White);
		i_right++;

	} while (i_right <= bit_image.getSize().x - 1 && bit_image.getPixel(i_right, y).r == 0 && SELEC->onSelec(i_right + CALQUE->getPosition_i().x, y + CALQUE->getPosition_i().y) && pixelCheck(test_image->getPixel(i_right, y)));
	i_right--;

	COutil::range_type range = { i_left, i_right, y };
	ranges.push(range);
}

void CPot::use()
{
	if (IO->again(CInput::MLeft))
	{
		if (IO->pressed(CInput::Ctrl))
			ctrl(&VAR->color1);
		else if (IO->pressed(CInput::Maj))
			full_dessiner(VAR->color1);
		else
		{
			fill_color = VAR->color1;
			fill_color.a *= VAR->opacity / 255.f;
			ctrl(&target_color);
			dessiner();
		}
	}
	else if (IO->again(CInput::MRight))
	{
		if (IO->pressed(CInput::Ctrl))
			ctrl(&VAR->color2);
		else if (IO->pressed(CInput::Maj))
			full_dessiner(VAR->color2);
		else
		{
			fill_color = VAR->color2;
			fill_color.a *= VAR->opacity / 255.f;
			ctrl(&target_color);
			dessiner();
		}
	}
}
