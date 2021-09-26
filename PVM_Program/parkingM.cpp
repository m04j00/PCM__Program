#include "main.h"
#include "pmgt.h"

void parkingMgtScreen(const char*) {
	system("cls");
	pMgtTitle();
	cout << endl << endl;

	while (1) {
		if (keyControl() == SUBMIT) {
			break;
		}
	}
}

void pMgtTitle() {
	cout << endl << endl << endl << endl;
	cout << "                          아파트 주차 관리 시스템                          " << endl << endl << endl << endl;
}