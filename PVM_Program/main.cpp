#include "main.h"
int main() {
	init();
	while (1) {
		mainTitle();
		int menuCode = mainMenu();
		if (menuCode == 0) {
			login();
		}
		else if (menuCode == 1) {
			isVisitant();
		}
		else if (menuCode == 2) {
			parkingLotScreen();
		}
		else if (menuCode == 3) {
			infoScreen();
		}
		else if (menuCode == 4) {
			return 0;
		}
		system("cls");
	}
	return 0;
}

void parkingLotScreen() {
	system("cls");
	cout << endl << endl << endl << endl;
	cout << "                                  �� �� ��                                  " << endl << endl << endl;
	int parkingPossible = parkingAvailableNum();
	cout << "                        ���� ���� ��Ȳ  |  " << parkingPossible << " / 100" << endl << endl;
	printf("                   * %s�ʷϻ�%s : �� ����, %s������%s : ���� ����                   \n", GREEN, DEF, RED, DEF);
	cout << "                          * �ڷΰ��� : �����̽���                          " << endl;
	cout << endl << endl;
	drewParkingLotToCarNum(0);

	while (1) {
		if (keyControl() == SUBMIT) {
			system("cls");
			return;
		}
	}
}