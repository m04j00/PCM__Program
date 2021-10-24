#include "main.h"

void visitingInit() {
	system("cls");

	//현재 시간 구하기
	time_t curr_time;
	struct tm* curr_tm;
	curr_time = time(NULL);
	char buf[80];
	curr_tm = localtime(&curr_time);
	
	strftime(buf, sizeof(buf), "%Y.%m.%d.%X", curr_tm);
	cout << buf << endl;
	//사용 변수
	char* carNum = (char*)malloc(sizeof(char) * 10);
	char* phoneNum = (char*)malloc(sizeof(char) * 20);
	int period;

	cout << endl << endl << endl << endl;

	cout << "                               방문 차량 등록                              " << endl << endl << endl;

	cout << "                   차량 번호 : ";
	cin >> carNum;
	cout << "                   전화 번호 : ";
	cin >> phoneNum;
	cout << "    방문 기간 (3일 → 3 입력) : ";
	cin >> period;

	cout << endl << endl;
	VisitingCar car(carNum, phoneNum, 0, period, buf, NULL);
	visitingCarRegister(carNum, phoneNum, period);
	Sleep(1000);
	visitingScreen(car);
	system("cls");
	return;
}
VisitingCar visitingScreen(VisitingCar &car) {
	system("cls");
	cout << endl << endl << endl << endl;
	cout << "                            방문 차량 주차 관리                            " << endl << endl << endl;
	car.showCarInfo();
	while (1) {
		if (keyControl() == SUBMIT) {
			break;
		}
	}
	return car;
}