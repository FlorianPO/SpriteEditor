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
		void createSelection(sf::IntRect rect, const std::vector<nSet::o_line>& conf_l);
		void createSelection(sf::IntRect rect, const sf::Image& image, const std::vector<nSet::o_line>& conf_l);
		void deleteSelection(bool force=false);
		void addSelection(sf::IntRect rect,	const std::vector<nSet::o_line>& conf_l);
		void addSelection(sf::IntRect rect, const sf::Image& image, const std::vector<nSet::o_line>& conf_l);
		void subSelection(sf::IntRect rect, const std::vector<nSet::o_line>& conf_l);
		void subSelection(sf::IntRect rect, const sf::Image& image, const std::vector<nSet::o_line>& conf_l);
		void intersectSelection(sf::IntRect rect, const std::vector<nSet::o_line>& conf_l);
		void intersectSelection(sf::IntRect rect, const sf::Image& image, const std::vector<nSet::o_line>& conf_l);
		void invertSelection();
		void uninvertSelection();
		void deleteLayer();
	private slots:
		void createSelection(sf::IntRect rect, const sf::Image* image);
		void sumSelection(sf::IntRect rect, const sf::Image* image, bool add); // add == false -> sub
		void intersectSelection(sf::IntRect rect, const sf::Image* image);
	signals:
		void selectionUpdated(int mode=0); // Always emitted when selection changes : 1 add, 2 sub, 3 intersect
		void selectionCreated();
		void selectionDeleted();
		void selectionInverted();
		void selectionUninverted();
		void selectionMoved(sf::Vector2f);
		void selectionScaled(sf::Vector2f);
		
// METHODS
public:
	void displayLines();
	void move(); // Direct mouse manipulation
	void translate(sf::Vector2f translation);
	void setPosition(sf::Vector2f pos);
	void setRealPosition(sf::Vector2f real_pos);

	bool onSelec(int x, int y);
	inline bool isSelected() { return pos_lines != NULL; }
	inline bool isInverted() { return inverted; }
	inline sf::Vector2f getPosition() { return sprite_selec.getPosition(); }
	sf::Vector2f getRealPosition();
	inline sf::IntRect getCadre() { return cadre; }

private:
	void invert();
	void updateCadre();
	void del();
	bool reline(); // return true if no selection
	Q_INVOKABLE void updateLines();
	void keyMove(int x, int y);

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

