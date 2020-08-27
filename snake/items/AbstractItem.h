#pragma once

#define MAX_X_AXIS 120
#define MAX_Y_AXIS 20

enum class Direction {
	PX, PY, NX, NY, NONE
};

struct Point{
	int x;
	int y;
	Direction direction;
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
	virtual Points* getPoints() = 0;
};