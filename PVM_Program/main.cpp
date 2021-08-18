#include <iostream>
#include <Windows.h>
#include <conio.h>
using namespace std;

void gotoxy(int, int);
void init();
int mainMenu();

int main() {
	//cols : 세로 lines : 가로
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

	return 0;
}