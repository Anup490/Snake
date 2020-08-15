#include <iostream>
#include "../items/abstractItem.h"
#include <list>

#define TURN_LENGTH_X SNAKE_LENGTH
#define TURN_LENGTH_Y SNAKE_LENGTH

using namespace std;

enum class Direction {
	PX,PY,NX,NY,NONE
};

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

	//int spacesInX = 0;
	//int spacesInY = 0;
	//Direction previousDirection = Direction::PX;
	//void paintInXAxis();
	//void paintInYAxis();
	//void changeSpacesInX();
	//void changeSpacesInY();
	//void printEmptySpaces();
public:
	Painter(AbstractItem* pItems, int totalItems);
	void paint();
	
	
	//void paint(Direction direction);
};




