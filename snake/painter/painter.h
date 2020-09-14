#include <iostream>
#include <initializer_list>
#include "../items/abstractItem.h"

using namespace std;

struct Row
{
	bool* pPointFlags;
	int size = 0;
	Row() = default;

	Row(int boolSize) {
		this->pPointFlags = new bool[boolSize];
	}

	~Row() {
		delete[] pPointFlags;
	}
};

class Painter {
	initializer_list<AbstractItem*>* pItems;
	void initRows(Row* pRows);
	void makeFrame(Row* pRows);
	bool isWithinBounds(Point point);
	void drawFrame(Row* pRows, int& rTotalDotsDrawn);
	void notifyItems();
public:
	Painter(initializer_list<AbstractItem*> *pItems);
	int paint();
};




