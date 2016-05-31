#include "Source Files/Application/Brush/BrushController.h"

#include "Source Files/Application/Brush/Brushes/BrushCircle.h"
#include "Source Files/Application/Brush/Brushes/BrushCircleOutline.h"
#include "Source Files/Application/Brush/Brushes/BrushSquare.h"
#include "Source Files/Application/Brush/Brushes/BrushSquareOutline.h"
#include "Source Files/Application/Res/Res.h"

CBrushController* CBrushController::_t;

void CBrushController::initSignals() {
	opacity = 255;
	emit opacityChanged(opacity);
	seuil = 7;
	emit seuilChanged(seuil);

	default_size = sf::Vector2i(25, 25);
	emit sizeXChanged(default_size.x);
	emit sizeYChanged(default_size.y);

	createBrush(CBrush::CIRCLE);
	createBrush(CBrush::CIRCLE_OUTLINE);
	createBrush(CBrush::SQUARE);
	createBrush(CBrush::SQUARE_OUTLINE);
}

////////////
// CREATE //
////////////
void CBrushController::createBrush(CBrush::brush_enum brush) {
	CBrush* brush_created = NULL;
	switch (brush)
	{
		// TODO
		//case CBrush::PIXEL:			brush_created = new ();						break;
		case CBrush::CIRCLE:			brush_created = new CBrushCircle();			break;
		case CBrush::CIRCLE_OUTLINE:	brush_created = new CBrushCircleOutline();	break;
		case CBrush::SQUARE:			brush_created = new CBrushSquare();			break;
		case CBrush::SQUARE_OUTLINE:	brush_created = new CBrushSquareOutline();	break;
		default:																	break;
	}
	brush_created->createPreview();
	brush_created->create(default_size);
	brush_created->createLines();

	default_brushes.push_back(brush_created);
	emit brushCreated(brush_created);
}

void CBrushController::createBrush(int brush_id) {
	createBrush(static_cast<CBrush::brush_enum>(brush_id));	
}

////////////
// SELECT //
////////////
void CBrushController::selectBrush(CBrush* brush) {
	if (current_brush != brush) {
		if (current_brush != NULL)
			current_brush->unselect();
		brush->select();

		current_brush = brush;	
	}
}
void CBrushController::selectBrush(CBrush::brush_enum brush) {
	for (int i=0; i < default_brushes.size(); i++)
		if (default_brushes[i]->getEnum() == brush)
			selectBrush(default_brushes[i]);
}
void CBrushController::selectBrush(int brush_id) {
	selectBrush(static_cast<CBrush::brush_enum>(brush_id));
}

//////////
// SIZE //
//////////
void CBrushController::changeSize(sf::Vector2i value) {
	changeSizeX(value.x);
	changeSizeY(value.y);
}
void CBrushController::changeSizeX(int value) {
	if (default_size.x != value) {
		default_size.x = value;
		emit sizeXChanged(value);

		if (current_brush != NULL)
			current_brush->checkSize(default_size);
	}
}
void CBrushController::changeSizeY(int value) {
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
void CBrushController::changeOpacity(int value) {
	if (opacity !=  value) {
		opacity = value;
		RES->getShader(CRes::usual)->setParameter("opacity", value);
		emit opacityChanged(value);
	}
}
void CBrushController::changeSeuil(int value) {
	if (seuil !=  value) {
		seuil = value;
		emit seuilChanged(value);
	}
}