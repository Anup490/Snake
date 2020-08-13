#include "painter.h"

void Painter::paint(int spaces) {
	system("cls");
	for (int i = 0; i < spaces;i++) {
		cout << " ";
	}
	cout << "******";
}
