#include "PVM.h"

void carMgtScreen() {
	system("cls");
	gotoxy(21, 4);
	cout<< "아파트 차량 관리 시스템";
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

}
void residentLogin() {

}