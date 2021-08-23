#include "main.h"
#include "cmgt.h"
#include <cstring>  
//#include "airtight.h"
#define ADMINID admin07
#define adminPW admin0702

void carMgtScreen() {
	system("cls");
	gotoxy(21, 4);
	cout << "아파트 차량 관리 시스템";
	int x = 33;
	int y = 7;
	gotoxy(x - 2, y);
	cout << "> 관리자 로그인";
	gotoxy(x, y + 1);
	cout << "입주민 로그인";
	gotoxy(x, y + 2);
	cout << "뒤로가기";

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
			int code = y - 7;
			if (code == 0)	adminLogin();
			else if (code == 1)	residentLogin();
			else return;
		}
		}
	}
}

void adminLogin() {
	system("cls");

	char* id = (char*)malloc(sizeof(char) * 100);
	char* inputPw = (char*)malloc(sizeof(char) * 100);
	int buffer = 0;
	int i = 0;

	cout << endl << endl << endl << endl;
	cout << "                    관리자 로그인" << endl << endl;
	cout << "* 설정된 관리자 id로만 로그인할 수 있습니다." << endl;
	cout << " id : ";
	cin >> id;
	cout << " 비밀번호 : ";
	for (i = 0; buffer != 13; i++) {
		inputPw[i] = _getch();
		cout << "*";
		buffer = (int)inputPw[i];
	}
	inputPw[i - 1] = '\0'; //마지막 문자 NULL 문자로 치환

	if (id == "adminid" && inputPw == "adminpw") {
		cout << "로그인 성공";
	}
	else {
		system("cls");
		cout << "관리자 의외의 사람은 로그인할 수 없습니다.";
		Sleep(1000);
		carMgtScreen();
		return;
	}
}
void residentLogin() {
	char id;
	char pw;
	system("cls");
	cout << "                    입주민 로그인" << endl << endl;
	cout << " id : ";
	cin >> id;
	cout << " 비밀번호 : ";
	cin >> pw;

	while (1) {
		if (keyControl() == SUBMIT) {
			break;
		}
	}
}