#include "main.h"
#include "cmgt.h"
#include <cstring>  
//#include "airtight.h"
#define ADMINID admin07
#define adminPW admin0702

int carMgtScreen() {
	system("cls");

	while (1) {
		cout << endl << endl << endl << endl;
		cout << "                           ����Ʈ ���� ���� �ý���";
		int menuCode = carMgtMenu();
		if (menuCode == 0) {
			adminLogin();
		}
		else if (menuCode == 1) {
			residentLogin();
		}
		else if (menuCode == 2) {
			return 0;
		}
		system("cls");
	}
	return 0;

}

int carMgtMenu() {
	int x = 32;
	int y = 7;
	gotoxy(x - 2, y);
	cout << "> ������  �α���";
	gotoxy(x, y + 1);
	cout << "���ֹ�  �α���";
	gotoxy(x, y + 2);
	cout << "��  ��  ��  ��";

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
int adminLogin() { return 0; }
int main() {
	init();
	system("cls");
	char* id = (char*)malloc(sizeof(char) * 100);
	char* inputPw = (char*)malloc(sizeof(char) * 100);
	int buffer = 0;
	int i = 0;

	cout << endl << endl << endl << endl;
	//cout << "-------------------------------������ �α���-------------------------------" << endl << endl;
	cout << "                               ������ �α���                               " << endl << endl;
	//cout << "-------------------* ������ id�θ� �α����� �� �ֽ��ϴ�.-------------------" << endl;
	cout << "                  * ��ϵ� �����ڸ� �α����� �� �ֽ��ϴ�.                  " << endl << endl;

	
	cout << "                      I      D : ";
	cin >> id;
	cout << endl << endl;
	cout << "                      ��й�ȣ : ";
	for (i = 0; buffer != 13; i++) {
		inputPw[i] = _getch();
		cout << "*";
		buffer = (int)inputPw[i];
	}
	inputPw[i - 1] = '\0'; //������ ���� NULL ���ڷ� ġȯ
	if(strcmp(id, "aaa") == 0 && strcmp(inputPw, "aaa") == 0){
		cout << endl << endl << endl;
		cout << "                      -- admin1�� �α��εǾ����ϴ� --                      ";
	}
	else {
		system("cls");
		cout << endl << endl << endl << endl << endl << endl << endl << endl;
		cout << "                         ��ϵ� �����ڰ� �ƴմϴ�.                         ";
		Sleep(1000);
	}
	return 0;
}
void residentLogin() {
	system("cls");

	while (1) {
		if (keyControl() == SUBMIT) {
			break;
		}
	}
}