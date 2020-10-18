#pragma once

#include <cmath>
#include <ctime>
#include "AbstractItem.h"

class FoodItem : public AbstractItem{
	list<Point*>* pPoints;
	void initPoints();
	int getRandomPoint(int from, int to);
public:
	FoodItem();
	~FoodItem();
	void onDraw() override;
	list<Point*>* getPoints() override;
	void onCollision() override;
	int getPointsCount() override;
};