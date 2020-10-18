#pragma once

#include "AbstractItem.h"

class SnakeItem : public AbstractItem{
	Direction direction;
	list<Point*>* pPoints;
	Point* pNewTail;
	int snakeLength;
	void initPoints();
	void shiftHead(Point* pHead);
	void shiftBody(Point prevHead);
	Direction toOrientation(char inputChar);
public:
	SnakeItem();
	~SnakeItem();
	void onDraw() override;
	void onInput(char inputChar);
	list<Point*>* getPoints() override;
	void onCollision() override;
	int getPointsCount() override;
};