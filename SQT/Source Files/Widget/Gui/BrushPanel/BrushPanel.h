#pragma once

#include "stdenum.h"
#include "ui_BrushPanel.h"

class TabSFML; // Forward declaration
class ClickLabel; // Forward declaration
class Brush; // Forward declaration

class BrushPanel : public QWidget
{
	Q_OBJECT
// CONSTRUCTOR
public:
	BrushPanel(QWidget* parent, const QPoint& position=QPoint());
	~BrushPanel() {}

// SIGNALS SLOTS
	public slots:
		void brushCreated(Brush* brush);

// MEMBERS
private:
	Ui_BrushPanel ui;

	ClickLabel* Opacity;
	ClickLabel* Seuil;
	ClickLabel* SizeX;
	ClickLabel* SizeY;
	TabSFML* SFMLTab;
};
