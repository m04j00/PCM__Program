#include "main.h"

void init() {
	//console ũ��
	//cols : ���� lines : ����
	system("mode con: cols=75 lines=20");
	mysqlMain();
	//���콺 Ŀ�� ���ֱ�
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = 0;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);
}

//��ǥ �Լ�
void gotoxy(int x, int y) {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}
//title ��ǥ
void titleXY() {
	gotoxy(21, 4);
}
//�̵� ������ Ű���� Ű �Լ�
int keyControl() {
	char temp = _getch();
	if (temp == 72) return UP;
	else if (temp == 80) return DOWN;
	else if (temp == 37) return LEFT;
	else if (temp == 77) return RIGHT;
	else if (temp == 32) return SUBMIT;
	else if (temp == 27) return EXIT;
}