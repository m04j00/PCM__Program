#include "main.h"

void isVisitant() {
	system("cls");
	cout << endl << endl << endl << endl;
	cout << "                                 방문 차량                                 " << endl << endl << endl;
	cout << "                   주차장에 주차된 차량이 있습니까? Y / N                   " << endl;

	char YorN = '0';
	while (true) {
		gotoxy(0, 8);
		cout << "                                             " << endl;
		gotoxy(0, 8);
		cout << "                   >> ";
		cin >> YorN;
		if (YorN == 'Y' || YorN == 'y') {
			cout << endl;
			char* input_num = (char*)malloc(sizeof(char) * 20);
			//cout << "                          차량 번호를 입력해주세요                         " << endl;
			cout << "                   차량 번호를 입력해주세요 : ";
			//cout << "                          >> ";
			cin >> input_num;
			cout << endl << endl;
			int success = isVisiter(input_num); // 존재(-1), 없음(0)
			if (success == 0) { // 로그인
				printf("%s                       방문 차량이 확인되었습니다.                         %s", GREEN, DEF);
				Sleep(1500);
				VisitingCar car;
				VisitingGetCarInfo(input_num, car);
				VisitingScreen(car);
				return;
			}
			else if (success == -1) {
				printf("%s          입력한 차량번호와 일치하는 차량번호를 찾을 수 없습니다.          %s\n\n", RED, DEF);
				printf("                        이전 화면으로 돌아갑니다...                        ");
				break;

			}
			else{
				printf("%s        해당 차량은 최대 주차 기간이 지났습니다. 출차를 요청합니다.        %s\n\n", RED, DEF);
				Sleep(500);
				printf("%s                                 출차 완료                                 %s\n\n", GREEN, DEF);
				printf("                        이전 화면으로 돌아갑니다...                        ");
				break;
			}
		}
		else if (YorN == 'N' || YorN == 'n') {
			cout << endl << endl;
			printf("                                    ---                                    \n\n");
			Sleep(500);
			visitingInit();
			system("cls");
			return;
		}
	}
	Sleep(1500);
	system("cls");
	return;

}
void visitingInit() {
	system("cls");

	//현재 시간 구하기
	time_t curr_time;
	struct tm* curr_tm;
	curr_time = time(NULL);
	char buf[80];
	curr_tm = localtime(&curr_time);

	strftime(buf, sizeof(buf), "%Y.%m.%d.%X", curr_tm);
	//사용 변수
	char* carNum = (char*)malloc(sizeof(char) * 10);
	char* phoneNum = (char*)malloc(sizeof(char) * 20);
	int period;

	cout << endl << endl << endl << endl;

	cout << "                               방문 차량 등록                              ";
	cout << endl << endl << endl;
	int parkingAvailNum = parkingAvailableNum();
	if (parkingAvailNum == 0) {
		cout << "                         주차 구역 현황  |  0 / 100                         " << endl << endl;
		printf("%s             현재 주차장이 만차상태이므로 주차할 수 없습니다.             %s\n\n", RED, DEF);
		printf("                        이전 화면으로 돌아갑니다...                        ");
		Sleep(2000);
		return;
	}
	cout << "                   차량 번호 : ";
	cin >> carNum;
	int isCarNum = SearchCarNum(carNum, 1);
	if (isCarNum == -1) {
		printf("\n%s                        이미 등록된 차량번호입니다.                         %s\n", RED, DEF);
		printf("                        이전 화면으로 돌아갑니다...                        ");
		Sleep(1500);
		return;
	}
	cout << "                   전화 번호 : ";
	cin >> phoneNum;
	cout << endl << "                                    ---                                    " << endl << endl;
	printf("%s                방문 차량은 최대 3일까지 주차할 수 있습니다.               %s", GREEN, DEF);
	printf("%s                        3일일 경우 %s3%s만 입력해주세요.                       %s\n\n", GREEN, RED, GREEN, DEF);
	while (true) {
		gotoxy(0, 16);
		cout << "                                                  ";
		gotoxy(0, 19);
		cout << "                                                                             ";
		gotoxy(0, 16);
		cout << "                   방문 기간 : ";
		cin >> period;
		if (period > 0 && period <= 3) break;

		gotoxy(0, 19);
		printf("%s  1 ~ 3 사이의 숫자만 입력해주세요. 최대 머무를 수 있는 기간은 3일입니다.  %s", RED, DEF);
		Sleep(1500);
	}

	cout << endl << endl;
	VisitingCar car(carNum, phoneNum, 0, period, buf, NULL);
	visitingCarRegister(carNum, phoneNum, period);
	Sleep(1500);
	gotoParkingLot(car, parkingAvailNum);
	system("cls");
	return;
}
VisitingCar gotoParkingLot(VisitingCar& car, int availableNum) {
	system("cls");
	char* parkingSpace = (char*)malloc(sizeof(char) * 10);
	cout << endl << endl << endl << endl;
	cout << "                                   주차장                                  " << endl << endl;
	cout << "                         주차 가능 구역 현황 " << availableNum << " / 100" << endl << endl;
	DrewParkingLot();
	while (true) {
		gotoxy(0, 40);
		cout << "                                                                                ";
		gotoxy(0, 42);
		cout << "                                                                                ";
		gotoxy(0, 40);
		cout << "                     주차 구역을 입력해주세요 >> ";
		cin >> parkingSpace;
		char* car_num = car.getNum();
		int checkingParking = parkingLotState(1, parkingSpace, car_num, 1);
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
			car.setSpace(parkingSpace);
			cout << "                              주차되었습니다.                              ";
			VisitingState(1, car.getSpace(), car.getNum());
			break;
		}
	}
	Sleep(1500);
	VisitingScreen(car);
	system("cls");
	return car;
}
int VisitingScreen(VisitingCar& car) {
	system("cls");

	while (1) {
		cout << endl << endl << endl << endl;
		cout << "                             방문 차량 메뉴 창                             ";
		int menuCode = VisitingMenu();
		if (menuCode == 0) {
			visitingInfoScreen(car);
		}
		else if (menuCode == 1) {
			VisitingExitCar(car);
			return 0;
		}
		else if (menuCode == 2) {
			return 0;
		}
		system("cls");
	}
	return 0;

}

VisitingCar visitingInfoScreen(VisitingCar& car) {
	system("cls");
	cout << endl << endl << endl << endl;
	cout << "                            방문 차량 주차 관리                            " << endl << endl;
	cout << "                         * 뒤로가기 : 스페이스바                           " << endl << endl;
	cout << "                           차량 번호   : " << car.getNum() << endl;
	cout << "                           입차 날짜   : " << getDate(car.getNow(), 0) << endl;
	cout << "                        최대 주차 날짜 : " << getDate(car.getNow(), car.getPeriod()) << endl;
	while (1) {
		if (keyControl() == SUBMIT) {
			break;
		}
	}
	system("cls");
	return car;
}
void VisitingExitCar(VisitingCar& car) {
	system("cls");
	gotoxy(0, 6);
	cout << "                             방문 차량 : " << car.getNum() << endl << endl;
	cout << "                              출차되었습니다.                              " << endl;
	ExitVisitingCar(car.getNum());
	Sleep(2000);
	system("cls");
	return;
}