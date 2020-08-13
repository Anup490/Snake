#include "painter.h"

Painter::Painter(int maxInXAxis, int maxInYAxis) {
	this->maxInXAxis = maxInXAxis;
	this->maxInYAxis = maxInYAxis;
}

void Painter::paint(Direction direction) {
	system("cls");
	if (direction == Direction::PX) {
		paintInXAxis();
		spacesInX++;
	}
	else if (direction == Direction::NX) {
		paintInXAxis();
		spacesInX--;
	}
	else if (direction == Direction::PY) {
		paintInYAxis();
		spacesInY++;
	}
	else{
		paintInYAxis();
		spacesInY--;
	}
	previousDirection = direction;
}

void Painter::paintInXAxis() {
	changeSpacesInY();
	printEmptySpaces();
	for (int i = 0; i < spacesInX; i++) {
		cout << " ";
	}
	for (int i = 0; i < SNAKE_LENGTH; i++) {
		cout << "* ";
	}
}

void Painter::paintInYAxis() {
	changeSpacesInX();
	printEmptySpaces();
	for (int i = 0; i < SNAKE_LENGTH; i++) {
		for (int i = 0; i < spacesInX; i++) {
			cout << " ";
		}
		cout << "*" <<endl;
	}
}

void Painter::changeSpacesInX() {
	if (previousDirection == Direction::PX) {
		spacesInX += TURN_LENGTH;
	}
	else if (previousDirection == Direction::NX) {
		spacesInX -= TURN_LENGTH;
	}
}

void Painter::changeSpacesInY() {
	if (previousDirection == Direction::PY) {
		spacesInY += TURN_LENGTH;
	}
	else if (previousDirection == Direction::NY) {
		spacesInY -= TURN_LENGTH;
	}
}

void Painter::printEmptySpaces() {
	for (int i = 0; i < spacesInY; i++) {
		for (int i = 0; i < spacesInX; i++) {
			cout << " ";
		}
		cout << endl;
	}
}