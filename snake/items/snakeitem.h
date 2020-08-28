#pragma once

#include "abstractItem.h"

class SnakeItem : public AbstractItem{
	Direction direction;
	Points* pPoints;
	void initPoints();
	void shiftHead(Point* pHead);
	void shiftBody(Point prevHead);
	Direction toOrientation(char inputChar);
public:
	SnakeItem();
	~SnakeItem();
	void onDraw();
	void onInput(char inputChar);
	Points* getPoints();
};