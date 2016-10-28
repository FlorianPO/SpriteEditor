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
	inline Brush* getCurrentBrush() const { return current_brush; }
	inline const sf::Vector2i& getDefaultSize() const { return default_size; }
	inline int getSeuil() const { return seuil; }
	inline int getOpacity() const { return opacity; }
	void setExPosition(const sf::Vector2f& position);
	const sf::Vector2f& getExPosition() const { return ex_position; }
	void setDisplayPosition(const sf::Vector2f& position) { display_position = position; }
	const sf::Vector2f& getDisplayPosition() const { return display_position; }
private:
	friend class BrushUndo;
	void _setExPosition(const sf::Vector2f& position) { ex_position = position; }

// SIGNALS SLOTS
	// CREATE
	public slots:
		void createBrush(int brush_id);				// create default brush
		void createBrush(nBrh::brush_enum brush);	// create default brush
	signals:
		void brushCreated(Brush&) const;
	// SELECT
	public slots:
		void selectBrush(Brush& brush);
		void selectBrush(int brush_id);				// select default brush
		void selectBrush(nBrh::brush_enum brush);	// select default brush
	// SIZE
	public slots:
		void changeSize(const sf::Vector2i& value);
		void changeSizeX(int value);
		void changeSizeY(int value);
	signals:
		void sizeXChanged(int) const;
		void sizeYChanged(int) const;
	// OPACITY SEUIL
	public slots:
		void changeOpacity(int value);
		void changeSeuil(int value);
	signals:
		void opacityChanged(int) const;
		void seuilChanged(int) const;
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

