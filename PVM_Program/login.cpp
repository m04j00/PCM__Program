#include "main.h"
void login() {
	system("cls");
	char* id = (char*)malloc(sizeof(char) * 16);
	char* pw = (char*)malloc(sizeof(char) * 20);
	cout << endl << endl << endl;
	cout << "                                   로그인                                  " << endl << endl;
	cout << "           * 관리자는 사전에 등록된 계정만 로그인할 수 있습니다.           " << endl;
	cout << "       * 입주민은 관리자를 통해 등록된 계정만 로그인할 수 있습니다.        " << endl << endl << endl;

	cout << "                      I      D : ";
	cin >> id;
	cout << endl;
	cout << "                      비밀번호 : ";
	cin >> pw;

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
		return;
	}
	case 2: {
		cout << "                            로그인 되었습니다.                             ";
		Sleep(1000);
		system("cls");
		adminScreen();
		return;
	}
	}
	system("cls");
	return;
}