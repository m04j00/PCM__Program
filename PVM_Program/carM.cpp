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
			return 0;
		}
		else if (menuCode == 1) {
			return 0;
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
