#include "main.h"
int main() {
	init();
	while (1) {
		mainTitle();
		int menuCode = mainMenu();
		if (menuCode == 0) {
			parkingLotScreen();
		}
		else if (menuCode == 1) {
			login();
			
		}
		else if (menuCode == 2) {
			isVisitant();
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
	cout << "                                  �� �� ��                                  " << endl;
	int parkingPossible = parkingAvailableNum();
	cout << "                        ���� ���� ��Ȳ  |  " << parkingPossible << " / 100" << endl << endl;
	printf("                   * %s�ʷϻ�%s : �� ����, %s������%s : ���� ����                   ", GREEN, DEF, RED, DEF);
	cout << "                          * �ڷΰ��� : �����̽���                          " << endl << endl;
	drewParkingLotToCarNum(0, NULL);

	while (1) {
		if (keyControl() == SUBMIT) {
			system("cls");
			return;
		}
	}
}