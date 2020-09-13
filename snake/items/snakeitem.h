#pragma once

#include "abstractItem.h"

class SnakeItem : public AbstractItem{
	Direction direction;
	list<Point*>* pPoints;
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
};