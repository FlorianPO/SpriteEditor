#pragma once

#include "stdenum.h"
class Brush; //Forward declaration

#define INIT_BRUSH_CONTROLLER BrushController::createInstance();
#define BRUSH_CONTROLLER BrushController::getInstance()
#define BRUSH BrushController::getInstance()->getCurrentBrush()

class BrushController : public QObject
{
	Q_OBJECT
// INSTANCE
private:	static BrushController* _t;
public:		inline static void createInstance() { _t = new BrushController(); }
			inline static BrushController* getInstance() { return _t; }

// CONSTRUCTOR
public:
	BrushController();
	~BrushController() {}

// METHODS
public:
	inline Brush* getCurrentBrush() { return current_brush; }
	inline sf::Vector2i getDefaultSize() { return default_size; }
	inline int getSeuil() { return seuil; }
	inline int getOpacity() { return opacity; }
	void setExPosition(sf::Vector2f position);
	sf::Vector2f getExPosition() { return ex_position; }
	void setDisplayPosition(sf::Vector2f position) { display_position = position; }
	sf::Vector2f getDisplayPosition() { return display_position; }
private:
	friend class BrushUndo;
	void _setExPosition(sf::Vector2f position) { ex_position = position; }

// SIGNALS SLOTS
	// CREATE
	public slots:
		void createBrush(int brush_id);				// create default brush
		void createBrush(nBrh::brush_enum brush);	// create default brush
	signals:
		void brushCreated(Brush*);
	// SELECT
	public slots:
		void selectBrush(Brush* brush);
		void selectBrush(int brush_id);				// select default brush
		void selectBrush(nBrh::brush_enum brush);	// select default brush
	// SIZE
	public slots:
		void changeSize(sf::Vector2i value);
		void changeSizeX(int value);
		void changeSizeY(int value);
	signals:
		void sizeXChanged(int);
		void sizeYChanged(int);
	// OPACITY SEUIL
	public slots:
		void changeOpacity(int value);
		void changeSeuil(int value);
	signals:
		void opacityChanged(int);
		void seuilChanged(int);
	// OTHER
	public slots:
		void displayCenter(bool force=false);

// MEMBERS
private:
	Brush* current_brush = NULL;
	std::vector<Brush*> default_brushes;
	std::vector<Brush*> custom_brushes;

	sf::Vector2i default_size;
	int opacity;
	int seuil;

	sf::Vector2f ex_position;
	sf::Vector2f display_position;
};

