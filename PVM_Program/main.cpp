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
	cout << "                                  주 차 장                                  " << endl << endl << endl;
	int parkingPossible = parkingAvailableNum();
	cout << "                        주차 구역 현황  |  " << parkingPossible << " / 100" << endl << endl;
	printf("                   * %s초록색%s : 빈 구역, %s붉은색%s : 주차 상태                   \n", GREEN, DEF, RED, DEF);
	cout << "                          * 뒤로가기 : 스페이스바                          " << endl;
	cout << endl << endl;
	drewParkingLotToCarNum(0);

	while (1) {
		if (keyControl() == SUBMIT) {
			system("cls");
			return;
		}
	}
}