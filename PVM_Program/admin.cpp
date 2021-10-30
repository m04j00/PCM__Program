#include "main.h"
#include <cstring>  

int adminScreen() {
	system("cls");

	while (1) {
		cout << endl << endl << endl << endl;
		cout << "                                 ������ â                                 ";
		int menuCode = adminMenu();
		if (menuCode == 0) {
			system("cls");
			ResiMgtScreen();
			
		}
		else if (menuCode == 1) {
			system("cls");
			VisitingMgtScreen();
		}
		else if (menuCode == 2) {
			system("cls");
			AdminParkingLotScreen();
		}
		else if (menuCode == 3) {
			return 0;
		}
		system("cls");
	}
	return 0;

}
int ResiMgtScreen() {
	system("cls");

	while (1) {
		cout << endl << endl << endl << endl;
		cout << "                            ���ֹ� ���� ���� â                            ";
		int menuCode = ResidentMgtMenu();
		if (menuCode == 0) {
			carRegistration();
		}
		else if (menuCode == 1) {
			carDelReg();
		}
		else if (menuCode == 2) {
			ShowResidentList();
		}
		else if (menuCode == 3) {
			return 0;
		}
		system("cls");
	}
	return 0;

}
void VisitingMgtScreen() {
	system("cls");
	cout << endl << endl << endl << endl;
	cout << "                              �湮 ���� ��Ȳ                               " << endl << endl;
	cout << "                          * �ڷΰ��� : �����̽���                          " << endl << endl << endl;
	int num = VisitingList();
	if (num == 1) {
		cout << endl << endl;
		cout << "                        ������ �湮������ �����ϴ�.                        " << endl << endl;
	}
	while (1) {
		if (keyControl() == SUBMIT) {
			system("cls");
			return;
		}
	}
}
int carRegistration() {
	system("cls");
	char* carNum = (char*)malloc(sizeof(char) * 10);
	char* phoneNum = (char*)malloc(sizeof(char) * 20);
	int nBuilding;
	int nUnit;
	char* id = (char*)malloc(sizeof(char) * 12);
	char* password = (char*)malloc(sizeof(char) * 20);

	cout << endl << endl << endl << endl;
	cout << "                                 ���� ���                                 " << endl << endl << endl;
	cout << "               ���� ��ȣ : ";
	cin >> carNum;
	int isCar = SearchCarNum(carNum, 0);
	if (isCar == -1) {
		printf("\n%s                        �̹� ��ϵ� ������ȣ�Դϴ�.                         %s\n", RED, DEF);
		printf("                        ���� ȭ������ ���ư��ϴ�...                        ");
		Sleep(1500);
		return 0;
	}
	cout << "               ��ȭ ��ȣ : ";
	cin >> phoneNum;
	cout << "               ��     �� : ";
	cin >> nBuilding;
	cout << "               ȣ     �� : ";
	cin >> nUnit;
	cout << "               I       D : ";
	cin >> id;
	cout << "               ��� ��ȣ : ";
	cin >> password;
	cout << endl << endl;

	int isUser = SearchUserId(id);
	if (isUser == 0) {
		JoinUser(id, password);
		JoinCarInfo(id, carNum, phoneNum, nBuilding, nUnit);
		printf("%s                            ������ ��ϵǾ����ϴ�.                             %s\n\n", GREEN, DEF);
		cout << "                       ������ �����Ͻðڽ��ϱ�? Y / N                       " << endl;
		char YorN = '0';
		while (true) {
			gotoxy(0, 19);
			cout << "                                                 " << endl;
			gotoxy(0, 19);
			cout << "                       >> ";
			cin >> YorN;
			if (YorN == 'Y' || YorN == 'y') {
				cout << endl << "                    1�� �� ȭ���� �ڵ����� �̵��˴ϴ�...                    ";
				Sleep(1500);
				gotoParkingLot(carNum);
				return 0;
			}
			else if (YorN == 'N' || YorN == 'n') {
				break;
			}
		}
	}
	else printf("%s                          �̹� ��ϵ� ���̵��Դϴ�.                           %s", RED, DEF);
	
	cout << endl << endl;
	printf("                        ���� ȭ������ ���ư��ϴ�...                        ");
	Sleep(1500);

	system("cls");
	return 0;

}
int gotoParkingLot(char* car_num) {
	system("cls");
	char* parkingSpace = (char*)malloc(sizeof(char) * 10);
	int availableNum = parkingAvailableNum();
	cout << endl << endl << endl << endl;
	cout << "                                   ������                                  " << endl << endl;
	cout << "                         ���� ���� ���� ��Ȳ " << availableNum << " / 100" << endl;
	printf("              * %s�ʷϻ�%s : ���� ���� ����, %s������%s : ������ ����               \n\n", GREEN, DEF, RED, DEF);
	DrewParkingLot();
	while (true) {
		gotoxy(0, 40);
		cout << "                                                                                ";
		gotoxy(0, 42);
		cout << "                                                                                ";
		gotoxy(0, 40);
		cout << "                     ���� ������ �Է����ּ��� >> ";
		cin >> parkingSpace;
		int checkingParking = parkingLotState(1, parkingSpace, car_num, 0);
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
			ResidentState(1, parkingSpace, car_num);
			cout << "                              �����Ǿ����ϴ�.                              ";
			break;
		}
	}
	Sleep(1500);
	system("cls");
	return 0;
}
int carDelReg() {
	system("cls");
	char* carNum = (char*)malloc(sizeof(char) * 10);
	int selectBuilding = 0;
	int selectUnit = 0;
	string selectPhoneNum = "aaaaaa";

	cout << endl << endl << endl << endl;
	cout << "                               ���� ��� ����                              " << endl << endl << endl;
	cout << "                    ���� ��ȣ : ";
	cin >> carNum;
	cout << endl << endl;
	int carInfo = FindCarInfo(carNum);
	if (carInfo) {
		printf("%s                      ��ϵ��� ���� ������ȣ �Դϴ�.                       %s\n\n", RED, DEF);
		printf("                        ���� ȭ������ ���ư��ϴ�...                        ");
		Sleep(1500);
		return 0;
	}
	cout << endl << "---------------------------------------------------------------------------" << endl << endl;
	
	cout << "                     �ش� ������ �½��ϱ� ?     Y / N                      " << endl;
	char YorN = '0';
	while (true) {
		gotoxy(0, 17);
		cout << "                                             " << endl;
		gotoxy(0, 17);
		cout << "                     >> ";
		cin >> YorN;
		if (YorN == 'Y' || YorN == 'y') {
			char* inputId = (char*)malloc(sizeof(char) * 20);
			cout << endl;
			cout << "                     �Բ� ����� ���̵� �Է����ּ���                     " << endl;
			cout << "                     >> ";
			cin >> inputId;
			cout << endl << endl;
			int success = DeleteCarInfo(carNum, inputId);
			if (success == 0) {
				printf("%s                        ���������� �����Ǿ����ϴ�.                         %s", GREEN, DEF);
				cout << endl << endl << "                    1�� �� ȭ���� �ڵ����� �̵��˴ϴ�...                    ";
			}
			else {
				printf("%s           �Է��� ���̵�� ��ġ���� �ʾ� ������ ��� �Ǿ����ϴ�.           %s\n\n", RED, DEF);
				printf("                        ���� ȭ������ ���ư��ϴ�...                        ");
			}
			break;
		}
		else if (YorN == 'N' || YorN == 'n') {
			printf("%s                              ��ҵǾ����ϴ�.                              %s\n\n", RED, DEF);
			printf("                        ���� ȭ������ ���ư��ϴ�...                        ");
			break;
		}
	}
	Sleep(1500);
	system("cls");
	return 0;
}
void ShowResidentList() {
	system("cls");
	cout << endl << endl << endl << endl;
	cout << "                                 ���� ��ȸ                                 " << endl << endl;
	cout << "                          * �ڷΰ��� : �����̽���                          " << endl;
	cout << endl << endl;
	ResidentList();
	while (1) {
		if (keyControl() == SUBMIT) {
			system("cls");
			return;
		}
	}
}

void AdminParkingLotScreen() {
	cout << endl << endl << endl << endl;
	cout << "                                  �� �� ��                                  " << endl << endl << endl;
	int parkingPossible = parkingAvailableNum();
	cout << "                        ���� ���� ��Ȳ  |  " << parkingPossible << " / 100" << endl << endl;
	printf(" * %s�ʷϻ�%s : �� ����, %s������%s : ���ֹ� ���� ����, %sû��%s : �湮 ���� ���� ���� \n", GREEN, DEF, RED, DEF, BLUE, DEF);
	cout << "                          * �ڷΰ��� : �����̽���                          " << endl;
	cout << endl << endl;
	drewParkingLotToCarNum(1, NULL);

	while (1) {
		if (keyControl() == SUBMIT) {
			system("cls");
			return;
		}
	}
} 