#include "PVM.h"

void infoScreen() {
	system("cls");
	cout << endl << endl;
	cout << "���� ���" << endl << endl;
	cout << "              �̵� : ȭ��ǥ �� �� �� ��" << endl << endl;
	cout << "              ���� : ����" << endl << endl << endl;

	while (1) {
		if (keyControl() == SUBMIT) {
			break;
		}
	}
}