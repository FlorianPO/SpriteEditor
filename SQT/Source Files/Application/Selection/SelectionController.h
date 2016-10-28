#pragma once

#include "stdenum.h"

#define INIT_SELECTION_CONTROLLER SelectionController::createInstance();
#define SELECTION_CONTROLLER SelectionController::getInstance()
#define SELEC SELECTION_CONTROLLER

class SelectionController : public QObject
{
	Q_OBJECT
// INSTANCE
private:	static SelectionController* _t; 
public:		inline static void createInstance() { _t = new SelectionController(); }
			inline static SelectionController* getInstance() { return _t; }

// CONSTRUCTOR
public:
	SelectionController();
	~SelectionController() {}
	void freeWork();

// SIGNALS / SLOTS
	public slots:
		void createSelection(const sf::IntRect& rect, const std::vector<nSet::o_line>& conf_l);
		void createSelection(const sf::IntRect& rect, const sf::Image& image, const std::vector<nSet::o_line>& conf_l);
		void deleteSelection(bool force=false);
		void addSelection(const sf::IntRect& rect,	const std::vector<nSet::o_line>& conf_l);
		void addSelection(const sf::IntRect& rect, const sf::Image& image, const std::vector<nSet::o_line>& conf_l);
		void subSelection(const sf::IntRect& rect, const std::vector<nSet::o_line>& conf_l);
		void subSelection(const sf::IntRect& rect, const sf::Image& image, const std::vector<nSet::o_line>& conf_l);
		void intersectSelection(const sf::IntRect& rect, const std::vector<nSet::o_line>& conf_l);
		void intersectSelection(const sf::IntRect& rect, const sf::Image& image, const std::vector<nSet::o_line>& conf_l);
		void invertSelection();
		void uninvertSelection();
		void deleteLayer();
	private slots:
		void createSelection(const sf::IntRect& rect, const sf::Image* image);
		void sumSelection(const sf::IntRect& rect, const sf::Image* image, bool add); // add == false -> sub
		void intersectSelection(const sf::IntRect& rect, const sf::Image* image);
	signals:
		void selectionUpdated(int mode=0) const; // Always emitted when selection changes : 1 add, 2 sub, 3 intersect
		void selectionCreated() const;
		void selectionDeleted() const;
		void selectionInverted() const;
		void selectionUninverted() const;
		void selectionMoved(sf::Vector2f) const;
		void selectionScaled(sf::Vector2f) const;
		
// METHODS
public:
	void displayLines();
	void move(); // Direct mouse manipulation
	void translate(const sf::Vector2f& translation);
	void setPosition(const sf::Vector2f& pos);
	void setRealPosition(const sf::Vector2f& real_pos);

	template <typename T>
	bool onSelec(const sf::Vector2<T>& pos) const;
	inline bool isSelected() const { return pos_lines != NULL; }
	inline bool isInverted() const { return inverted; }
	inline const sf::Vector2f& getPosition() const { return sprite_selec.getPosition(); }
	sf::Vector2f getRealPosition() const;
	inline const sf::IntRect& getCadre() const { return cadre; }

private:
	void invert();
	void updateCadre();
	void del();
	bool reline(); // return true if no selection
	Q_INVOKABLE void updateLines();
	void keyMove(const sf::Vector2f& pos);

// MEMBERS
public:
	sf::Color blend_color = sf::Color(255, 255, 255, 0);
	sf::Color ident_color = sf::Color(255, 255, 255, 255);
private:
	bool inverted = false;

	sf::IntRect cadre;
	sf::RenderTexture renderTexture_selec;
	sf::Sprite sprite_selec;

	sf::Image* image_selec;
	nSet::positionned_olines* pos_lines;

	// Related to void move()
	sf::Vector2i pos_init;
	sf::Vector2f pos_selec;

// UNDO
public:
	friend class SelecUpdated;
	friend class SelecMoved;
	friend class SelecDeleted;
	friend class SelecInverted;

	private:
		void setSelection(sf::Image* image, sf::Vector2f position, nSet::positionned_olines* plines, bool invert);
		void setImage(sf::Image* image);
		void setLines(nSet::positionned_olines* plines);
		void setInverted(bool inverted);
};

template <typename T>
bool SelectionController::onSelec(const sf::Vector2<T>& pos) const {
	if (isSelected())
		if (inverted)
			return pos.x - sprite_selec.getPosition().x >= 0 &&
			pos.x - sprite_selec.getPosition().x < image_selec->getSize().x &&
			pos.y - sprite_selec.getPosition().y >= 0 &&
			pos.y - sprite_selec.getPosition().y < image_selec->getSize().y &&
			image_selec->getPixel(pos.x - sprite_selec.getPosition().x, pos.y - sprite_selec.getPosition().y).a == 0;
		else
			if (pos.x - sprite_selec.getPosition().x >= 0
				&& pos.x - sprite_selec.getPosition().x < image_selec->getSize().x
				&& pos.y - sprite_selec.getPosition().y >= 0
				&& pos.y - sprite_selec.getPosition().y < image_selec->getSize().y)
				return image_selec->getPixel(pos.x - sprite_selec.getPosition().x, pos.y - sprite_selec.getPosition().y).a == 0;

	return true;
}