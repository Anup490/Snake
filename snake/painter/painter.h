#include <iostream>
#include "../items/abstractItem.h"
#include <list>
#define SNAKE_LENGTH 6

#define TURN_LENGTH_X SNAKE_LENGTH
#define TURN_LENGTH_Y SNAKE_LENGTH

#define MAX_X_AXIS 20
#define MAX_Y_AXIS 10

using namespace std;

enum class Direction {
	PX,PY,NX,NY,NONE
};

struct Row
{
	bool* pPointFlags;
	int size;
};

class Painter {
	AbstractItem* pItems;
	int totalItems;
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




