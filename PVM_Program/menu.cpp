#include "main.h"

void mainTitle() {
	gotoxy(21, 4);
	cout << "����Ʈ ���� �� ���� ���� �ý���";
}
int mainMenu() {
	int x = 33;
	int y = 7;
	gotoxy(x - 2, y);
	cout << "> ��  ��  ��";
	gotoxy(x, y + 1);
	cout << "�湮  ����";
	gotoxy(x, y + 2);
	cout << "��  ��  ��";
	gotoxy(x, y + 3);
	cout << "���  ���";
	gotoxy(x, y + 4);
	cout << "  ��  ��  ";
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
	cout << "> ���� ����";
	gotoxy(x, y + 1);
	cout << "���� ����";
	gotoxy(x, y + 2);
	cout << "�ڷ� ����";
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
	cout << "> ������ (���� ��ġ Ȯ��)";
	gotoxy(x, y + 2);
	cout << "�ڷ� ����";
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