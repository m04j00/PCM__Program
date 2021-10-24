#include "main.h"

void visitingInit() {
	system("cls");

	//���� �ð� ���ϱ�
	time_t curr_time;
	struct tm* curr_tm;
	curr_time = time(NULL);
	char buf[80];
	curr_tm = localtime(&curr_time);
	
	strftime(buf, sizeof(buf), "%Y.%m.%d.%X", curr_tm);
	cout << buf << endl;
	//��� ����
	char* carNum = (char*)malloc(sizeof(char) * 10);
	char* phoneNum = (char*)malloc(sizeof(char) * 20);
	int period;

	cout << endl << endl << endl << endl;

	cout << "                               �湮 ���� ���                              " << endl << endl << endl;

	cout << "                   ���� ��ȣ : ";
	cin >> carNum;
	cout << "                   ��ȭ ��ȣ : ";
	cin >> phoneNum;
	cout << "    �湮 �Ⱓ (3�� �� 3 �Է�) : ";
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
	cout << "                            �湮 ���� ���� ����                            " << endl << endl << endl;
	car.showCarInfo();
	while (1) {
		if (keyControl() == SUBMIT) {
			break;
		}
	}
	return car;
}