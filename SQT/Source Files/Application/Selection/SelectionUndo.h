#pragma once

#include "stdenum.h"

class SelecUndo : public nUnk::UndoCommand
{
public:
	SelecUndo(void* instance) { this->instance = instance; }
	~SelecUndo() {}

	virtual sf::Image* getImage() const;
	virtual sf::Vector2f getPosition() const;
	virtual nSet::positionned_olines* getLines() const;
	virtual bool isInverted() const;
};

class SelecUpdated : public SelecUndo
{
public:
	SelecUpdated(void* instance, sf::Image& image, sf::Vector2f position, nSet::positionned_olines& oriented_lines, bool inverted);
	~SelecUpdated();
	void undo() override;
	void redo() override;

	sf::Image* getImage() const override { return image; }
	sf::Vector2f getPosition() const override	{ return position; }
	nSet::positionned_olines* getLines() const override { return plines; }
	bool isInverted() const override { return inverted; }
private:
	sf::Image* image;
	sf::Vector2f position;
	nSet::positionned_olines* plines;
	bool inverted;
};

class SelecMoved : public SelecUndo
{
public:
	SelecMoved(void* instance, const sf::Vector2f& position);
	~SelecMoved() {}
	void undo() override;
	void redo() override;

	sf::Vector2f getPosition() const override { return position; }
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

	sf::Image* getImage() const override { return NULL; }
	sf::Vector2f getPosition() const override	{ return sf::Vector2f(); }
	nSet::positionned_olines* getLines() const override { return NULL; }
	bool isInverted() const override { return false; }
};

class SelecInverted : public SelecUndo
{
public:
	SelecInverted(void* instance, sf::Image& image, bool inverted);
	~SelecInverted();
	void undo() override;
	void redo() override;

	sf::Image* getImage() const override { return image; }
	bool isInverted() const override { return inverted; }
private:
	sf::Image* image;
	bool inverted;
};