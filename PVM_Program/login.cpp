#include "main.h"
#include "cmgt.h"
void login() {
	system("cls");
	char* id = (char*)malloc(sizeof(char) * 16);
	char* pw = (char*)malloc(sizeof(char) * 16);
	cout << endl << endl << endl;
	cout << "                                   �α���                                  " << endl << endl;
	cout << "                  * ��ϵ� �����ڸ� �α����� �� �ֽ��ϴ�.                  " << endl;
	cout << "           * �����ڸ� ���� ��ϵ� ���ֹθ� �α����� �� �ֽ��ϴ�.           " << endl << endl;

	cout << "                      I      D : ";
	cin >> id;
	cout << endl;
	cout << "                      ��й�ȣ : ";

	// ��й�ȣ ������
	int i = 0;
	int buf = 0;
	for (i = 0; buf != 13; i++) {
		pw[i] = _getch();
		cout << "*";
		buf = (int)pw[i];
	}
	pw[i - 1] = '\0'; //������ ���� NULL ���ڷ� ġȯ
	//char num, char phoneNum, int state,  char id, char pw, char building, char unit
	//Resident rd("1234", "010-1111-1111", 0, id, pw, "101", "101");

	int isUser = FindUser(id, pw);
	cout << endl << endl;
	switch (isUser) {
	case 0: {
		cout << "                   ��ġ�ϴ� ���̵� �������� �ʽ��ϴ�.                   ";
		Sleep(1000);
		system("cls");
		return;
	}
	case -1: {
		cout << "                       ��й�ȣ�� ��ġ���� �ʽ��ϴ�.                       ";
		Sleep(1000);
		system("cls");
		return;
	}
	case 1: {
		cout << "                            �α��� �Ǿ����ϴ�.                             ";
		Sleep(1000);
		system("cls");
		afterLoginMain(id);
	}
	case 2: {
		cout << "                            �α��� �Ǿ����ϴ�.                             ";
		Sleep(1000);
		system("cls");
		adminScreen();
	}
	}
	system("cls");
	//afterLoginMain(id);
	return;
}