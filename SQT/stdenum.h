#pragma once

#include "stdafx.h"

///////////////////////////////////////////
// class Class:  nCls                    //
//               ||||                    //
//               |||last letter          //
//               ||second letter         //
//               |first letter (capital) //
//           namespace                   //
//                                       //
// Input : nInt                          //
// Brush : nBrh                          //
// Tool  : nTol                          //
///////////////////////////////////////////

// Global
namespace nStd {
	enum Corner {
		UP_LEFT = 0,
		UP,
		UP_RIGHT,
		RIGHT,
		DOWN_RIGHT,
		DOWN,
		DOWN_LEFT,
		LEFT,
		CENTER
	};

	enum Angle {
		RAD = 0,
		DEG
	};
}

// Ressource
namespace nRer {
	enum TEXTURE {
		transparency = 0,
		none,
		LAST_TEXTURE
	};

	enum SPRITE {
		alpha_gimp = 0,
		sprite_white,
		LAST_SPRITE
	};

	enum SHADER {
		invert = 0,
		update,
		fuse,
		pot,
		cut,
		usual,
		LAST_SHADER
	};

	enum FONT {
		base = 0,
		LAST_FONT
	};
}

// UndoStack
namespace nUnk {
	class UndoCommand {
		private:
			bool first = false;
		protected:
			void* instance = NULL;
		public:
			UndoCommand() {}
			virtual ~UndoCommand() {}

			virtual void undo() = 0;
			virtual void redo() = 0;

			void* getInstance() { return instance; }

			void setFirst() { first = true; }
			bool isFirst() { return first; }
	};
}

// Input
namespace nInt {
	typedef int qkey; // Qt::Key or Qt::MouseButton or Qt::Modifier

	enum WheelKey {
		WHEEL_UP = 0x10000000,
		WHEEL_DOWN = 0x20000000
	};

	enum PressMode {
		PRESSED = 0x1,
		RELEASED = 0x2,
		AGAIN = 0x4,    
		LONG_TAP = 0x8,
		DOUBLE_TAP = 0x10,
		LOG = 0x20, 
		NONE = 0x40,
	};

	typedef int press_code;

	struct key_combinaison {
		press_code seq;
		int press_mode;
	};

	inline key_combinaison keyCombinaison(press_code seq, press_code press_code) {
		key_combinaison keys = { seq, press_code };
		return keys;
	}

	inline key_combinaison keyCombinaison(press_code seq, PressMode press_mode) {
		key_combinaison keys = { seq, press_mode };
		return keys;
	}
};

// Brush
namespace nBrh {
	enum brush_enum
	{
		PIXEL = 0,
		CIRCLE,
		CIRCLE_OUTLINE,
		SQUARE,
		SQUARE_OUTLINE
	};
}
	
// Selection
namespace nSet {
	enum Orientation {
		UP = 0,
		RIGHT,
		DOWN,
		LEFT
	};

	enum FuseMode {
		NO_FUSION = 0,
		ADD,
		SUB,
		INTERSECT
	};

	struct o_line {
		sf::VertexArray line;
		Orientation orient;
		int x;
		int y;
	};
	inline o_line oLine(sf::VertexArray line, Orientation orient, int x, int y) {
		o_line lc = {line, orient, x, y};
		return lc;
	}

	class OrientedLines  {
		private:
			sf::IntRect bounds;
			std::vector<o_line> lines;
			bool refresh_bounds = true;

			void calculateBounds() {
				if (lines.size() > 0) {
					int x_min = lines[0].x, y_min = lines[0].y, x_max = lines[0].x, y_max = lines[0].y;
					FOR_I (lines.size()) {
						if (lines[i].x < x_min) x_min = lines[i].x;
						else if (lines[i].x > x_max) x_max = lines[i].x;
						if (lines[i].y < y_min) y_min = lines[i].y;
						else if (lines[i].y > y_max) y_max = lines[i].y;
					}
					bounds = sf::IntRect(x_min, y_min, x_max-x_min+1, y_max-y_min+1);
					refresh_bounds = false;
				}
			}

		public:
			OrientedLines() {}
			~OrientedLines() {}
			
			inline void push_back(const o_line& l) { lines.push_back(l); }
			inline void clear() { lines.clear(); refresh_bounds = true; }
			inline unsigned int size() { return lines.size(); }
			inline std::vector<o_line>& getLines() { return lines; }
			inline sf::IntRect getBounds() { 
				if (refresh_bounds)
					calculateBounds();
				return bounds; 
			}

			void moveLines(sf::Vector2i move) {
				refresh_bounds = true; 
				FOR_I (lines.size()) {
					lines[i].x += move.x;
					lines[i].y += move.y;
					lines[i].line[0].position.x += move.x;
					lines[i].line[0].position.y += move.y;
					lines[i].line[1].position.x += move.x;
					lines[i].line[1].position.y += move.y;
				}
			}
	};

	struct positionned_olines {
		std::vector<o_line> lines;
		sf::Vector2f pos;
	};
	struct positionned_lines {
		std::vector<sf::VertexArray> lines;
		sf::Vector2f pos;
	};
}

// Tool
namespace nTol {
	enum tool_enum {
		CRAYON = 0,
		GOMME,
		AERO,
		POT,
		DEGRADE,
		RECTSELEC,
		BAGUETTE,
		SELECCOLOR,
		SNAP,
		CHEMIN,
		MOVE,
		GRAND,
		ROTATION,
		FLIP,
		ALIGN
	};

	struct range_type {
		int debutX;
		int finX;
		int Y;
	};

	inline bool isTransform(tool_enum t) {
		switch(t) {
			case MOVE:		return true;
			case GRAND:		return true;
			case ROTATION:	return true;
			case FLIP:		return true;
			default:		return false;
		}
	}
}