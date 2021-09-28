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

int adminMenu() {
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

	int joinInfo = JoinCarInfo(id, carNum, phoneNum, nBuilding, nUnit);
	int Join = JoinUser(id, password);
	if(joinInfo == 0 && Join == 0)
		cout << "                        ���� ����� �Ϸ�Ǿ����ϴ�.                        ";
		
	else 
		cout << "                 �̹� ��ϵ� ���̵��̰ų� ������ȣ�Դϴ�.                  ";
	Sleep(3000);
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
	cout << endl;
	int carInfo = FindCarInfo(carNum);
	if (carInfo) {
		cout << "                      ��ϵ��� ���� ������ȣ �Դϴ�.                       " << endl;
		Sleep(1000);
		return 0;
	}
	cout << endl << "---------------------------------------------------------------------------" << endl << endl;
	

	cout << "                       �ش� ������ �½��ϱ� ? Y / N                        " << endl;
	cout << "                       >> ";
	cin >> YorN;
	cout << endl;
	if (YorN == 'Y' || YorN == 'y') {
		DeleteCarInfo(carNum);
		cout << "                        ���������� �����Ǿ����ϴ�.                         " << endl;
	}
	else	
		cout << "                              ��ҵǾ����ϴ�.                              " << endl;
	Sleep(1000);
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