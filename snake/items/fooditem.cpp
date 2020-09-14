#include "fooditem.h"

FoodItem::FoodItem() {
	this->pPoints = new list<Point*>;
	initPoints();
}

FoodItem::~FoodItem() {
	for (auto pPointsIterator = pPoints->begin(); pPointsIterator != pPoints->end(); pPointsIterator++) {
		Point* pPoint = *pPointsIterator;
		delete pPoint;
	}
	delete pPoints;
}

void FoodItem::onDraw() {}

list<Point*>* FoodItem::getPoints() {
	return pPoints;
}

void FoodItem::initPoints() {
	Point* pPoint = new Point;
	pPoint->x = getRandomPoint(0, MAX_X_AXIS);
	pPoint->y = getRandomPoint(0, MAX_Y_AXIS);
	pPoints->push_back(pPoint);
}

int FoodItem::getRandomPoint(int from, int to) {
	if (from > to) {
		int temp = from;
		from = to;
		to = temp;
	}
	int mid_value = (from + to) / 2;
	srand((unsigned)time(NULL));
	int calc_rand = rand() % to;
	if ((calc_rand >= from) && (calc_rand <= to)) {
		return calc_rand;
	}
	else if (calc_rand <= mid_value) {
		return (calc_rand + from);
	}
	else {
		return (calc_rand - from);
	}
}