#pragma once

#include "stdenum.h"

class CopyUndo : public nUnk::UndoCommand
{
public:
	CopyUndo(void* instance) { this->instance = instance; }
	~CopyUndo() {}

	virtual sf::Vector2f getPosition() const;
	virtual sf::Vector2f getScale() const;
	virtual float getRotation() const;
	virtual sf::Vector2f getOrigin() const;
};

class CopyCreated : public CopyUndo
{
public:
	CopyCreated(void* copy, const sf::Vector2f& position);
	~CopyCreated();
	void undo() override;
	void redo() override;

	sf::Vector2f getPosition() const override { return position; }
	sf::Vector2f getScale() const override { return sf::Vector2f(1, 1); }
	float getRotation() const override { return 0; }
	sf::Vector2f getOrigin() const override { return sf::Vector2f(); }
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
	CopyMoved(void* copy, const sf::Vector2f& position);
	~CopyMoved() {}
	void undo() override;
	void redo() override;

	sf::Vector2f getPosition() const override { return position; }
private:
	sf::Vector2f position;
};

class CopyScaled : public CopyUndo
{
public:
	CopyScaled(void* copy, const sf::Vector2f& position, const sf::Vector2f& scale, const sf::Vector2f& origin);
	~CopyScaled() {}
	void undo() override;
	void redo() override;

	sf::Vector2f getPosition() const override { return position; }
	sf::Vector2f getScale() const override { return scale; }
	sf::Vector2f getOrigin() const override { return origin; }
private:
	sf::Vector2f position;
	sf::Vector2f scale;
	sf::Vector2f origin;
};

class CopyRotated : public CopyUndo
{
public:
	CopyRotated(void* copy, const sf::Vector2f& position, float rotation, const sf::Vector2f& origin);
	~CopyRotated() {}
	void undo() override;
	void redo() override;

	sf::Vector2f getPosition() const override { return position; }
	float getRotation() const override { return rotation; }
	sf::Vector2f getOrigin() const override { return origin; }
private:
	sf::Vector2f position;
	float rotation;
	sf::Vector2f origin;
};

class CopyFlipped : public CopyUndo
{
public:
	CopyFlipped(void* copy, const sf::Vector2f& position, const sf::Vector2f& scale);
	~CopyFlipped() {}
	void undo() override;
	void redo() override;

	sf::Vector2f getPosition() const override { return position; }
	sf::Vector2f getScale() const override { return scale; }
private:
	sf::Vector2f position;
	sf::Vector2f scale;
};