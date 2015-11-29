#include "Writter.h"
#include "Res.h"

CWritter* WRITTER;

CWritter::CWritter()
{
	sf::Sprite sprite(*RES->getTexture(CRes::TEXTURE::panneau));

	int ini_dn = 121;
	int dy = 301;

	int dn = ini_dn;
	sprite.setTextureRect(sf::IntRect(dn, dy, 10, 14)); sprite_list.push_back(sprite); //0
	sprite.setTextureRect(sf::IntRect(dn += 10, dy, 6, 14)); sprite_list.push_back(sprite); //1
	sprite.setTextureRect(sf::IntRect(dn += 6, dy, 10, 14)); sprite_list.push_back(sprite); //2
	sprite.setTextureRect(sf::IntRect(dn += 10, dy, 10, 14)); sprite_list.push_back(sprite); //3
	sprite.setTextureRect(sf::IntRect(dn += 10, dy, 10, 14)); sprite_list.push_back(sprite); //4
	sprite.setTextureRect(sf::IntRect(dn += 10, dy, 10, 14)); sprite_list.push_back(sprite); //5
	sprite.setTextureRect(sf::IntRect(dn += 10, dy, 10, 14)); sprite_list.push_back(sprite); //6
	sprite.setTextureRect(sf::IntRect(dn += 10, dy, 10, 14)); sprite_list.push_back(sprite); //7
	sprite.setTextureRect(sf::IntRect(dn += 10, dy, 10, 14)); sprite_list.push_back(sprite); //8
	sprite.setTextureRect(sf::IntRect(dn += 10, dy, 10, 14)); sprite_list.push_back(sprite); //9
	sprite.setTextureRect(sf::IntRect(dn += 10, dy, 7, 14)); sprite_list.push_back(sprite); //-

	dn = ini_dn;
	dy += 15;
	sprite.setTextureRect(sf::IntRect(dn, dy, 7, 14)); sprite_list.push_back(sprite); // 
	sprite.setTextureRect(sf::IntRect(dn += 7, dy, 10, 14)); sprite_list.push_back(sprite); //A
	sprite.setTextureRect(sf::IntRect(dn += 10, dy, 10, 14)); sprite_list.push_back(sprite); //B
	sprite.setTextureRect(sf::IntRect(dn += 10, dy, 8, 14)); sprite_list.push_back(sprite); //C
	sprite.setTextureRect(sf::IntRect(dn += 8, dy, 10, 14)); sprite_list.push_back(sprite); //D
	sprite.setTextureRect(sf::IntRect(dn += 10, dy, 8, 14)); sprite_list.push_back(sprite); //E
	sprite.setTextureRect(sf::IntRect(dn += 8, dy, 8, 14)); sprite_list.push_back(sprite); //F
	sprite.setTextureRect(sf::IntRect(dn += 8, dy, 10, 14)); sprite_list.push_back(sprite); //G
	sprite.setTextureRect(sf::IntRect(dn += 10, dy, 10, 14)); sprite_list.push_back(sprite); //H
	sprite.setTextureRect(sf::IntRect(dn += 10, dy, 8, 14)); sprite_list.push_back(sprite); //I
	sprite.setTextureRect(sf::IntRect(dn += 8, dy, 10, 14)); sprite_list.push_back(sprite); //J
	sprite.setTextureRect(sf::IntRect(dn += 10, dy, 10, 14)); sprite_list.push_back(sprite); //K
	sprite.setTextureRect(sf::IntRect(dn += 10, dy, 8, 14)); sprite_list.push_back(sprite); //L
	sprite.setTextureRect(sf::IntRect(dn += 8, dy, 12, 14)); sprite_list.push_back(sprite); //M
	sprite.setTextureRect(sf::IntRect(dn += 12, dy, 10, 14)); sprite_list.push_back(sprite); //N
	sprite.setTextureRect(sf::IntRect(dn += 10, dy, 10, 14)); sprite_list.push_back(sprite); //O
	sprite.setTextureRect(sf::IntRect(dn += 10, dy, 10, 14)); sprite_list.push_back(sprite); //P
	sprite.setTextureRect(sf::IntRect(dn += 10, dy, 10, 14)); sprite_list.push_back(sprite); //Q
	sprite.setTextureRect(sf::IntRect(dn += 10, dy, 10, 14)); sprite_list.push_back(sprite); //R
	sprite.setTextureRect(sf::IntRect(dn += 10, dy, 10, 14)); sprite_list.push_back(sprite); //S
	sprite.setTextureRect(sf::IntRect(dn += 10, dy, 8, 14)); sprite_list.push_back(sprite); //T
	sprite.setTextureRect(sf::IntRect(dn += 8, dy, 10, 14)); sprite_list.push_back(sprite); //U
	sprite.setTextureRect(sf::IntRect(dn += 10, dy, 10, 14)); sprite_list.push_back(sprite); //V
	sprite.setTextureRect(sf::IntRect(dn += 10, dy, 12, 14)); sprite_list.push_back(sprite); //W
	sprite.setTextureRect(sf::IntRect(dn += 12, dy, 10, 14)); sprite_list.push_back(sprite); //X
	sprite.setTextureRect(sf::IntRect(dn += 10, dy, 10, 14)); sprite_list.push_back(sprite); //Y
	sprite.setTextureRect(sf::IntRect(dn += 10, dy, 8, 14)); sprite_list.push_back(sprite); //Z

	dn = ini_dn;
	dy += 15;
	sprite.setTextureRect(sf::IntRect(dn, dy, 10, 16)); sprite_list.push_back(sprite); //a
	sprite.setTextureRect(sf::IntRect(dn += 10, dy, 10, 16)); sprite_list.push_back(sprite); //b
	sprite.setTextureRect(sf::IntRect(dn += 10, dy, 8, 16)); sprite_list.push_back(sprite); //c
	sprite.setTextureRect(sf::IntRect(dn += 8, dy, 10, 16)); sprite_list.push_back(sprite); //d
	sprite.setTextureRect(sf::IntRect(dn += 10, dy, 10, 16)); sprite_list.push_back(sprite); //e
	sprite.setTextureRect(sf::IntRect(dn += 10, dy, 8, 16)); sprite_list.push_back(sprite); //f
	sprite.setTextureRect(sf::IntRect(dn += 8, dy, 10, 16)); sprite_list.push_back(sprite); //g
	sprite.setTextureRect(sf::IntRect(dn += 10, dy, 10, 16)); sprite_list.push_back(sprite); //h
	sprite.setTextureRect(sf::IntRect(dn += 10, dy, 4, 16)); sprite_list.push_back(sprite); //i
	sprite.setTextureRect(sf::IntRect(dn += 4, dy, 6, 16)); sprite_list.push_back(sprite); //j
	sprite.setTextureRect(sf::IntRect(dn += 6, dy, 10, 16)); sprite_list.push_back(sprite); //k
	sprite.setTextureRect(sf::IntRect(dn += 10, dy, 4, 16)); sprite_list.push_back(sprite); //l
	sprite.setTextureRect(sf::IntRect(dn += 4, dy, 12, 16)); sprite_list.push_back(sprite); //m
	sprite.setTextureRect(sf::IntRect(dn += 12, dy, 10, 16)); sprite_list.push_back(sprite); //n
	sprite.setTextureRect(sf::IntRect(dn += 10, dy, 10, 16)); sprite_list.push_back(sprite); //o
	sprite.setTextureRect(sf::IntRect(dn += 10, dy, 10, 16)); sprite_list.push_back(sprite); //p
	sprite.setTextureRect(sf::IntRect(dn += 10, dy, 10, 16)); sprite_list.push_back(sprite); //q
	sprite.setTextureRect(sf::IntRect(dn += 10, dy, 8, 16)); sprite_list.push_back(sprite); //r
	sprite.setTextureRect(sf::IntRect(dn += 8, dy, 10, 16)); sprite_list.push_back(sprite); //s
	sprite.setTextureRect(sf::IntRect(dn += 10, dy, 8, 16)); sprite_list.push_back(sprite); //t
	sprite.setTextureRect(sf::IntRect(dn += 8, dy, 10, 16)); sprite_list.push_back(sprite); //u
	sprite.setTextureRect(sf::IntRect(dn += 10, dy, 10, 16)); sprite_list.push_back(sprite); //v
	sprite.setTextureRect(sf::IntRect(dn += 10, dy, 12, 16)); sprite_list.push_back(sprite); //w
	sprite.setTextureRect(sf::IntRect(dn += 12, dy, 8, 16)); sprite_list.push_back(sprite); //x
	sprite.setTextureRect(sf::IntRect(dn += 8, dy, 10, 16)); sprite_list.push_back(sprite); //y
	sprite.setTextureRect(sf::IntRect(dn += 10, dy, 10, 16)); sprite_list.push_back(sprite); //z
}

