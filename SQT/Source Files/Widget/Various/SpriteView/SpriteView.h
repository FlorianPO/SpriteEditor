#pragma once

#include "stdenum.h"
#include "Source Files/Widget/SQT/SQT.h"

class SpriteView : public SQT
{
	Q_OBJECT
// CONSTRUCTOR
public:
	SpriteView(QWidget* parent, QMainWindow* window=NULL);
	SpriteView(QWidget* parent, const sf::Texture& texture, QMainWindow* window=NULL);
	SpriteView(QWidget* parent, const sf::Texture& texture, const sf::IntRect& rect, QMainWindow* window=NULL);
	~SpriteView() {}

// METHODS
public:
	void setTexture(const sf::Texture& texture);
	void setTextureRect(const sf::IntRect& rect);
	void setOutLine(int pixel);

private:
	virtual void OnUpdate() override;
	bool eventFilter(QObject* object, QEvent* evnt) override;
	void resizeEvent(QResizeEvent* qr) override;

// SIGNALS SLOTS
	private slots:
		void resize();
	public slots:
		void select();
		void unselect();

// MEMBERS
private:
	QWidget* parent;
	sf::Sprite sprite;
	bool texture_rect_defined = false;
	sf::IntRect texture_rect;

	sf::Color background_color = sf::Color(240, 240, 240);
	bool selected = false;
	int pixel = 0;
};
