#pragma once

#include "stdenum.h"
#include "Source Files/SignalType/SignalList.h"
#include "Source Files/SignalType/SignalListObject.h"

class Layer;

class Animation : public SignalListObject
{
	Q_OBJECT
// COSNTRUCTOR
public:
	Animation(const QString name);
	~Animation() {}

// METHODS
public:
	void gerer();
	void display();
	void setOffsetPosition(const sf::Vector2f& position);
	void setOffsetScale(float scale);
	
	inline const sf::Sprite& getSprite() const { return sprite; }
	inline SignalList& getList() { return anim_rect_list; }
	inline const QString& getName() const { return name; }
private:
	void selectFistAnimation();

// SIGNALS SLOTS
	public slots:
		void createAnimationRect(const sf::IntRect& rect=sf::IntRect());
		void setLayer(const Layer& layer);
		void dropSelected();
		void setName(const QString& name);
		void setPosition(const sf::Vector2f& position);
		void setScale(float factor);
		void show();
		void hide();
	signals:
		void nameChanged(const QString&) const;
		void animationChanged() const;
		void animationVisible() const;
		void animationUnvisible() const;
		void layerChanged(const Layer&) const;

// MEMBERS
private:
	SignalList anim_rect_list;

	bool visible = true;
	bool origin_resolved=false;
	sf::Sprite sprite;
	int cpt;
	int i_anim;

	sf::Vector2f position;
	sf::Vector2f offset_position;
	float scale = 1;
	float offset_scale;

	QString name;
};

