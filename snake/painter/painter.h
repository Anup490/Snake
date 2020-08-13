#include <iostream>
#define SNAKE_LENGTH 6
#define TURN_LENGTH SNAKE_LENGTH*2

using namespace std;

enum class Direction {
	PX,PY,NONE
};

class Painter {
	int spacesInX = 0;
	int spacesInY = 0;
	Direction previousDirection = Direction::PX;

	int maxInXAxis;
	int maxInYAxis;
	
	void paintInXAxis();
	void paintInYAxis();
public:
	Painter(int maxInXAxis,int maxInYAxis);
	void paint(Direction direction);
};




