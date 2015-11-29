#include "Arg.h"
#include <iostream>

std::deque<void*> CArg::buffer;
std::deque<CArg::TYPE> CArg::types_buffer;

CArg::CArg(void)
{
	CArg::buffer.clear();
	CArg::types_buffer.clear();
}

CArg::CArg(sf::Color i, CArg a)
{
	buffer.push_front(new sf::Color(i));
	types_buffer.push_front(COLOR);

	arg = buffer;
	types = types_buffer;
}

CArg::CArg(sf::IntRect r, CArg a)
{
	buffer.push_front(new sf::IntRect(r));
	types_buffer.push_front(INTRECT);

	arg = buffer;
	types = types_buffer;
}

CArg::CArg(sf::Vector2i i, CArg a)
{
	buffer.push_front(new sf::Vector2i(i));
	types_buffer.push_front(VECTOR_I);

	arg = buffer;
	types = types_buffer;
}

CArg::CArg(sf::Vector2f f, CArg a)
{
	buffer.push_front(new sf::Vector2i(f));
	types_buffer.push_front(VECTOR_I);

	arg = buffer;
	types = types_buffer;
}

CArg::CArg(int i, CArg a)
{
	buffer.push_front(new int(i));
	types_buffer.push_front(INT);

	arg = buffer;
	types = types_buffer;
}

CArg::CArg(float f, CArg a)
{
	buffer.push_front(new float(f));
	types_buffer.push_front(FLOAT);

	arg = buffer;
	types = types_buffer;
}

CArg::~CArg(void)
{
	if (del)
		for (int i = 0; i < types.size(); i++)
			delete arg[i];
}