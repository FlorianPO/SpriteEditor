#pragma once

#include "stdenum.h"

class LayerUndo : public nUnk::UndoCommand
{
public:
	LayerUndo(void* instance) { this->instance = instance; }
	~LayerUndo() {}

	virtual sf::Image* getImage() const;
	virtual sf::Vector2f getPosition() const;
};

class LayerCreated : public LayerUndo
{
public:
	LayerCreated(void* layer, sf::Image& image);
	~LayerCreated();
	void undo() override;
	void redo() override;

	sf::Image* getImage() const override { return image; }
	sf::Vector2f getPosition() const override { return sf::Vector2f(); }
private:
	sf::Image* image;
};

class LayerDrawn : public LayerUndo
{
public:
	LayerDrawn(void* layer, sf::Image& image);
	~LayerDrawn();
	void undo() override;
	void redo() override;

	sf::Image* getImage() const override { return image; }
private:
	sf::Image* image;
};

class LayerMoved : public LayerUndo
{
public:
	LayerMoved(void* layer, const sf::Vector2f& position);
	~LayerMoved() {}
	void undo() override;
	void redo() override;

	sf::Vector2f getPosition() const override { return position; }
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