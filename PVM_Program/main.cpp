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
			isVisitant();
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