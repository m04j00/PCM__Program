#include "main.h"
int main() {
	init();
	while (1) {
		mainTitle();
		int menuCode = mainMenu();
		if (menuCode == 0) {
			login();
		}
		else if (menuCode == 1) {
			carMgtScreen();
		}
		else if (menuCode == 2) {
			infoScreen();
		}
		else if (menuCode == 3) {
			return 0;
		}
		system("cls");
	}
	return 0;
}

int afterLoginMain(const char* id) {
	system("cls");
	while (1) {
		gotoxy(21, 4);
		cout << "����Ʈ ���� �� ���� ���� �ý���";
		int menuCode = afterLoginMainMenu();
		if (menuCode == 0) {
			parkingMgtScreen(id);
		}
		else if (menuCode == 1) {
			carMgtScreen();
		}
		else if (menuCode == 2) {
			infoScreen();
		}
		else if (menuCode == 3) {
			mysqlClose();
			return 0;
		}
		system("cls");
	}
	return 0;
}