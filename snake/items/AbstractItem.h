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

struct Points {
	Point* pPointArray;
	int noOfPoints = 0;

	Points(int size) {
		this->pPointArray = new Point[size];
		this->noOfPoints = size;
	}

	~Points() {
		delete[] pPointArray;
	}
};

class AbstractItem {
public:
	virtual void onDraw() = 0;
	virtual vector<Point*>* getPoints() = 0;
};