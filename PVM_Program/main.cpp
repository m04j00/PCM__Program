#include <iostream>
#include <Windows.h>
#include <conio.h>
using namespace std;

void gotoxy(int, int);
void init();
int mainMenu();

int main() {
	//cols : ���� lines : ����
	system("mode con: cols=75 lines=20");
	init();
	mainMenu();
	return 0;
}

void gotoxy(int x, int y) {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}
void init() {
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

	return 0;
}