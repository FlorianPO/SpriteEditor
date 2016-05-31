#pragma once

#include "stdafx.h"

#define INIT_COPY_CONTROLLER CopyController::createInstance();

#define COPY_CONTROLLER CopyController::getInstance()
#define COPY_LIST CopyController::getInstance()->getCopyList()
#define COPY CopyController::getInstance()->getCurrentCopy()

class CCopy; //Forward declaration

class CopyController : public QObject
{
	Q_OBJECT
// INSTANCE
private:	static CopyController* _t; 
public:		inline static void createInstance() { _t = new CopyController(); }
			inline static CopyController* getInstance() { return _t; }

// CONSTRUCTOR
	CopyController() {}
	~CopyController() {}

// METHODS
	inline CCopy* getCurrentCopy() { return current_copy; }
	inline const std::vector<CCopy*>& getLayerList() { return copy_list; }

// SIGNALS SLOTS
	public slots:
		void new_copy(const sf::Image& image);
		void _copyCreated(CCopy*);
		void _copyApplied(CCopy*);
		void _copyTransformed(CCopy*);
	signals:
		void copyCreated(CCopy*);
		void copyApplied(CCopy*);
		void copyTransformed(CCopy*);

// MEMBERS
private:
	CCopy* current_copy;
	std::vector<CCopy*> copy_list;
	sf::Vector2f last_pos_copy;
};

