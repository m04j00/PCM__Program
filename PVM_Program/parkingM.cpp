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
	cout << "                          ����Ʈ ���� ���� �ý���                          " << endl << endl << endl << endl;
}