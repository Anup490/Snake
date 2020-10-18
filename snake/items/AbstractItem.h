#pragma once

#include <list>
#include "../constant/Constants.h"

using namespace std;

enum class Direction {
	PX, PY, NX, NY, NONE
};

struct Point{
	int x;
	int y;
};

class AbstractItem {
public:
	virtual void onDraw() = 0;
	virtual list<Point*>* getPoints() = 0;
	virtual void onCollision() = 0;
	virtual int getPointsCount() = 0;
};