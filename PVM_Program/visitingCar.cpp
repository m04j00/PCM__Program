#include "main.h"

void visitingScreen() {
	system("cls");
	cout << endl << endl << endl << endl;
	char* carNum = (char*)malloc(sizeof(char) * 10);
	char* phoneNum = (char*)malloc(sizeof(char) * 20);
	int period;
	cout << "                               �湮 ���� ���                              " << endl << endl << endl;

	cout << "                   ���� ��ȣ : ";
	cin >> carNum;
	cout << "                   ��ȭ ��ȣ : ";
	cin >> phoneNum;
	cout << "    �湮 �Ⱓ (3�� �� 3 �Է�) : ";
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