CWritter::~CWritter(void) {}

sf::String CWritter::intToString(int x)
{
	std::ostringstream oss;
	oss << x;
	return oss.str();
}

void CWritter::ecrire(int value, sf::RenderTexture* renderTexture, sf::Vector2i pos, sf::Color color)
{
	ecrire(intToString(value), renderTexture, pos, color);
}

void CWritter::ecrire(sf::String string, sf::RenderTexture* renderTexture, sf::Vector2i pos, sf::Color color)
{
	renderTexture->clear(color);

	int pos_x = pos.x;
	for (int i = 0; i<string.getSize(); i++)
	{
		if (string[i] == ' ')
		{
			sprite_list[11].setPosition(pos_x, pos.y);
			renderTexture->draw(sprite_list[11]);
			pos_x += sprite_list[11].getTextureRect().width;
		}
		else if (string[i] >= 'a')
		{
			sprite_list[string[i] - 'a' + 38].setPosition(pos_x, pos.y);
			renderTexture->draw(sprite_list[string[i] - 'a' + 38]);
			pos_x += sprite_list[string[i] - 'a' + 38].getTextureRect().width;
		}
		else if (string[i] >= 'A')
		{
			sprite_list[string[i] - 'A' + 12].setPosition(pos_x, pos.y);
			renderTexture->draw(sprite_list[string[i] - 'A' + 12]);
			pos_x += sprite_list[string[i] - 'A' + 12].getTextureRect().width;
		}
		else if (string[i] == '-')
		{
			sprite_list[10].setPosition(pos_x, pos.y);
			renderTexture->draw(sprite_list[10]);
			pos_x += sprite_list[10].getTextureRect().width;
		}
		else
		{
			sprite_list[string[i] - '0'].setPosition(pos_x, pos.y);
			renderTexture->draw(sprite_list[string[i] - '0']);
			pos_x += sprite_list[string[i] - '0'].getTextureRect().width;
		}
	}
	renderTexture->display();
}
