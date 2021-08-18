#include <iostream>
#include <Windows.h>
#include <conio.h>
using namespace std;

//키보드 값
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4
#define BACK 5
#define EXIT 6

void init();
void gotoxy(int, int);
int keyControl();
void titleText();
int mainMenu();
void infoDraw();

int main() {
	init();
	
	while (1) {
		titleText();
		int menuCode = mainMenu();
		if (menuCode == 0) {
			
		}
		else if (menuCode == 1) {

		}
		else if (menuCode == 2) {
			infoDraw();
		}
		else if (menuCode == 3) {
			return 0;
		}
		system("cls");
	}
	
	return 0;
}

void init() {
	//cols : 세로 lines : 가로
	system("mode con: cols=75 lines=20");

	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = 0;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);
}
void gotoxy(int x, int y) {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}
void titleText() {
	gotoxy(21, 4);
	cout << "아파트 주차 및 차량 관리 시스템";
}
int mainMenu() {
	int x = 33;
	int y = 7;
	gotoxy(x - 2, y);
	cout << "> 주차 관리";
	gotoxy(x, y + 1);
	cout << "차량 관리";
	gotoxy(x, y + 2);
	cout << "사용 방법";
	gotoxy(x, y + 3);
	cout << "  종 료  ";
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
int keyControl() {
	char temp = _getch();
	if (temp == 72) return UP;
	else if (temp == 80) return DOWN;
	else if (temp == 75) return LEFT;
	else if (temp == 77) return RIGHT;
	else if (temp == 13) return SUBMIT;
}
void infoDraw() {
	system("cls");
	cout << endl << endl;
	cout << "                    조작 방법" << endl << endl;
	cout << "              이동 : 화살표 ↑ ↓ ← →" << endl << endl;
	cout << "              선택 : 엔터" << endl << endl << endl; 

	while (1) {
		if (keyControl() == SUBMIT) {
			break;
		}
	}
}