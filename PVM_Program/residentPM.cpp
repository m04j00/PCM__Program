#include "main.h"
#include "pcmClass.h"

int afterLoginMain(const char* id) {
	system("cls");
	Resident resi;
	residentInit(id);
	getCarInfo(id, resi);
	while (1) {
		gotoxy(21, 4);
		cout << "아파트 주차 및 차량 관리 시스템";
		int menuCode = afterLoginMainMenu();
		if (menuCode == 0) {
			ParkingScreen(resi);
		}
		else if (menuCode == 1) {
			MgtScreen(resi);
		}
		else if (menuCode == 2) {
			return 0;
		}
		system("cls");
	}
	return 0;
}

Resident ParkingScreen(Resident &resi) {
	system("cls");
	cout << endl << endl << endl << endl;
	cout << "                          아파트 주차 관리 시스템                          " << endl << endl << endl;

	resi.parkingCheck();

	while (1) {
		if (keyControl() == SUBMIT) {
			break;
		}
	}
	return resi;
}

Resident MgtScreen(Resident& resi) {
	system("cls");
	cout << endl << endl << endl << endl;
	cout << "                          아파트 차량 관리 시스템                          " << endl << endl << endl;

	resi.getState();

	while (1) {
		if (keyControl() == SUBMIT) {
			break;
		}
	}
	return resi;
}

void residentInit(const char* id) {
	Resident resi;
	getCarInfo(id, resi);
}