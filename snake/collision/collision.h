#pragma once
#include <exception>
#include <initializer_list>
#include "../items/AbstractItem.h"
using namespace std;

struct CollisionException : exception {
	const char* what() const override;
};

class Collision {
	initializer_list<AbstractItem*>* pItems;
	int totalDots;
	void setTotalDots();
	bool hasOverlapped(Point snakePoint, Point foodPoint);
public:
	Collision(initializer_list<AbstractItem*>* pItems);
	void checkCollision(int dotsDrawn) throw(CollisionException);
};