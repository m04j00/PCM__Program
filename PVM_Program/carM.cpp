#include "main.h"
#include "cmgt.h"
#include <cstring>  
//#include "airtight.h"
#define ADMINID admin07
#define adminPW admin0702

int carMgtScreen() {
	system("cls");

	while (1) {
		cout << endl << endl << endl << endl;
		cout << "                           아파트 차량 관리 시스템";
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
int adminLogin() { return 0; }
int main() {
	init();
	system("cls");
	char* id = (char*)malloc(sizeof(char) * 100);
	char* inputPw = (char*)malloc(sizeof(char) * 100);
	int buffer = 0;
	int i = 0;

	cout << endl << endl << endl << endl;
	//cout << "-------------------------------관리자 로그인-------------------------------" << endl << endl;
	cout << "                               관리자 로그인                               " << endl << endl;
	//cout << "-------------------* 관리자 id로만 로그인할 수 있습니다.-------------------" << endl;
	cout << "                  * 등록된 관리자만 로그인할 수 있습니다.                  " << endl << endl;

	
	cout << "                      I      D : ";
	cin >> id;
	cout << endl << endl;
	cout << "                      비밀번호 : ";
	for (i = 0; buffer != 13; i++) {
		inputPw[i] = _getch();
		cout << "*";
		buffer = (int)inputPw[i];
	}
	inputPw[i - 1] = '\0'; //마지막 문자 NULL 문자로 치환
	if(strcmp(id, "aaa") == 0 && strcmp(inputPw, "aaa") == 0){
		cout << endl << endl << endl;
		cout << "                      -- admin1로 로그인되었습니다 --                      ";
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
	system("cls");

	while (1) {
		if (keyControl() == SUBMIT) {
			break;
		}
	}
}