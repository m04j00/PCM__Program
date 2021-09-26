#include "main.h"

void init() {
	//console 크기
	//cols : 세로 lines : 가로
	system("mode con: cols=75 lines=20");
	mysqlMain();
	//마우스 커서 없애기
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = 0;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);
}

//좌표 함수
void gotoxy(int x, int y) {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}
//title 좌표
void titleXY() {
	gotoxy(21, 4);
}
//이동 관련한 키보드 키 함수
int keyControl() {
	char temp = _getch();
	if (temp == 72) return UP;
	else if (temp == 80) return DOWN;
	else if (temp == 37) return LEFT;
	else if (temp == 77) return RIGHT;
	else if (temp == 32) return SUBMIT;
	else if (temp == 27) return EXIT;
}