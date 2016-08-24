#pragma once

//SFMLView
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

//Librairies Windows
#include <queue>
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <tchar.h>
#include <cfloat>
#include <functional>
#include <stack>
#include <thread>
#include <unordered_map>
#include <climits>

//Presse papier
#include <windows.h>
#include <typeinfo>

//Qt
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QLabel>
#include <QUndoStack.h>
#include <QPushButton>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QTimer>
#include <QLineEdit>
#include <QtCore/QSignalMapper.h>
#include <QShortcut.h>
#include <QMenuBar.h>
#include <QMenu.h>
#include <QFileDialog.h>

#define PI 3.14159265358979323846
#define PIH PI / 8.0

// MACRO DEFINITION
#define QBOTTOMY(w)				(w)->pos().y() + (w)->size().height()
#define VECTOR2D(v)				Vector2d(v.x, v.y)
#define VECTOR2F(v)				sf::Vector2f(v.x, v.y)
#define VECTOR2I(v)				sf::Vector2i(v.x, v.y)
#define RECTI(r)				sf::IntRect(r.left, r.top, r.width, r.height)
#define RECTF(r)				sf::IntRect(r.left, r.top, r.width, r.height)
#define POS_RECT(r)				sf::Vector2f(r.left, r.top)
#define SIZE_RECT(r)			sf::Vector2f(r.width, r.height)

#define ARG_VECTOR(v)			v.x, v.y
#define ARG_RECT(r)				r.left, r.top, r.width, r.height
#define ARG_POS(r)				r.left, r.top
#define ARG_SIZE(r)				r.width, r.height
#define CALL_VECTOR2F(v, f)		sf::Vector2f(f(v.x), f(v.y))
#define CALL_VECTOR2I(v, f)		sf::Vector2i(f(v.x), f(v.y))
#define OPER_VECTOR2F(v, op)	sf::Vector2f(v.x op, v.y op)
#define OPER_VECTOR2I(v, op)	sf::Vector2f(v.x op, v.y op)

#define H_VECTOR2F(v)	sf::Vector2f(v.x / 2.f, v.y / 2.f)
#define H_VECTOR2I(v)	sf::Vector2i(v.x / 2.f, v.y / 2.f)
#define H_RECT(r)		sf::Vector2f(r.left + r.width / 2.f, r.top + r.height / 2.f)

#define DEBUG					std::cout << "_Debug_" << std::endl;
#define DEBUGN(n)				std::cout << n << std::endl;
#define DEBUGH(h, n)			std::cout << h << " : " << n << std::endl;
#define DEBUG_VECTOR(v)			std::cout << v.x << "   " << v.y << std::endl;
#define DEBUG_RECT(r)			std::cout << r.left << "   " << r.top  << "   " << r.width  << "   " << r.height << std::endl;
#define DEBUGN_VECTOR(n, v)		std::cout << n << ":  " << v.x << "   " << v.y << std::endl;
#define DEBUGN_RECT(n, r)		std::cout << n << ":  " << r.left << "   " << r.top  << "   " << r.width  << "   " << r.height << std::endl;

#define FOR(i, max)		for (int i=0; i < max; i++)
#define FOR_I(max)		for (int i=0; i < max; i++)
#define FOR_J(max)		for (int j=0; j < max; j++)
#define FOR_K(max)		for (int k=0; k < max; k++)
#define FOR_INV(i, max)		for (int i=max-1; i >=0; i--)
#define FOR_I_INV(max)		for (int i=max-1; i >= 0; i--)
#define FOR_J_INV(max)		for (int j=max-1; j >= 0; j--)
#define FOR_K_INV(max)		for (int k=max-1; k >= 0; k--)
#define FIRST(list)		list[0]
#define LAST(list)		list[list.size()-1]

typedef sf::Vector2<double> Vector2d;