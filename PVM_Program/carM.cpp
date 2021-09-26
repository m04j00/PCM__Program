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
		cout << "                          아파트 차량 관리 시스템                          ";
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
	cout << "> 관리자  로그인";
	gotoxy(x, y + 1);
	cout << "입주민  로그인";
	gotoxy(x, y + 2);
	cout << "뒤  로  가  기";

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
	//cout << "-------------------------------관리자 로그인-------------------------------" << endl << endl;
	cout << "                               관리자 로그인                               " << endl << endl;
	//cout << "-------------------* 관리자 id로만 로그인할 수 있습니다.-------------------" << endl;
	cout << "                  * 등록된 관리자만 로그인할 수 있습니다.                  " << endl << endl;

	cout << "                      I      D : ";
	cin >> id;
	cout << endl;
	cout << "                      비밀번호 : ";
	secretPw(inputPw);
	
	if(strcmp(id, "aaa") == 0 && strcmp(inputPw, "aaa") == 0){
		cout << endl << endl << endl;
		cout << "                      -- admin1로 로그인되었습니다 --                      ";
		Sleep(1000);
		return adminScreen();
	}
	else {
		system("cls");
		cout << endl << endl << endl << endl << endl << endl << endl << endl;
		cout << "                         등록된 관리자가 아닙니다.                         ";
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
	//cout << "-------------------------------관리자 로그인-------------------------------" << endl << endl;
	cout << "                               입주민 로그인                               " << endl << endl;
	//cout << "-----------* 관리자를 통해 등록된 입주민만 로그인할 수 있습니다.-----------" << endl;
	cout << "           * 관리자를 통해 등록된 입주민만 로그인할 수 있습니다.           " << endl << endl;

	cout << "                      동    수 : ";
	cin >> nBuilding;
	cout << endl;
	cout << "                      호    수 : ";
	cin >> nUnit;
	cout << endl;
	cout << "                      비밀번호 : ";
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
	pw[i - 1] = '\0'; //마지막 문자 NULL 문자로 치환
}