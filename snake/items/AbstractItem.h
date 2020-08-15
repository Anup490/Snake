#pragma once

#define MAX_X_AXIS 20
#define MAX_Y_AXIS 10

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
	virtual Points* getPoints() = 0;
};