#pragma once

#include <cmath>
#include <ctime>
#include "abstractItem.h"

class FoodItem : public AbstractItem{
	list<Point*>* pPoints;
	void initPoints();
	int getRandomPoint(int from, int to);
public:
	FoodItem();
	~FoodItem();
	void onDraw() override;
	list<Point*>* getPoints() override;
};