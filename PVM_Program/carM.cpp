#include "main.h"
#include "cmgt.h"
#include <cstring>  
//#include "airtight.h"
#define ADMINID admin07
#define adminPW admin0702

void carMgtScreen() {
	system("cls");
	gotoxy(21, 4);
	cout << "����Ʈ ���� ���� �ý���";
	int x = 33;
	int y = 7;
	gotoxy(x - 2, y);
	cout << "> ������ �α���";
	gotoxy(x, y + 1);
	cout << "���ֹ� �α���";
	gotoxy(x, y + 2);
	cout << "�ڷΰ���";

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
	cout << "                    ������ �α���" << endl << endl;
	cout << "* ������ ������ id�θ� �α����� �� �ֽ��ϴ�." << endl;
	cout << " id : ";
	cin >> id;
	cout << " ��й�ȣ : ";
	for (i = 0; buffer != 13; i++) {
		inputPw[i] = _getch();
		cout << "*";
		buffer = (int)inputPw[i];
	}
	inputPw[i - 1] = '\0'; //������ ���� NULL ���ڷ� ġȯ

	if (id == "adminid" && inputPw == "adminpw") {
		cout << "�α��� ����";
	}
	else {
		system("cls");
		cout << "������ �ǿ��� ����� �α����� �� �����ϴ�.";
		Sleep(1000);
		carMgtScreen();
		return;
	}
}
void residentLogin() {
	char id;
	char pw;
	system("cls");
	cout << "                    ���ֹ� �α���" << endl << endl;
	cout << " id : ";
	cin >> id;
	cout << " ��й�ȣ : ";
	cin >> pw;

	while (1) {
		if (keyControl() == SUBMIT) {
			break;
		}
	}
}