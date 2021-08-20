#include "PVM.h"

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