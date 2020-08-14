#pragma once

#include "abstractItem.h"

#define SNAKE_LENGTH 6

class SnakeItem : public AbstractItem{
	Points* pPoints;
	Point* pPoint;
	void initPoints();
public:
	SnakeItem();
	~SnakeItem();
	void onDraw();
	Points* getPoints();
};
