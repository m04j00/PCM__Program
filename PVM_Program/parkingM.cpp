#include "PVM.h"
#include "pmgt.h"

void parkingMgtScreen() {
	system("cls");
	pMgtTitle();
	while (1) {
		if (keyControl() == SUBMIT) {
			break;
		}
	}
}

void pMgtTitle() {
	gotoxy(21, 4);
	cout << "����Ʈ ���� ���� �ý���";
}
