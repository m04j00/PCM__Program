#include "main.h"

void visitingScreen() {
	system("cls");
	cout << endl << endl << endl << endl;
	char* carNum = (char*)malloc(sizeof(char) * 10);
	char* phoneNum = (char*)malloc(sizeof(char) * 20);
	int period;
	cout << "                               방문 차량 등록                              " << endl << endl << endl;

	cout << "                   차량 번호 : ";
	cin >> carNum;
	cout << "                   전화 번호 : ";
	cin >> phoneNum;
	cout << "    방문 기간 (3일 → 3 입력) : ";
	cin >> period;

	//VisitingCar(const char* num, const char* phoneNum, int state, int period) : carInfo(num, phoneNum, state), period(period) {
	cout << endl << endl;
	VisitingCar(carNum, phoneNum, 0, period);
	while (1) {
		if (keyControl() == SUBMIT) {
			break;
		}
	}
	return;
}