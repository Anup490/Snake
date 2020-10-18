#pragma once
#include "AbstractItem.h"

class FoodItem : public AbstractItem
{
	list<Point*>* pPoints;
	void InitPoints();
	int GetRandomPoint(int from, int to);
	void SetFromAndToProperly(int& from, int& to);
	int GetClampedValue(int& from, int& to, int rand, int midVal);
public:
	FoodItem();
	~FoodItem();
	void OnDraw() override;
	list<Point*>* GetPoints() override;
	void OnCollision() override;
	int GetPointsCount() override;
};