#pragma once

#include <SFML/Graphics.hpp>
#include <deque>

class CArg
{
public:
	enum TYPE
	{
		COLOR,
		INTRECT,
		VECTOR_I,
		VECTOR_F,
		INT,
		FLOAT,
		STRING
	};

	CArg(void);
	~CArg(void);

	CArg(sf::Color c, CArg a = CArg());
	CArg(sf::IntRect r, CArg a = CArg());
	CArg(sf::Vector2i i, CArg a = CArg());
	CArg(sf::Vector2f f, CArg a = CArg());
	CArg(int i, CArg a = CArg());
	CArg(float f, CArg a = CArg());
	CArg(sf::String s, CArg a = CArg());

	inline TYPE is(int i) { return types[i]; }
	inline void* get(int i) { del = true; return arg[i]; }
	inline int size() { return types.size(); }

private:
	static std::deque<void*> buffer;
	static std::deque<TYPE> types_buffer;

private:
	bool del = false;
	std::deque<TYPE> types;
	std::deque<void*> arg;
};