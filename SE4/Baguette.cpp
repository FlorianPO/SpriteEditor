#include "Baguette.h"
#include "Input.h"
#include "Selec.h"
#include "Calque.h"
#include "Fonction.h"
#include "Var.h"
#include "App.h"

CBaguette::CBaguette(void)
{
	numero_outil = COutil::BAGUETTE;
}

CBaguette::~CBaguette(void)
{
}

void CBaguette::ctrl(sf::Color* color)
{
	*color = CFonction::getColor(IO->getPixel() - CALQUE->getPosition_i(), CALQUE->getImage());
}

bool CBaguette::pixelCheck(sf::Color color)
{
	return std::abs(target_color.a - color.a) <= VAR->seuil 
		&& std::abs(target_color.r - color.r) <=VAR->seuil 
		&& std::abs(target_color.g - color.g) <=VAR->seuil 
		&& std::abs(target_color.b - color.b) <=VAR->seuil;
}

void CBaguette::algorithmNoSelec()
{
	if (!CFonction::onCalque(IO->getPixel() - CALQUE->getPosition_i(), CALQUE->getTexture()))
		return;

	image = CALQUE->getImage();
	SELEC->initTest();

	bit_image.create(image->getSize().x, image->getSize().y, SELEC->ident_color);

	sf::VertexArray line(sf::LinesStrip, 2);
	
	linearFillNoSelec(IO->getPixel().x - CALQUE->getPosition_i().x, IO->getPixel().y - CALQUE->getPosition_i().y);
	while (!ranges.empty())
    {
		COutil::range_type range = ranges.front(); ranges.pop();

        for (int i = range.debutX; i <= range.finX; i++)
        {
			if (range.Y > 0)
			{
				if (bit_image.getPixel(i, range.Y-1).a != 0)
				{
					if (pixelCheck(image->getPixel(i, range.Y-1)))
					{linearFillNoSelec(i, range.Y-1);}
					else
					{
						line[0].position = sf::Vector2f(i, range.Y);
						line[1].position = sf::Vector2f(i+1, range.Y);
						conf_lines.push_back(COutil::creer_conf_line(line, 0, i, range.Y));
			}	}	}
			else
			{
				line[0].position = sf::Vector2f(i, range.Y);
				line[1].position = sf::Vector2f(i+1, range.Y);
				conf_lines.push_back(COutil::creer_conf_line(line, 0, i, range.Y));
			}
			
			if (range.Y < image->getSize().y-1)
			{
				if (bit_image.getPixel(i, range.Y+1).a != 0)
				{
					if (pixelCheck(image->getPixel(i, range.Y+1)))
					{linearFillNoSelec(i, range.Y+1);}
					else
					{
						line[0].position = sf::Vector2f(i, range.Y+1);
						line[1].position = sf::Vector2f(i+1, range.Y+1);
						conf_lines.push_back(COutil::creer_conf_line(line, 2, i, range.Y));
			}	}	}
			else
			{
				line[0].position = sf::Vector2f(i, range.Y+1);
				line[1].position = sf::Vector2f(i+1, range.Y+1);
				conf_lines.push_back(COutil::creer_conf_line(line, 2, i, range.Y));
			}
	}	}
}

void CBaguette::linearFillNoSelec(int x, int y)
{
	sf::VertexArray line(sf::LinesStrip, 2);

    int i_left = x;
	do
    {
		bit_image.setPixel(i_left, y, SELEC->blend_color);
		i_left--;

    } while (i_left >= 0 && bit_image.getPixel(i_left, y).a != 0 && pixelCheck(image->getPixel(i_left, y)));
	i_left++;

	line[0].position = sf::Vector2f(i_left, y);
	line[1].position = sf::Vector2f(i_left, y+1);
	conf_lines.push_back(COutil::creer_conf_line(line, 3, i_left, y));

    int i_right = x;
	do
    {
		bit_image.setPixel(i_right, y, SELEC->blend_color);
		i_right++;

	} while (i_right <= bit_image.getSize().x-1 && bit_image.getPixel(i_right, y).a != 0 && pixelCheck(image->getPixel(i_right, y)));
	i_right--;

	line[0].position = sf::Vector2f(i_right+1, y);
	line[1].position = sf::Vector2f(i_right+1, y+1);
	conf_lines.push_back(COutil::creer_conf_line(line, 1, i_right, y));

	COutil::range_type range = {i_left, i_right, y};
	ranges.push(range);
}

/////////////////////////////////

