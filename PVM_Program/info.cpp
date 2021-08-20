#include "PVM.h"

void infoScreen() {
	system("cls");
	cout << endl << endl;
	cout << "조작 방법" << endl << endl;
	cout << "              이동 : 화살표 ↑ ↓ ← →" << endl << endl;
	cout << "              선택 : 엔터" << endl << endl << endl;

	while (1) {
		if (keyControl() == SUBMIT) {
			break;
		}
	}
}