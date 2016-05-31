#pragma once

#include "stdafx.h"
#include "Source Files/Application/Brush/Brush.h"
#include "Source Files/SignalType/SignalController.h"

#define INIT_BRUSH_CONTROLLER CBrushController::createInstance();

#define BRUSH_CONTROLLER CBrushController::getInstance()
#define BRUSH CBrushController::getInstance()->getCurrentBrush()

class CBrushController : public QObject, private SignalController
{
	Q_OBJECT
// INSTANCE
private:	static CBrushController* _t;
public:		inline static void createInstance() { _t = new CBrushController(); }
			inline static CBrushController* getInstance() { return _t; }

// CONSTRUCTOR
public:
	CBrushController() : SignalController() {}
	~CBrushController() {}

// METHODS
public:
	void initSignals() override;
	inline CBrush* getCurrentBrush() { return current_brush; }
	inline sf::Vector2i getDefaultSize() { return default_size; }
	inline int getSeuil() { return seuil; }
	inline int getOpacity() { return opacity; }

// SIGNALS SLOTS
	// CREATE
	public slots:
		void createBrush(int brush_id);				// create default brush
		void createBrush(CBrush::brush_enum brush); // create default brush
	signals:
		void brushCreated(CBrush*);
	// SELECT
	public slots:
		void selectBrush(CBrush* brush);
		void selectBrush(int brush_id);				// select default brush
		void selectBrush(CBrush::brush_enum brush); // select default brush
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

// MEMBERS
private:
	CBrush* current_brush = NULL;
	std::vector<CBrush*> default_brushes;
	std::vector<CBrush*> custom_brushes;

	sf::Vector2i default_size;
	int opacity;
	int seuil;
};

