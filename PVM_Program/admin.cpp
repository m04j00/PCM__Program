#include "main.h"
#include "cmgt.h"
#include <cstring>  

int adminScreen() {
	system("cls");

	while (1) {
		cout << endl << endl << endl << endl;
		//cout << "---------------------------------������ â---------------------------------";
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
			parkingLotScreen();
		}
		else if (menuCode == 3) {
			return 0;
		}
		system("cls");
	}
	return 0;

}
int adminMenu() {
	int x = 31;
	int y = 7;
	gotoxy(x - 2, y);
	cout << "> ���ֹ� ���� ����";
	gotoxy(x, y + 1);
	cout << "�湮  ����  ����";
	gotoxy(x, y + 2);
	cout << "�� �� ��   �� ��";
	gotoxy(x, y + 3);
	cout << "��  ��    ��  ��";

	while (1) {
		int num = keyControl();
		switch (num) {
		case UP: {
			if (y > 7) {
				gotoxy(x - 2, y);
				cout << " ";
				gotoxy(x - 2, --y);
				cout << ">";
			}
			break;
		}
		case DOWN: {
			if (y < 10) {
				gotoxy(x - 2, y);
				cout << " ";
				gotoxy(x - 2, ++y);
				cout << ">";
			}
			break;
		}
		case SUBMIT: {
			return y - 7;
		}
		}
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
int ResidentMgtMenu() {
	int x = 31;
	int y = 7;
	gotoxy(x - 2, y);
	cout << "> ��  ��  ��  ��";
	gotoxy(x, y + 1);
	cout << "���� ��� ����";
	gotoxy(x, y + 2);
	cout << "��  ��  ��  ȸ";
	gotoxy(x, y + 3);
	cout << "��  ��  ��  ��";

	while (1) {
		int num = keyControl();
		switch (num) {
		case UP: {
			if (y > 7) {
				gotoxy(x - 2, y);
				cout << " ";
				gotoxy(x - 2, --y);
				cout << ">";
			}
			break;
		}
		case DOWN: {
			if (y < 10) {
				gotoxy(x - 2, y);
				cout << " ";
				gotoxy(x - 2, ++y);
				cout << ">";
			}
			break;
		}
		case SUBMIT: {
			return y - 7;
		}
		}
	}
	return 0;
}
void VisitingMgtScreen() {
	system("cls");
	cout << endl << endl << endl << endl;
	cout << "                              �湮 ���� ��Ȳ                               " << endl << endl << endl;
	int num = VisitingList();
	if (num == 1)
		cout << endl << endl <<  "                     ������ �湮������ �����ϴ�." << endl << endl;
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
	int isCar = SearchCarNum(carNum);
	if (isCar == -1) {
		printf("\n%s                        �̹� ��ϵ� ������ȣ�Դϴ�.                         %s\n", RED, DEF);
		printf("                        ���� ȭ������ ���ư��ϴ�...                        ");
		Sleep(1500);
		return 0;
	}
	cout << "               ��ȭ ��ȣ : ";
	cin >> phoneNum;
	cout << "               �� �� : ";
	cin >> nBuilding;
	cout << "               ȣ �� : ";
	cin >> nUnit;
	cout << "               ���̵� : ";
	cin >> id;
	cout << "               ��� ��ȣ : ";
	cin >> password;
	cout << endl << endl;

	int isUser = SearchUserId(id);
	if (isUser == 0) {
		JoinUser(id, password);
		JoinCarInfo(id, carNum, phoneNum, nBuilding, nUnit);
		printf("%s                                ��ϵǾ����ϴ�.                                %s", GREEN, DEF);
	}
	else printf("%s                          �̹� ��ϵ� ���̵��Դϴ�.                           %s", RED, DEF);
		
	Sleep(1000);
	while (1) {
		if (keyControl() == SUBMIT) {
			system("cls");
			return 0;
		}
	}
	system("cls");
	return 0;

}

int carDelReg() {
	system("cls");
	char* carNum = (char*)malloc(sizeof(char) * 10);
	int selectBuilding = 0;
	int selectUnit = 0;
	string selectPhoneNum = "aaaaaa";
	char YorN = '0';

	cout << endl << endl << endl << endl;
	cout << "                               ���� ��� ����                              " << endl << endl;
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
	

	cout << "                       �ش� ������ �½��ϱ� ? Y / N                        " << endl;
	cout << "                       >> ";
	cin >> YorN;
	cout << endl;
	if (YorN == 'Y' || YorN == 'y') {
		char* inputId = (char*)malloc(sizeof(char) * 20);
		cout << "                     �Բ� ����� ���̵� �Է����ּ���                     " << endl;
		cout << "                     >> ";
		cin >> inputId;
		cout << endl << endl;
		int success = DeleteCarInfo(carNum, inputId);
		if (success == 0)
			printf("%s                        ���������� �����Ǿ����ϴ�.                         %s", GREEN, DEF);
		else {
			printf("%s           �Է��� ���̵�� ��ġ���� �ʾ� ������ ��� �Ǿ����ϴ�.           %s\n\n", RED, DEF);
			printf("                        ���� ȭ������ ���ư��ϴ�...                        ");
			Sleep(1500);
			return 0;
		}
	}
	//"                     �Բ� ����� ���̵� �Է����ּ���                     "
	else	
		printf("%s                              ��ҵǾ����ϴ�.                              %s\n\n", RED, DEF);
	Sleep(1000);
	while (1) {
		if (keyControl() == SUBMIT) {
			system("cls");
			return 0 ;
		}
	}
	system("cls");
	return 0;
}
void ShowResidentList() {
	system("cls");
	cout << endl << endl;
	cout << "                                 ���� ��ȸ                                 " << endl;
	cout << endl << endl;
	ResidentList();
	while (1) {
		if (keyControl() == SUBMIT) {
			system("cls");
			return;
		}
	}
}

void parkingLotScreen() {
	cout << endl << endl << endl << endl;
	cout << "                                  �� �� ��                                  " << endl << endl << endl;
	int parkingPossible = parkingAvailableNum();
	cout << "                        ���� ���� ��Ȳ  |  " << parkingPossible << " / 100" << endl << endl;
	printf(" * %s�ʷϻ�%s : �� ����, %s������%s : ���ֹ� ���� ����, %sû��%s : �湮 ���� ���� ���� \n", GREEN, DEF, RED, DEF, BLUE, DEF);
	cout << "                          * �ڷΰ��� : �����̽���                          " << endl;
	cout << endl << endl;
	drewParkingLotToCarNum();

	while (1) {
		if (keyControl() == SUBMIT) {
			system("cls");
			return;
		}
	}
} 