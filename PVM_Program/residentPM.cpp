#include "main.h"

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
	

	int num = resi.parkingCheck(); // 입차 1, 출차 2
	while (1) {
		if (num == 1) {
			int parkingAvailNum = parkingAvailableNum();
			cout << endl << endl << "                          주차 가능 개수 " << parkingAvailNum << " / 100" << endl;
			Sleep(1000);
			gotoParkingLot(resi, parkingAvailNum);
			break;
		}
		else if (num == 2) {
			int whatNum = parkingLotState(0, resi.getSpace(), NULL);
			cout << whatNum << endl;
			int parkingAvailNum = parkingAvailableNum();
			cout << endl << endl << "                     주차 가능 구역 현황 " << parkingAvailNum << " / 100" << endl;
			Sleep(1500);
			break;
		}
		else if (keyControl() == SUBMIT) {
			break;
		}
		system("cls");
	}
	return resi;
}
Resident gotoParkingLot(Resident& resi, int availableNum) {
	system("cls");
	char* parkingSpace = (char*)malloc(sizeof(char) * 10);
	cout << endl << endl << endl << endl;
	cout << "                                   주차장                                  " <<  endl << endl;
	cout << "                     주차 가능 구역 현황 " << availableNum << " / 100" << endl << endl;
	DrewParkingLot();
	while (true) {
		gotoxy(0, 40);
		cout << "                                                                                ";
		gotoxy(0, 42);
		cout << "                                                                                ";
		gotoxy(0, 40);
		cout << "           주차 구역을 입력해주세요 >> ";
		cin >> parkingSpace;
		int checkingParking = parkingLotState(1, parkingSpace, resi.getNum());
		gotoxy(0, 42);
		if (checkingParking == -1) {
			printf("%s        주차 구역을 잘못 입력했습니다. 다시 입력해주세요.%s", RED, DEF);
			Sleep(1500);
		}
		else if (checkingParking == 1) {
			printf("%s        이미 주차된 구역입니다. 다시 입력해주세요.%s", RED, DEF);
			Sleep(1500);
		}
		else if (checkingParking == 0) {
			resi.setSpace(parkingSpace);
			cout << "            주차되었습니다.";
			break;
		}
	}
	while (1) {
		if (keyControl() == SUBMIT) {
			break;
		}
		system("cls");
	}
	return resi;
}
Resident MgtScreen(Resident& resi) {
	system("cls");
	cout << endl << endl << endl << endl;
	cout << "                          아파트 차량 관리 시스템                          " << endl << endl << endl;

	int state = resi.getState();
	if (state == 1) {
		cout << "                              주차 위치 : " << resi.getSpace() << endl;
	}
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