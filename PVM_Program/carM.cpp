#include "main.h"
#include "cmgt.h"
#include <cstring>  
//#include "airtight.h"
void secretPw(char *);

int adminScrenn() {
	return 0;
}
int carMgtScreen() {
	system("cls");

	while (1) {
		cout << endl << endl << endl << endl;
		cout << "                          ����Ʈ ���� ���� �ý���                          ";
		int menuCode = carMgtMenu();
		if (menuCode == 0) {
			adminLogin();
		}
		else if (menuCode == 1) {
			residentLogin();
		}
		else if (menuCode == 2) {
			return 0;
		}
		system("cls");
	}
	return 0;

}

int carMgtMenu() {
	int x = 32;
	int y = 7;
	gotoxy(x - 2, y);
	cout << "> ������  �α���";
	gotoxy(x, y + 1);
	cout << "���ֹ�  �α���";
	gotoxy(x, y + 2);
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
			if (y < 9) {
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
int adminLogin() {
	system("cls");
	char* id = (char*)malloc(sizeof(char) * 15);
	char* inputPw = (char*)malloc(sizeof(char) * 15);

	cout << endl << endl << endl << endl;
	//cout << "-------------------------------������ �α���-------------------------------" << endl << endl;
	cout << "                               ������ �α���                               " << endl << endl;
	//cout << "-------------------* ������ id�θ� �α����� �� �ֽ��ϴ�.-------------------" << endl;
	cout << "                  * ��ϵ� �����ڸ� �α����� �� �ֽ��ϴ�.                  " << endl << endl;

	cout << "                      I      D : ";
	cin >> id;
	cout << endl;
	cout << "                      ��й�ȣ : ";
	secretPw(inputPw);
	
	if(strcmp(id, "aaa") == 0 && strcmp(inputPw, "aaa") == 0){
		cout << endl << endl << endl;
		cout << "                      -- admin1�� �α��εǾ����ϴ� --                      ";
		Sleep(1000);
		return adminScreen();
	}
	else {
		system("cls");
		cout << endl << endl << endl << endl << endl << endl << endl << endl;
		cout << "                         ��ϵ� �����ڰ� �ƴմϴ�.                         ";
		Sleep(1000);
	}
	return 0;
}
void residentLogin() {
	init();
	system("cls");
	char* nBuilding = (char*)malloc(sizeof(char) * 4);
	char* nUnit = (char*)malloc(sizeof(char) * 4);
	char* inputPw = (char*)malloc(sizeof(char) * 8);
	cout << endl << endl << endl << endl;
	//cout << "-------------------------------������ �α���-------------------------------" << endl << endl;
	cout << "                               ���ֹ� �α���                               " << endl << endl;
	//cout << "-----------* �����ڸ� ���� ��ϵ� ���ֹθ� �α����� �� �ֽ��ϴ�.-----------" << endl;
	cout << "           * �����ڸ� ���� ��ϵ� ���ֹθ� �α����� �� �ֽ��ϴ�.           " << endl << endl;

	cout << "                      ��    �� : ";
	cin >> nBuilding;
	cout << endl;
	cout << "                      ȣ    �� : ";
	cin >> nUnit;
	cout << endl;
	cout << "                      ��й�ȣ : ";
	secretPw(inputPw);

	while (1) {
		if (keyControl() == SUBMIT) {
			return;
		}
	}
}

void secretPw(char *pw) {
	int i = 0;
	int buf = 0;
	for (i = 0; buf != 13; i++) {
		pw[i] = _getch();
		cout << "*";
		buf = (int)pw[i];
	}
	pw[i - 1] = '\0'; //������ ���� NULL ���ڷ� ġȯ
}