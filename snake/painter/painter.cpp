#include "painter.h"

Painter::Painter(AbstractItem* pItems, int totalItems) {
	this->pItems = pItems;
	this->totalItems = totalItems;
}

void Painter::paint() {
	Row* pRows = new Row[MAX_Y_AXIS];
	initRows(pRows);
	makeFrame(pRows);
	system("cls");
	for (int i = 0; i < MAX_Y_AXIS; i++) {
		if (pRows[i].size > 0 ) {
			for (int j = 0; j < pRows[i].size; j++) {
				bool glow = *(pRows[i].pPointFlags + j);
				(glow == true) ? cout << "*" : cout << " ";
			}
		}
		cout << endl;
	}
	for (int i = 0; i < totalItems; i++) {
		AbstractItem* pItem = pItems + i;
		pItem->onDraw();
	}
	delete[] pRows;
}

void Painter::initRows(Row* pRows) {
	for (int i = 0; i < MAX_Y_AXIS; i++) {
		Row* pNewRow = new Row(MAX_X_AXIS);
		pRows[i] = *pNewRow;
	}
}

void Painter::makeFrame(Row* pRows) {
	for (int i = 0; i < totalItems; i++) {
		AbstractItem* pItem = pItems + i;
		Points* pPoints = pItem->getPoints();
		for (int j = 0; j < pPoints->noOfPoints; j++) {
			Point* pPoint = pPoints->pPointArray + j;
			if (isWithinBounds(*pPoint)) {
				Row* pRow = pRows + (pPoint->y);		
				bool* pPointFlag = (pRow->pPointFlags) + (pPoint->x);
				*(pPointFlag) = true;
				pRow->size = pPoint->x;
			}
		}
	}
}

bool Painter::isWithinBounds(Point point) {
	return (point.x < MAX_X_AXIS) && (point.y < MAX_Y_AXIS);
}

//void Painter::paint(Direction direction) {
//	system("cls");
//	if (direction == Direction::PX) {
//		paintInXAxis();
//		spacesInX++;
//	}
//	else if (direction == Direction::NX) {
//		paintInXAxis();
//		spacesInX--;
//	}
//	else if (direction == Direction::PY) {
//		paintInYAxis();
//		spacesInY++;
//	}
//	else{
//		paintInYAxis();
//		spacesInY--;
//	}
//	previousDirection = direction;
//}
//
//void Painter::paintInXAxis() {
//	changeSpacesInY();
//	printEmptySpaces();
//	for (int i = 0; i < spacesInX; i++) {
//		cout << " ";
//	}
//	for (int i = 0; i < SNAKE_LENGTH; i++) {
//		cout << "*";
//	}
//}
//
//void Painter::paintInYAxis() {
//	changeSpacesInX();
//	printEmptySpaces();
//	for (int i = 0; i < SNAKE_LENGTH; i++) {
//		for (int i = 0; i < spacesInX; i++) {
//			cout << " ";
//		}
//		cout << "*" <<endl;
//	}
//}
//
//void Painter::changeSpacesInX() {
//	if (previousDirection == Direction::PX) {
//		spacesInX += TURN_LENGTH_X;
//	}
//	else if (previousDirection == Direction::NX) {
//		spacesInX -= TURN_LENGTH_X;
//	}
//}
//
//void Painter::changeSpacesInY() {
//	if (previousDirection == Direction::PY) {
//		spacesInY += TURN_LENGTH_Y;
//	}
//	else if (previousDirection == Direction::NY) {
//		spacesInY -= TURN_LENGTH_Y;
//	}
//}
//
//void Painter::printEmptySpaces() {
//	for (int i = 0; i < spacesInY; i++) {
//		cout << endl;
//	}
//}