#include "Fooditem.h"
#include "../constant/Constants.h"
#include <list>
#include <cmath>
#include <ctime>

FoodItem::FoodItem() 
{
	this->pPoints = new list<Point*>;
	InitPoints();
}

FoodItem::~FoodItem() 
{
	for (auto pPointsIterator = pPoints->begin(); pPointsIterator != pPoints->end(); pPointsIterator++) 
	{
		Point* pPoint = *pPointsIterator;
		delete pPoint;
	}
	delete pPoints;
}

void FoodItem::OnDraw() {}

list<Point*>* FoodItem::GetPoints() 
{
	return pPoints;
}

void FoodItem::OnCollision() 
{
	Point* pPoint = *(pPoints->begin());
	pPoint->x = GetRandomPoint(0, MAX_X_AXIS);
	pPoint->y = GetRandomPoint(0, MAX_Y_AXIS);
}

int FoodItem::GetPointsCount() 
{
	return 1;
}

void FoodItem::InitPoints() 
{
	Point* pPoint = new Point;
	pPoint->x = GetRandomPoint(0, MAX_X_AXIS);
	pPoint->y = GetRandomPoint(0, MAX_Y_AXIS);
	pPoints->push_back(pPoint);
}

int FoodItem::GetRandomPoint(int from, int to) 
{
	SetFromAndToProperly(from, to);
	srand((unsigned)time(NULL));
	return GetClampedValue(from, to, rand() % to, (from + to) / 2);
}

void FoodItem::SetFromAndToProperly(int& from, int& to)
{
	if (from > to)
	{
		int temp = from;
		from = to;
		to = temp;
	}	
}

int FoodItem::GetClampedValue(int& from, int& to, int rand, int midVal)
{
	if ((rand >= from) && (rand <= to))
	{
		return rand;
	}
	else if (rand <= midVal)
	{
		return (rand + from);
	}
	else
	{
		return (rand - from);
	}
}