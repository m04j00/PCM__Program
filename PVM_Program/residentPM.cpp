#include "main.h"

int afterLoginMain(const char* id) {
	system("cls");
	Resident resi;
	residentInit(id);
	getCarInfo(id, resi);
	cout << resi.getNum() << endl;
	cout << resi.getSpace() << endl;
	while (1) {
		gotoxy(21, 4);
		cout << "����Ʈ ���� �� ���� ���� �ý���";
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
	cout << "                          ����Ʈ ���� ���� �ý���                          " << endl << endl << endl;

	int num = resi.parkingCheck(); // ���� 1, ���� 0
	while (1) {
		if (num == 1) {
			int parkingAvailNum = parkingAvailableNum();
			cout << endl << endl << "                         ���������� ���� " << parkingAvailNum << " / 100" << endl << endl << endl;
			if (parkingAvailNum == 0) {
				printf("%s   ���������� ������ �����ϴ�. �湮 ������ ������� ������ ��û�մϴ�...   \n\n", RED);
				Sleep(1500);
				delParkingLot(1);
				parkingAvailNum = parkingAvailableNum();
				if (parkingAvailNum == 0) {
					printf("     ���������� ������ ã�� ���߽��ϴ�. �����ڿ��� ���� �������ּ���.      %s\n", DEF);
					resi.setState(0);
					cout << endl << endl << "                         ���������� ���� " << parkingAvailNum << " / 100" << endl;
					Sleep(1500);
					break;
				}
				printf("                       ���������� ������ ã�ҽ��ϴ�!                      %s\n", DEF);
				cout << endl << endl << "                         ���������� ���� " << parkingAvailNum << " / 100" << endl;
				while (1) {
					if (keyControl() == SUBMIT) {
						break;
					}
					system("cls");
				}
			}
			Sleep(1000);
			gotoParkingLot(resi, parkingAvailNum);
			break;
		}
		else if (num == 0) {
			parkingLotState(0, resi.getSpace(), "NULL");
			ResidentState(0, "NULL", resi.getNum());
			int parkingAvailNum = parkingAvailableNum();
			cout << endl << endl << "                         ���������� ���� " << parkingAvailNum << " / 100" << endl;
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
	cout << "                                   ������                                  " <<  endl << endl;
	cout << "                         ���� ���� ���� ��Ȳ " << availableNum << " / 100" << endl << endl;
	DrewParkingLot(NULL);
	while (true) {
		gotoxy(0, 40);
		cout << "                                                                                ";
		gotoxy(0, 42);
		cout << "                                                                                ";
		gotoxy(0, 40);
		cout << "                     ���� ������ �Է����ּ��� >> ";
		cin >> parkingSpace;
		int checkingParking = parkingLotState(1, parkingSpace, resi.getNum());
		gotoxy(0, 42);
		if (checkingParking == -1) {
			printf("%s        ���� ������ �߸� �Է��߽��ϴ�. �ٽ� �Է����ּ���.%s", RED, DEF);
			Sleep(1500);
		}
		else if (checkingParking == 1) {
			printf("%s        �̹� ������ �����Դϴ�. �ٽ� �Է����ּ���.%s", RED, DEF);
			Sleep(1500);
		}
		else if (checkingParking == 0) {
			resi.setSpace(parkingSpace);
			cout << "                              �����Ǿ����ϴ�.                              ";
			ResidentState(1, resi.getSpace(), resi.getNum());
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
	cout << "                          ����Ʈ ���� ���� �ý���                          " << endl << endl << endl;

	int state = resi.getState();
	if (state == 1) {
		cout << "                              ���� ��ġ : " << resi.getSpace() << endl;
	}
	DrewParkingLot(resi.getNum());
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