#include "BrushPanel.h"

#include "BrushWidget/BrushWidget.h"
#include "Source Files/Application/Brush/BrushController.h"
#include "Source Files/Application/Brush/Brush.h"
#include "Source Files/Widget/Various/Label/ClickLabel.h"
#include "Source Files/Widget/Various/TabSFML/TabSFML.h"

BrushPanel::BrushPanel(QWidget* parent) : QWidget(parent) {
	ui.setupUi(this);
	hide();

	// OPACITY
	Opacity = new ClickLabel(this, sf::Vector2i(0, 255));
	Opacity->move(QPoint(0, 0));
	Opacity->show();
	QObject::connect(BRUSH_CONTROLLER, SIGNAL(opacityChanged(int)), Opacity, SLOT(changeValue(int)), Qt::DirectConnection);
	QObject::connect(Opacity, SIGNAL(valueChanged(int)), BRUSH_CONTROLLER, SLOT(changeOpacity(int)), Qt::DirectConnection);
	// SEUIL
	Seuil = new ClickLabel(this, sf::Vector2i(0, 255));
	Seuil->move(QPoint(0, 16));
	Seuil->show();
	QObject::connect(BRUSH_CONTROLLER, SIGNAL(seuilChanged(int)), Seuil, SLOT(changeValue(int)), Qt::DirectConnection);
	QObject::connect(Seuil, SIGNAL(valueChanged(int)), BRUSH_CONTROLLER, SLOT(changeSeuil(int)), Qt::DirectConnection);
	// SIZE X
	SizeX = new ClickLabel(this, sf::Vector2i(1, 999));
	SizeX->move(QPoint(0, 40));
	SizeX->show();
	QObject::connect(BRUSH_CONTROLLER, SIGNAL(sizeXChanged(int)), SizeX, SLOT(changeValue(int)), Qt::DirectConnection);
	QObject::connect(SizeX, SIGNAL(valueChanged(int)), BRUSH_CONTROLLER, SLOT(changeSizeX(int)), Qt::DirectConnection);
	// SIZE Y
	SizeY = new ClickLabel(this, sf::Vector2i(1, 999));
	SizeY->move(QPoint(48, 40));
	SizeY->show();
	QObject::connect(BRUSH_CONTROLLER, SIGNAL(sizeYChanged(int)), SizeY, SLOT(changeValue(int)), Qt::DirectConnection);
	QObject::connect(SizeY, SIGNAL(valueChanged(int)), BRUSH_CONTROLLER, SLOT(changeSizeY(int)), Qt::DirectConnection);
	// TAB
	QWidget* qw = new QWidget(ui.DefaultFrame);
	qw->resize(ui.DefaultFrame->size());
	qw->show();
	SFMLTab = new TabSFML(qw, ui.DefaultFrame->size());
	SFMLTab->setGeometry(ui.DefaultFrame->geometry());
	SFMLTab->show();

	// THIS
	QObject::connect(BRUSH_CONTROLLER, SIGNAL(brushCreated(Brush&)), this, SLOT(brushCreated(Brush&)));
	QObject::connect(SizeX, SIGNAL(focusIn()), BRUSH_CONTROLLER, SLOT(displayCenter()));
	QObject::connect(SizeY, SIGNAL(focusIn()), BRUSH_CONTROLLER, SLOT(displayCenter()));
}

void BrushPanel::brushCreated(Brush& brush) {
	BrushWidget* tool_widget = new BrushWidget(brush, brush.getPreviewTexture());
	QObject::connect(BRUSH_CONTROLLER, SIGNAL(sizeXChanged(int)), tool_widget, SLOT(sizeXChanged(int)), Qt::DirectConnection);
	QObject::connect(BRUSH_CONTROLLER, SIGNAL(sizeYChanged(int)), tool_widget, SLOT(sizeYChanged(int)), Qt::DirectConnection);
	SFMLTab->add(*tool_widget);
}
