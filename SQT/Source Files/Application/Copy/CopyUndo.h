#pragma once

#include "stdenum.h"

class CopyUndo : public nUnk::UndoCommand
{
public:
	CopyUndo(void* instance) { this->instance = instance; }
	~CopyUndo() {}

	virtual sf::Vector2f getPosition();
	virtual sf::Vector2f getScale();
	virtual float getRotation();
	virtual sf::Vector2f getOrigin();
};

class CopyCreated : public CopyUndo
{
public:
	CopyCreated(void* copy, sf::Vector2f position);
	~CopyCreated();
	void undo() override;
	void redo() override;

	sf::Vector2f getPosition() override { return position; }
	sf::Vector2f getScale() override { return sf::Vector2f(1, 1); }
	float getRotation() override { return 0; }
	sf::Vector2f getOrigin() override { return sf::Vector2f(); }
private:
	sf::Vector2f position;
};

class CopyDropped : public CopyUndo
{
public:
	CopyDropped(void* copy);
	~CopyDropped() {}
	void undo() override;
	void redo() override;
};

class CopyMoved : public CopyUndo
{
public:
	CopyMoved(void* copy, sf::Vector2f position);
	~CopyMoved() {}
	void undo() override;
	void redo() override;

	sf::Vector2f getPosition() override { return position; }
private:
	sf::Vector2f position;
};

class CopyScaled : public CopyUndo
{
public:
	CopyScaled(void* copy, sf::Vector2f position, sf::Vector2f scale, sf::Vector2f origin);
	~CopyScaled() {}
	void undo() override;
	void redo() override;

	sf::Vector2f getPosition() override { return position; }
	sf::Vector2f getScale() override { return scale; }
	sf::Vector2f getOrigin() override { return origin; }
private:
	sf::Vector2f position;
	sf::Vector2f scale;
	sf::Vector2f origin;
};

class CopyRotated : public CopyUndo
{
public:
	CopyRotated(void* copy, sf::Vector2f position, float rotation, sf::Vector2f origin);
	~CopyRotated() {}
	void undo() override;
	void redo() override;

	sf::Vector2f getPosition() override { return position; }
	float getRotation() override { return rotation; }
	sf::Vector2f getOrigin() override { return origin; }
private:
	sf::Vector2f position;
	float rotation;
	sf::Vector2f origin;
};

class CopyFlipped : public CopyUndo
{
public:
	CopyFlipped(void* copy, sf::Vector2f position, sf::Vector2f scale);
	~CopyFlipped() {}
	void undo() override;
	void redo() override;

	sf::Vector2f getPosition() override { return position; }
	sf::Vector2f getScale() override { return scale; }
private:
	sf::Vector2f position;
	sf::Vector2f scale;
};