void CBaguette::algorithmWithSelec()
{
	SELEC->initTest();
	if (!CFonction::onCalque(IO->getPixel() - CALQUE->getPosition_i(), CALQUE->getTexture()) || !SELEC->onSelec(IO->getPixel().x, IO->getPixel().y))
	{return;}

	bit_image.create(image->getSize().x, image->getSize().y, SELEC->ident_color);

	sf::VertexArray line(sf::LinesStrip, 2);
	
	linearFillWithSelec(IO->getPixel().x - CALQUE->getPosition_i().x, IO->getPixel().y - CALQUE->getPosition_i().y);
	while (!ranges.empty())
    {
		COutil::range_type range = ranges.front(); ranges.pop();

        for (int i = range.debutX; i <= range.finX; i++)
        {
			if (range.Y > 0)
			{
				if (bit_image.getPixel(i, range.Y-1).a != 0)
				{
					if (SELEC->onSelec(i + CALQUE->getPosition_i().x, range.Y - 1 + CALQUE->getPosition_i().y) && pixelCheck(image->getPixel(i, range.Y - 1)))
					{linearFillWithSelec(i, range.Y-1);}
					else
					{
						line[0].position = sf::Vector2f(i, range.Y);
						line[1].position = sf::Vector2f(i+1, range.Y);
						conf_lines.push_back(COutil::creer_conf_line(line, 0, i, range.Y));
			}	}	}
			else
			{
				line[0].position = sf::Vector2f(i, range.Y);
				line[1].position = sf::Vector2f(i+1, range.Y);
				conf_lines.push_back(COutil::creer_conf_line(line, 0, i, range.Y));
			}
			
			if (range.Y < image->getSize().y-1)
			{
				if (bit_image.getPixel(i, range.Y+1).a != 0)
				{
					if (SELEC->onSelec(i + CALQUE->getPosition_i().x, range.Y + 1 + CALQUE->getPosition_i().y) && pixelCheck(image->getPixel(i, range.Y + 1)))
					{linearFillWithSelec(i, range.Y+1);}
					else
					{
						line[0].position = sf::Vector2f(i, range.Y+1);
						line[1].position = sf::Vector2f(i+1, range.Y+1);
						conf_lines.push_back(COutil::creer_conf_line(line, 2, i, range.Y));
			}	}	}
			else
			{
				line[0].position = sf::Vector2f(i, range.Y+1);
				line[1].position = sf::Vector2f(i+1, range.Y+1);
				conf_lines.push_back(COutil::creer_conf_line(line, 2, i, range.Y));
			}
	}	}
}

void CBaguette::linearFillWithSelec(int x, int y)
{
	sf::VertexArray line(sf::LinesStrip, 2);

    int i_left = x;
	do
    {
		bit_image.setPixel(i_left, y, SELEC->blend_color);
		i_left--;

	} while (i_left >= 0 && bit_image.getPixel(i_left, y).a != 0 && SELEC->onSelec(i_left + CALQUE->getPosition_i().x, y + CALQUE->getPosition_i().y) && pixelCheck(image->getPixel(i_left, y)));
	i_left++;

	line[0].position = sf::Vector2f(i_left, y);
	line[1].position = sf::Vector2f(i_left, y+1);
	conf_lines.push_back(COutil::creer_conf_line(line, 3, i_left, y));

    int i_right = x;
	do
    {
		bit_image.setPixel(i_right, y, SELEC->blend_color);
		i_right++;

	} while (i_right <= bit_image.getSize().x - 1 && bit_image.getPixel(i_right, y).a != 0 && SELEC->onSelec(i_right + CALQUE->getPosition_i().x, y + CALQUE->getPosition_i().y) && pixelCheck(image->getPixel(i_right, y)));
	i_right--;

	line[0].position = sf::Vector2f(i_right+1, y);
	line[1].position = sf::Vector2f(i_right+1, y+1);
	conf_lines.push_back(COutil::creer_conf_line(line, 1, i_right, y));

	COutil::range_type range = {i_left, i_right, y};
	ranges.push(range);
}

void CBaguette::end_selec(int type)
{
	if (conf_lines.size() > 0)
	{
		COutil::move_line(&conf_lines, CALQUE->getPosition_i());

		int x_min = conf_lines[0].x, y_min = conf_lines[0].y, x_max = conf_lines[0].x, y_max = conf_lines[0].y;
		for (int i=0; i<conf_lines.size(); i++)
		{
			if (conf_lines[i].x < x_min) x_min = conf_lines[i].x;
			else if (conf_lines[i].x > x_max) x_max = conf_lines[i].x;
			if (conf_lines[i].y < y_min) y_min = conf_lines[i].y;
			else if (conf_lines[i].y > y_max) y_max = conf_lines[i].y;
		}
		SELEC->new_selec(sf::IntRect(x_min, y_min, x_max - x_min + 1, y_max - y_min + 1), &bit_image, &conf_lines, type);
		conf_lines.clear();
	}
}

void CBaguette::use()
{
	if (IO->again(CInput::MLeft))
	{
		ctrl(&target_color);
		conf_lines.clear();
		if (IO->pressed(CInput::Ctrl) && IO->pressed(CInput::Maj))
		{
			algorithmWithSelec();
			end_selec(3);
		}
		else if (IO->pressed(CInput::Ctrl))
		{
			algorithmWithSelec();
			end_selec(2);
		}
		else if (IO->pressed(CInput::Maj))
		{
			algorithmNoSelec();
			end_selec(1);
		}
		else
		{
			algorithmNoSelec();
			end_selec(0);
	}	}	
}