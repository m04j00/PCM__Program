#include "PVM.h"

void carMgtScreen() {
	system("cls");
	gotoxy(21, 4);
	cout<< "����Ʈ ���� ���� �ý���";
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

}
void residentLogin() {

}