#include "painter.h"

Painter::Painter(int maxInXAxis, int maxInYAxis) {
	this->maxInXAxis = maxInXAxis;
	this->maxInYAxis = maxInYAxis;
}

void Painter::paint(Direction direction) {
	system("cls");
	if (direction == Direction::PX) {
		paintInXAxis();
	}
	else {
		paintInYAxis();
	}
	previousDirection = direction;
}

void Painter::paintInXAxis() {
	if (previousDirection == Direction::PY) {
		spacesInY += TURN_LENGTH;
	}
	for (int i = 0; i < spacesInX; i++) {	
		for (int i = 0; i < spacesInY; i++) {
			cout << " " << endl;
		}
		cout << " ";
	}
	for (int i = 0; i < SNAKE_LENGTH; i++) {
		for (int i = 0; i < spacesInY; i++) {
			cout << " " << endl;
		}
		cout << "* ";
	}
	spacesInX++;
}

void Painter::paintInYAxis() {
	if (previousDirection == Direction::PX) {
		spacesInX += TURN_LENGTH;
	}
	for (int i = 0; i < spacesInY; i++) {	
		for (int i = 0; i < spacesInX; i++) {
			cout << " ";
		}
		cout << " " <<endl;
	}
	for (int i = 0; i < SNAKE_LENGTH; i++) {
		for (int i = 0; i < spacesInX; i++) {
			cout << " ";
		}
		cout << "*" << endl;
	}
	spacesInY++; 
}
