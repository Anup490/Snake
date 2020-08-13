#include <iostream>
#define SNAKE_LENGTH 6
#define TURN_LENGTH_X SNAKE_LENGTH*2
#define TURN_LENGTH_Y SNAKE_LENGTH

using namespace std;

enum class Direction {
	PX,PY,NX,NY,NONE
};

class Painter {
	int spacesInX = 0;
	int spacesInY = 0;
	Direction previousDirection = Direction::PX;

	int maxInXAxis;
	int maxInYAxis;
	
	void paintInXAxis();
	void paintInYAxis();
	void changeSpacesInX();
	void changeSpacesInY();
	void printEmptySpaces();
public:
	Painter(int maxInXAxis,int maxInYAxis);
	void paint(Direction direction);
};




