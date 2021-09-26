#include "main.h"
#include "cmgt.h"
void login() {
	system("cls");
	char* id = (char*)malloc(sizeof(char) * 16);
	char* pw = (char*)malloc(sizeof(char) * 16);
	cout << endl << endl << endl;
	cout << "                                   로그인                                  " << endl << endl;
	cout << "                  * 등록된 관리자만 로그인할 수 있습니다.                  " << endl;
	cout << "           * 관리자를 통해 등록된 입주민만 로그인할 수 있습니다.           " << endl << endl;

	cout << "                      I      D : ";
	cin >> id;
	cout << endl;
	cout << "                      비밀번호 : ";

	// 비밀번호 가리기
	int i = 0;
	int buf = 0;
	for (i = 0; buf != 13; i++) {
		pw[i] = _getch();
		cout << "*";
		buf = (int)pw[i];
	}
	pw[i - 1] = '\0'; //마지막 문자 NULL 문자로 치환
	//char num, char phoneNum, int state,  char id, char pw, char building, char unit
	//Resident rd("1234", "010-1111-1111", 0, id, pw, "101", "101");

	int isUser = FindUser(id, pw);
	cout << endl << endl;
	switch (isUser) {
	case 0: {
		cout << "                   일치하는 아이디가 존재하지 않습니다.                   ";
		Sleep(1000);
		system("cls");
		return;
	}
	case -1: {
		cout << "                       비밀번호가 일치하지 않습니다.                       ";
		Sleep(1000);
		system("cls");
		return;
	}
	case 1: {
		cout << "                            로그인 되었습니다.                             ";
		Sleep(1000);
		system("cls");
		afterLoginMain(id);
	}
	case 2: {
		cout << "                            로그인 되었습니다.                             ";
		Sleep(1000);
		system("cls");
		adminScreen();
	}
	}
	system("cls");
	//afterLoginMain(id);
	return;
}