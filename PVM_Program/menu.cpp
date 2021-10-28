#include "main.h"

void mainTitle() {
	gotoxy(21, 4);
	cout << "아파트 주차 및 차량 관리 시스템";
}
int mainMenu() {
	int x = 33;
	int y = 7;
	gotoxy(x - 2, y);
	cout << "> 로  그  인";
	gotoxy(x, y + 1);
	cout << "방문  차량";
	gotoxy(x, y + 2);
	cout << "주  차  장";
	gotoxy(x, y + 3);
	cout << "사용  방법";
	gotoxy(x, y + 4);
	cout << "  종  료  ";
	cout << endl << endl << endl;

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
			if (y < 11) {
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
int afterLoginMainMenu() {
	int x = 33;
	int y = 10;
	gotoxy(x - 2, y);
	cout << "> 주차 관리";
	gotoxy(x, y + 1);
	cout << "차량 관리";
	gotoxy(x, y + 2);
	cout << "뒤로 가기";
	cout << endl << endl << endl;

	while (1) {
		int num = keyControl();
		switch (num) {
		case UP: {
			if (y > 10) {
				gotoxy(x - 2, y);
				cout << " ";
				gotoxy(x - 2, --y);
				cout << ">";
			}
			break;
		}
		case DOWN: {
			if (y < 12) {
				gotoxy(x - 2, y);
				cout << " ";
				gotoxy(x - 2, ++y);
				cout << ">";
			}
			break;
		}
		case SUBMIT: {
			return y - 10;
		}
		}
	}
	return 0;
}

int MgtMenu() {
	int x = 33;
	int y = 15;
	gotoxy(x - 2, y);
	cout << "> 주차장 (주차 위치 확인)";
	gotoxy(x, y + 2);
	cout << "뒤로 가기";
	cout << endl << endl << endl;

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