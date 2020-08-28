#include <iostream>
#include "../items/abstractItem.h"

using namespace std;

struct Row
{
	bool* pPointFlags;
	int size = 0;
	Row(){}

	Row(int boolSize) {
		this->pPointFlags = new bool[boolSize];
	}

	~Row() {
		delete[] pPointFlags;
	}
};

class Painter {
	AbstractItem* pItems;
	int totalItems;
	void initRows(Row* pRows);
	void makeFrame(Row* pRows);
	bool isWithinBounds(Point point);
	void drawFrame(Row* pRows, int* pTotalDotsDrawn);
	void notifyItems();
public:
	Painter(AbstractItem* pItems, int totalItems);
	int paint();
};




