#include "painter.h"

Painter::Painter(AbstractItem* pItems, int totalItems) {
	this->pItems = pItems;
	this->totalItems = totalItems;
}

void Painter::paint() {
	Row rows[MAX_Y_AXIS];
	initRows(rows);
	makeFrame(rows);
	system("cls");
	for (int i = 0; i < MAX_Y_AXIS; i++) {
		if (rows[i].size > 0 ) {
			for (int j = 0; j < rows[i].size; j++) {
				bool glow = *(rows[i].pPointFlags + j);
				(glow == true) ? cout << "*" : cout << " ";
			}
		}
		cout << endl;
	}
	for (int i = 0; i < totalItems; i++) {
		AbstractItem* pItem = pItems + i;
		pItem->onDraw();
	}
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
			/*for (int j = 0; j < 6; j++) {
				cout <<"(x = "<<(pPoint + j)->x << " , y = "<< (pPoint + j)->y<<") | ";
			}
			cout << endl;
			cout << endl;*/
			if (isWithinBounds(*pPoint)) {
				Row* pRow = pRows + (pPoint->y);		
				bool* pPointFlag = (pRow->pPointFlags) + (pPoint->x);
				*(pPointFlag) = true;
				if(((pPoint->x) + 1)>(pRow->size)) {
					pRow->size = (pPoint->x) + 1;
				}

			}
			
		}
	}
	//////////////DRAW FRAMES (FOR TEST ONLY)//////////
	/*for (int i = 0; i < MAX_Y_AXIS; i++) {
		for (int j = 0; j < MAX_X_AXIS; j++) {
			cout << *((pRows+i)->pPointFlags + j)<<" ";
		}
		cout << " | ROW SIZE = " << (pRows + i)->size;
		cout << endl;
	}
	cout << endl;
	cout << endl;*/
	///////////////////////////////////////////////////
}

bool Painter::isWithinBounds(Point point) {
	return (point.x < MAX_X_AXIS) && (point.y < MAX_Y_AXIS);
}