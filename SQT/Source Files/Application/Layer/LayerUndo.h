#pragma once

#include "stdenum.h"

class LayerUndo : public nUnk::UndoCommand
{
public:
	LayerUndo(void* instance) { this->instance = instance; }
	~LayerUndo() {}

	virtual sf::Image* getImage();
	virtual sf::Vector2f getPosition();
};

class LayerCreated : public LayerUndo
{
public:
	LayerCreated(void* layer, sf::Image* image);
	~LayerCreated();
	void undo() override;
	void redo() override;

	sf::Image* getImage() override { return image; }
	sf::Vector2f getPosition() override { return sf::Vector2f(); }
private:
	sf::Image* image;
};

class LayerDrawn : public LayerUndo
{
public:
	LayerDrawn(void* layer, sf::Image* image);
	~LayerDrawn();
	void undo() override;
	void redo() override;

	sf::Image* getImage() override { return image; }
private:
	sf::Image* image;
};

class LayerMoved : public LayerUndo
{
public:
	LayerMoved(void* layer, sf::Vector2f position);
	~LayerMoved() {}
	void undo() override;
	void redo() override;

	sf::Vector2f getPosition() override { return position; }
private:
	sf::Vector2f position;
};

class LayerDropped : public LayerUndo
{
public:
	LayerDropped(void* layer);
	~LayerDropped() {}
	void undo() override;
	void redo() override;
};

// LAYER_CONTROLLER
class LayerOrdered : public nUnk::UndoCommand
{
public:
	LayerOrdered(int src, int dst);
	~LayerOrdered() {}
	void undo() override;
	void redo() override;

private:
	int source;
	int destination;
};