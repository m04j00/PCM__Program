#include <iostream>
#include <Windows.h>
#include <conio.h>
using namespace std;

//Ű���� ��
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
	//cols : ���� lines : ����
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
	cout << "����Ʈ ���� �� ���� ���� �ý���";
}
int mainMenu() {
	int x = 33;
	int y = 7;
	gotoxy(x - 2, y);
	cout << "> ���� ����";
	gotoxy(x, y + 1);
	cout << "���� ����";
	gotoxy(x, y + 2);
	cout << "��� ���";
	gotoxy(x, y + 3);
	cout << "  �� ��  ";
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
	cout << "                    ���� ���" << endl << endl;
	cout << "              �̵� : ȭ��ǥ �� �� �� ��" << endl << endl;
	cout << "              ���� : ����" << endl << endl << endl; 

	while (1) {
		if (keyControl() == SUBMIT) {
			break;
		}
	}
}