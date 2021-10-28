#include "main.h"

void mainTitle() {
	gotoxy(0, 4);
	cout << "                      아파트 주차 및 차량 관리 시스템                      ";
}
int mainMenu() {
	int x = 33;
	int y = 7;
	gotoxy(x - 2, y);
	cout << "> 주  차  장";
	gotoxy(x, y + 1);
	cout << "로  그  인";
	gotoxy(x, y + 2);
	cout << "방문  차량";
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
	cout << "로그 아웃";
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
int VisitingMenu() {
	int x = 27;
	int y = 7;
	gotoxy(x - 2, y);
	//cout << "                             방문 차량 메뉴 창                             ";
	//cout << "                                 차량 정보                                 ";
	//cout << "                                 출차 하기                                 ";
	//cout << "                           주차된 상태에서 나가기                          ";
	cout << ">       차량 정보       ";
	gotoxy(x, y + 1);
	cout << "      출차 하기       ";
	gotoxy(x, y + 2);
	cout << "주차된 상태에서 나가기";

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
int ResidentMgtMenu() {
	int x = 31;
	int y = 7;
	gotoxy(x - 2, y);
	cout << "> 차  량  등  록";
	gotoxy(x, y + 1);
	cout << "차량 등록 해지";
	gotoxy(x, y + 2);
	cout << "차  량  조  회";
	gotoxy(x, y + 3);
	cout << "뒤  로  가  기";

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
			if (y < 10) {
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
int adminMenu() {
	int x = 30;
	int y = 7;
	gotoxy(x - 2, y);
	//cout << "                            > 입주민 차량 관리                              ";
	//cout << "                              방문   차량 관리                               ";
	//cout << "                              주  차  장  조회                                ";
	//cout << "                              뒤  로    가  기                              ";
	cout << "> 입주민 차량 관리";
	gotoxy(x, y + 1);
	cout << "방문   차량 관리";
	gotoxy(x, y + 2);
	cout << "주  차  장  조회";
	gotoxy(x, y + 3);
	cout << "로  그    아  웃";

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
			if (y < 10) {
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