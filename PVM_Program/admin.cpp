#include "main.h"
#include "cmgt.h"
#include <cstring>  

int adminScreen() {
	system("cls");

	while (1) {
		cout << endl << endl << endl << endl;
		//cout << "---------------------------------관리자 창---------------------------------";
		cout << "                                 관리자 창                                 ";
		int menuCode = adminMenu();
		if (menuCode == 0) {
			carRegistration();
		}
		else if (menuCode == 1) {
			carDelReg();
		}
		else if (menuCode == 2) {
			ShowResidentList();
		}
		else if (menuCode == 3) {
			return 0;
		}
		system("cls");
	}
	return 0;

}

int adminMenu() {
	int x = 31;
	int y = 7;
	gotoxy(x - 2, y);
	cout << "> 차  량  등  록";
	gotoxy(x, y + 1);
	cout << "차량 등록 해지";
	gotoxy(x, y + 2);
	cout << "차  량  조  회";
	gotoxy(x, y + 3);
	cout << "뒤  로  가  기";

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

int carRegistration() {
	system("cls");
	char* carNum = (char*)malloc(sizeof(char) * 10);
	char* phoneNum = (char*)malloc(sizeof(char) * 20);
	int nBuilding;
	int nUnit;
	char* id = (char*)malloc(sizeof(char) * 12);
	char* password = (char*)malloc(sizeof(char) * 20);

	cout << endl << endl << endl << endl;
	cout << "                                 차량 등록                                 " << endl << endl << endl;
	cout << "               차량 번호 : ";
	cin >> carNum;
	cout << "               전화 번호 : ";
	cin >> phoneNum;
	cout << "               동 수 : ";
	cin >> nBuilding;
	cout << "               호 수 : ";
	cin >> nUnit;
	cout << "               아이디 : ";
	cin >> id;
	cout << "               비밀 번호 : ";
	cin >> password;
	cout << endl << endl;

	int joinInfo = JoinCarInfo(id, carNum, phoneNum, nBuilding, nUnit);
	int Join = JoinUser(id, password);
	if(joinInfo == 0 && Join == 0)
		cout << "                        차량 등록이 완료되었습니다.                        ";
		
	else 
		cout << "                 이미 등록된 아이디이거나 차량번호입니다.                  ";
	Sleep(3000);
	system("cls");
	return 0;

}

int carDelReg() {
	system("cls");
	char* carNum = (char*)malloc(sizeof(char) * 10);
	int selectBuilding = 0;
	int selectUnit = 0;
	string selectPhoneNum = "aaaaaa";
	char YorN = '0';

	cout << endl << endl << endl << endl;
	cout << "                               차량 등록 해지                              " << endl << endl;
	cout << "                    차량 번호 : ";
	cin >> carNum;
	cout << endl;
	int carInfo = FindCarInfo(carNum);
	if (carInfo) {
		cout << "                      등록되지 않은 차량번호 입니다.                       " << endl;
		Sleep(1000);
		return 0;
	}
	cout << endl << "---------------------------------------------------------------------------" << endl << endl;
	

	cout << "                       해당 정보가 맞습니까 ? Y / N                        " << endl;
	cout << "                       >> ";
	cin >> YorN;
	cout << endl;
	if (YorN == 'Y' || YorN == 'y') {
		DeleteCarInfo(carNum);
		cout << "                        정상적으로 해지되었습니다.                         " << endl;
	}
	else	
		cout << "                              취소되었습니다.                              " << endl;
	Sleep(1000);
	system("cls");
	return 0;
}
void ShowResidentList() {
	system("cls");
	cout << endl << endl;
	cout << "                                 차량 조회                                 " << endl;
	cout << endl << endl;
	ResidentList();
	while (1) {
		if (keyControl() == SUBMIT) {
			system("cls");
			return;
		}
	}
}