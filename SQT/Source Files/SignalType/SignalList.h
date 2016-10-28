#pragma once

#include "stdenum.h"
#include "Source Files/SignalType/SignalListObject.h"

class SignalList : public QObject
{
	Q_OBJECT
// CONSTRUCTOR
public:
	SignalList() {}
	~SignalList() {}

// METHODS
public:
	const std::vector<SignalListObject*>& getList() const { return vector; }
	template <typename T=SignalListObject*> T at(int i) const { return static_cast<T>(vector[i]); }
	template <typename T=SignalListObject*> T &operator[](int i) const { return static_cast<T>(vector[i]); }
	
	void push_back(SignalListObject& obj);
	void moveElement(int src, int dst);
	void selectOne(SignalListObject& obj);
	void dropSelected();
	void clear();

	int size() const { return vector.size(); }
	std::vector<SignalListObject*>::const_iterator begin() const { return vector.begin(); }
	std::vector<SignalListObject*>::const_iterator end() const { return vector.end(); }
	SignalListObject& front() const { return *vector.front(); }
	SignalListObject& back() const { return *vector.back(); }

private:
	void erase(std::vector<SignalListObject*>::const_iterator i);
	void insert(std::vector<SignalListObject*>::const_iterator at, SignalListObject& to_add);

// SIGNALS / SLOTS
	public slots:
		void remove(const SignalListObject& object);
	signals:
		void created(SignalListObject& object) const;

// MEMBERS
private:
	std::vector<SignalListObject*> vector;
};
