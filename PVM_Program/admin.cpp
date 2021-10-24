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
			system("cls");
			ResiMgtScreen();
			
		}
		else if (menuCode == 1) {
			system("cls");
			VisitingMgtScreen();
		}
		else if (menuCode == 2) {
			system("cls");
			parkingLotScreen();
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
	cout << "> 입주민 차량 관리";
	gotoxy(x, y + 1);
	cout << "방문  차량  관리";
	gotoxy(x, y + 2);
	cout << "주 차 장   관 리";
	gotoxy(x, y + 3);
	cout << "뒤  로    가  기";

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
int ResiMgtScreen() {
	system("cls");

	while (1) {
		cout << endl << endl << endl << endl;
		cout << "                            입주민 차량 관리 창                            ";
		int menuCode = ResidentMgtMenu();
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
int ResidentMgtMenu() {
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
void VisitingMgtScreen() {
	system("cls");
	cout << endl << endl << endl << endl;
	cout << "                              방문 차량 현황                               " << endl << endl << endl;
	int num = VisitingList();
	if (num == 1)
		cout << endl << endl <<  "                     주차된 방문차량이 없습니다." << endl << endl;
	while (1) {
		if (keyControl() == SUBMIT) {
			system("cls");
			return;
		}
	}
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
	int isCar = SearchCarNum(carNum);
	if (isCar == -1) {
		printf("\n%s                        이미 등록된 차량번호입니다.                         %s\n", RED, DEF);
		printf("                        이전 화면으로 돌아갑니다...                        ");
		Sleep(1500);
		return 0;
	}
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

	int isUser = SearchUserId(id);
	if (isUser == 0) {
		JoinUser(id, password);
		JoinCarInfo(id, carNum, phoneNum, nBuilding, nUnit);
		printf("%s                                등록되었습니다.                                %s", GREEN, DEF);
	}
	else printf("%s                          이미 등록된 아이디입니다.                           %s", RED, DEF);
		
	Sleep(1000);
	while (1) {
		if (keyControl() == SUBMIT) {
			system("cls");
			return 0;
		}
	}
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
	cout << endl << endl;
	int carInfo = FindCarInfo(carNum);
	if (carInfo) {
		printf("%s                      등록되지 않은 차량번호 입니다.                       %s\n\n", RED, DEF);
		printf("                        이전 화면으로 돌아갑니다...                        ");
		Sleep(1500);
		return 0;
	}
	cout << endl << "---------------------------------------------------------------------------" << endl << endl;
	

	cout << "                       해당 정보가 맞습니까 ? Y / N                        " << endl;
	cout << "                       >> ";
	cin >> YorN;
	cout << endl;
	if (YorN == 'Y' || YorN == 'y') {
		char* inputId = (char*)malloc(sizeof(char) * 20);
		cout << "                     함께 등록한 아이디를 입력해주세요                     " << endl;
		cout << "                     >> ";
		cin >> inputId;
		cout << endl << endl;
		int success = DeleteCarInfo(carNum, inputId);
		if (success == 0)
			printf("%s                        정상적으로 해지되었습니다.                         %s", GREEN, DEF);
		else {
			printf("%s           입력한 아이디와 일치하지 않아 해지가 취소 되었습니다.           %s\n\n", RED, DEF);
			printf("                        이전 화면으로 돌아갑니다...                        ");
			Sleep(1500);
			return 0;
		}
	}
	//"                     함께 등록한 아이디를 입력해주세요                     "
	else	
		printf("%s                              취소되었습니다.                              %s\n\n", RED, DEF);
	Sleep(1000);
	while (1) {
		if (keyControl() == SUBMIT) {
			system("cls");
			return 0 ;
		}
	}
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

void parkingLotScreen() {
	cout << endl << endl << endl << endl;
	cout << "                                  주 차 장                                  " << endl << endl << endl;
	int parkingPossible = parkingAvailableNum();
	cout << "                        주차 구역 현황  |  " << parkingPossible << " / 100" << endl << endl;
	printf(" * %s초록색%s : 빈 구역, %s붉은색%s : 입주민 주차 상태, %s청색%s : 방문 차량 주차 상태 \n", GREEN, DEF, RED, DEF, BLUE, DEF);
	cout << "                          * 뒤로가기 : 스페이스바                          " << endl;
	cout << endl << endl;
	drewParkingLotToCarNum();

	while (1) {
		if (keyControl() == SUBMIT) {
			system("cls");
			return;
		}
	}
} 