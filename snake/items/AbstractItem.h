#pragma once

#include <vector>
#include "../constant/constants.h"

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
	virtual vector<Point*>* getPoints() = 0;
};