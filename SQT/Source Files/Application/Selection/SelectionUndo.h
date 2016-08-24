#pragma once

#include "stdenum.h"

class SelecUndo : public nUnk::UndoCommand
{
public:
	SelecUndo(void* instance) { this->instance = instance; }
	~SelecUndo() {}

	virtual sf::Image* getImage();
	virtual sf::Vector2f getPosition();
	virtual nSet::positionned_olines* getLines();
	virtual bool isInverted();
};

class SelecUpdated : public SelecUndo
{
public:
	SelecUpdated(void* instance, sf::Image* image, sf::Vector2f position, nSet::positionned_olines* oriented_lines, bool inverted);
	~SelecUpdated();
	void undo() override;
	void redo() override;

	sf::Image* getImage() override { return image; }
	sf::Vector2f getPosition() override	{ return position; }
	nSet::positionned_olines* getLines() override { return plines; }
	bool isInverted() override { return inverted; }
private:
	sf::Image* image;
	sf::Vector2f position;
	nSet::positionned_olines* plines;
	bool inverted;
};

class SelecMoved : public SelecUndo
{
public:
	SelecMoved(void* instance, sf::Vector2f position);
	~SelecMoved() {}
	void undo() override;
	void redo() override;

	sf::Vector2f getPosition() override	{ return position; }
private:
	sf::Vector2f position;
};

class SelecDeleted : public SelecUndo
{
public:
	SelecDeleted(void* instance);
	~SelecDeleted() {}
	void undo() override;
	void redo() override;

	sf::Image* getImage() override { return NULL; }
	sf::Vector2f getPosition() override	{ return sf::Vector2f(); }
	nSet::positionned_olines* getLines() override { return NULL; }
	bool isInverted() override { return false; }
};

class SelecInverted : public SelecUndo
{
public:
	SelecInverted(void* instance, sf::Image* image, bool inverted);
	~SelecInverted();
	void undo() override;
	void redo() override;

	sf::Image* getImage() override { return image; }
	bool isInverted() override { return inverted; }
private:
	sf::Image* image;
	bool inverted;
};