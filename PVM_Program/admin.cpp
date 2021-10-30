#include "main.h"
#include <cstring>  

int adminScreen() {
	system("cls");

	while (1) {
		cout << endl << endl << endl << endl;
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
			AdminParkingLotScreen();
		}
		else if (menuCode == 3) {
			return 0;
		}
		system("cls");
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
void VisitingMgtScreen() {
	system("cls");
	cout << endl << endl << endl << endl;
	cout << "                              방문 차량 현황                               " << endl << endl;
	cout << "                          * 뒤로가기 : 스페이스바                          " << endl << endl << endl;
	int num = VisitingList();
	if (num == 1) {
		cout << endl << endl;
		cout << "                        주차된 방문차량이 없습니다.                        " << endl << endl;
	}
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
	int isCar = SearchCarNum(carNum, 0);
	if (isCar == -1) {
		printf("\n%s                        이미 등록된 차량번호입니다.                         %s\n", RED, DEF);
		printf("                        이전 화면으로 돌아갑니다...                        ");
		Sleep(1500);
		return 0;
	}
	cout << "               전화 번호 : ";
	cin >> phoneNum;
	cout << "               동     수 : ";
	cin >> nBuilding;
	cout << "               호     수 : ";
	cin >> nUnit;
	cout << "               I       D : ";
	cin >> id;
	cout << "               비밀 번호 : ";
	cin >> password;
	cout << endl << endl;

	int isUser = SearchUserId(id);
	if (isUser == 0) {
		JoinUser(id, password);
		JoinCarInfo(id, carNum, phoneNum, nBuilding, nUnit);
		printf("%s                            차량이 등록되었습니다.                             %s\n\n", GREEN, DEF);
		cout << "                       주차를 진행하시겠습니까? Y / N                       " << endl;
		char YorN = '0';
		while (true) {
			gotoxy(0, 19);
			cout << "                                                 " << endl;
			gotoxy(0, 19);
			cout << "                       >> ";
			cin >> YorN;
			if (YorN == 'Y' || YorN == 'y') {
				cout << endl << "                    1초 뒤 화면이 자동으로 이동됩니다...                    ";
				Sleep(1500);
				gotoParkingLot(carNum);
				return 0;
			}
			else if (YorN == 'N' || YorN == 'n') {
				break;
			}
		}
	}
	else printf("%s                          이미 등록된 아이디입니다.                           %s", RED, DEF);
	
	cout << endl << endl;
	printf("                        이전 화면으로 돌아갑니다...                        ");
	Sleep(1500);

	system("cls");
	return 0;

}
int gotoParkingLot(char* car_num) {
	system("cls");
	char* parkingSpace = (char*)malloc(sizeof(char) * 10);
	int availableNum = parkingAvailableNum();
	cout << endl << endl << endl << endl;
	cout << "                                   주차장                                  " << endl << endl;
	cout << "                         주차 가능 구역 현황 " << availableNum << " / 100" << endl;
	printf("              * %s초록색%s : 주차 가능 구역, %s붉은색%s : 주차된 구역               \n\n", GREEN, DEF, RED, DEF);
	DrewParkingLot();
	while (true) {
		gotoxy(0, 40);
		cout << "                                                                                ";
		gotoxy(0, 42);
		cout << "                                                                                ";
		gotoxy(0, 40);
		cout << "                     주차 구역을 입력해주세요 >> ";
		cin >> parkingSpace;
		int checkingParking = parkingLotState(1, parkingSpace, car_num, 0);
		gotoxy(0, 42);
		if (checkingParking == -1) {
			printf("%s        주차 구역을 잘못 입력했습니다. 다시 입력해주세요.%s", RED, DEF);
			Sleep(1500);
		}
		else if (checkingParking == 1) {
			printf("%s        이미 주차된 구역입니다. 다시 입력해주세요.%s", RED, DEF);
			Sleep(1500);
		}
		else if (checkingParking == 0) {
			ResidentState(1, parkingSpace, car_num);
			cout << "                              주차되었습니다.                              ";
			break;
		}
	}
	Sleep(1500);
	system("cls");
	return 0;
}
int carDelReg() {
	system("cls");
	char* carNum = (char*)malloc(sizeof(char) * 10);
	int selectBuilding = 0;
	int selectUnit = 0;
	string selectPhoneNum = "aaaaaa";

	cout << endl << endl << endl << endl;
	cout << "                               차량 등록 해지                              " << endl << endl << endl;
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
	
	cout << "                     해당 정보가 맞습니까 ?     Y / N                      " << endl;
	char YorN = '0';
	while (true) {
		gotoxy(0, 17);
		cout << "                                             " << endl;
		gotoxy(0, 17);
		cout << "                     >> ";
		cin >> YorN;
		if (YorN == 'Y' || YorN == 'y') {
			char* inputId = (char*)malloc(sizeof(char) * 20);
			cout << endl;
			cout << "                     함께 등록한 아이디를 입력해주세요                     " << endl;
			cout << "                     >> ";
			cin >> inputId;
			cout << endl << endl;
			int success = DeleteCarInfo(carNum, inputId);
			if (success == 0) {
				printf("%s                        정상적으로 해지되었습니다.                         %s", GREEN, DEF);
				cout << endl << endl << "                    1초 뒤 화면이 자동으로 이동됩니다...                    ";
			}
			else {
				printf("%s           입력한 아이디와 일치하지 않아 해지가 취소 되었습니다.           %s\n\n", RED, DEF);
				printf("                        이전 화면으로 돌아갑니다...                        ");
			}
			break;
		}
		else if (YorN == 'N' || YorN == 'n') {
			printf("%s                              취소되었습니다.                              %s\n\n", RED, DEF);
			printf("                        이전 화면으로 돌아갑니다...                        ");
			break;
		}
	}
	Sleep(1500);
	system("cls");
	return 0;
}
void ShowResidentList() {
	system("cls");
	cout << endl << endl << endl << endl;
	cout << "                                 차량 조회                                 " << endl << endl;
	cout << "                          * 뒤로가기 : 스페이스바                          " << endl;
	cout << endl << endl;
	ResidentList();
	while (1) {
		if (keyControl() == SUBMIT) {
			system("cls");
			return;
		}
	}
}

void AdminParkingLotScreen() {
	cout << endl << endl << endl << endl;
	cout << "                                  주 차 장                                  " << endl << endl << endl;
	int parkingPossible = parkingAvailableNum();
	cout << "                        주차 구역 현황  |  " << parkingPossible << " / 100" << endl << endl;
	printf(" * %s초록색%s : 빈 구역, %s붉은색%s : 입주민 주차 상태, %s청색%s : 방문 차량 주차 상태 \n", GREEN, DEF, RED, DEF, BLUE, DEF);
	cout << "                          * 뒤로가기 : 스페이스바                          " << endl;
	cout << endl << endl;
	drewParkingLotToCarNum(1, NULL);

	while (1) {
		if (keyControl() == SUBMIT) {
			system("cls");
			return;
		}
	}
} 