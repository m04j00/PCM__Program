#include "main.h"
void login() {
	system("cls");
	char* id = (char*)malloc(sizeof(char) * 16);
	char* pw = (char*)malloc(sizeof(char) * 20);
	cout << endl << endl << endl;
	cout << "                                   �α���                                  " << endl << endl;
	cout << "           * �����ڴ� ������ ��ϵ� ������ �α����� �� �ֽ��ϴ�.           " << endl;
	cout << "       * ���ֹ��� �����ڸ� ���� ��ϵ� ������ �α����� �� �ֽ��ϴ�.        " << endl << endl << endl;

	cout << "                      I      D : ";
	cin >> id;
	cout << endl;
	cout << "                      ��й�ȣ : ";
	cin >> pw;

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
		return;
	}
	case 2: {
		cout << "                            �α��� �Ǿ����ϴ�.                             ";
		Sleep(1000);
		system("cls");
		adminScreen();
		return;
	}
	}
	system("cls");
	return;
}