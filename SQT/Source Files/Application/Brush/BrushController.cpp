#include "BrushController.h"

#include "Source Files/Application/Brush/Brushes/BrushCircle.h"
#include "Source Files/Application/Brush/Brushes/BrushCircleOutline.h"
#include "Source Files/Application/Brush/Brushes/BrushSquare.h"
#include "Source Files/Application/Brush/Brushes/BrushSquareOutline.h"
#include "Source Files/Application/Resource/ResourceController.h"
#include "Source Files/Application/Input/InputController.h"
#include "Source Files/Application/App.h"
#include "Source Files/Application/Queue/QueueController.h"
#include "Source Files/Fonction/Fonction.h"
#include "Source Files/Application/UndoStack/UndoStack.h"
#include "BrushUndo.h"

using namespace nBrh;

BrushController* BrushController::_t;

BrushController::BrushController() {
	QUEUE->atStart([this]() {
		changeOpacity(255);
		changeSeuil(7);

		changeSize(sf::Vector2i(25, 25));

		createBrush(CIRCLE);
		createBrush(CIRCLE_OUTLINE);
		createBrush(SQUARE);
		createBrush(SQUARE_OUTLINE);
	});
}

////////////
// CREATE //
////////////
void BrushController::createBrush(nBrh::brush_enum brush) {
	Brush* brush_created = NULL;
	switch (brush)
	{
		// TODO
		//case PIXEL:			brush_created = new ();						break;
		case CIRCLE:			brush_created = new BrushCircle();			break;
		case CIRCLE_OUTLINE:	brush_created = new BrushCircleOutline();	break;
		case SQUARE:			brush_created = new BrushSquare();			break;
		case SQUARE_OUTLINE:	brush_created = new BrushSquareOutline();	break;
		default:															break;
	}
	brush_created->createPreview();
	brush_created->checkSize(default_size);

	default_brushes.push_back(brush_created);
	emit brushCreated(*brush_created);
}

void BrushController::setExPosition(const sf::Vector2f& position) {
	_setExPosition(position);
	UNDO->push(*new BrushUndo(position));
}

void BrushController::createBrush(int brush_id) {
	createBrush(static_cast<brush_enum>(brush_id));	
}

////////////
// SELECT //
////////////
void BrushController::selectBrush(Brush& brush) {
	if (current_brush != &brush) {
		if (current_brush != NULL)
			current_brush->unselect();
		brush.select();
		brush.checkSize(default_size);
		
		current_brush = &brush;	
		displayCenter(true);
	}
}
void BrushController::selectBrush(nBrh::brush_enum brush) {
	FOR_I (default_brushes.size())
		if (default_brushes[i]->getEnum() == brush)
			selectBrush(*default_brushes[i]);
}
void BrushController::selectBrush(int brush_id) {
	selectBrush(static_cast<nBrh::brush_enum>(brush_id));
}

//////////
// SIZE //
//////////
void BrushController::changeSize(const sf::Vector2i& value) {
	changeSizeX(value.x);
	changeSizeY(value.y);
}
void BrushController::changeSizeX(int value) {
	if (default_size.x != value) {
		default_size.x = value;
		emit sizeXChanged(value);

		if (current_brush != NULL)
			current_brush->checkSize(default_size);
	}
}
void BrushController::changeSizeY(int value) {
	if (default_size.y != value) {
		default_size.y = value;
		emit sizeYChanged(value);

		if (current_brush != NULL)
			current_brush->checkSize(default_size);
	}
}

///////////////////
// OPACITY SEUIL //
///////////////////
void BrushController::changeOpacity(int value) {
	if (opacity != value) {
		opacity = value;
		RES->getShader(nRer::usual).setParameter("opacity", value);
		RES->getShader(nRer::pot).setParameter("opacity", value);
		emit opacityChanged(value);
	}
}
void BrushController::changeSeuil(int value) {
	if (seuil != value) {
		seuil = value;
		emit seuilChanged(value);
	}
}

///////////
// OTHER //
///////////
void BrushController::displayCenter(bool force) {
	setDisplayPosition(INPUT->screenToPos(VECTOR2I(Fonction::centerCorner(APP->getWindow().getSize()))));
}