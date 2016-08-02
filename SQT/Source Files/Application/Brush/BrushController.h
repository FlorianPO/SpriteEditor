#pragma once

#include "stdenum.h"
#include "Source Files/SignalType/SignalInit.h"
class Brush; //Forward declaration

#define INIT_BRUSH_CONTROLLER BrushController::createInstance();
#define BRUSH_CONTROLLER BrushController::getInstance()
#define BRUSH BrushController::getInstance()->getCurrentBrush()

class BrushController : public QObject, SignalInit
{
	Q_OBJECT
// INSTANCE
private:	static BrushController* _t;
public:		inline static void createInstance() { _t = new BrushController(); }
			inline static BrushController* getInstance() { return _t; }

// CONSTRUCTOR
public:
	BrushController() : SignalInit() {}
	~BrushController() {}

// METHODS
public:
	void initSignals() override;
	inline Brush* getCurrentBrush() { return current_brush; }
	inline sf::Vector2i getDefaultSize() { return default_size; }
	inline int getSeuil() { return seuil; }
	inline int getOpacity() { return opacity; }

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
		void displayCenter();

// MEMBERS
private:
	Brush* current_brush = NULL;
	std::vector<Brush*> default_brushes;
	std::vector<Brush*> custom_brushes;

	sf::Vector2i default_size;
	int opacity;
	int seuil;
};

