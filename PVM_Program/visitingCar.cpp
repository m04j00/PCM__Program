#include "main.h"

void isVisitant() {
	system("cls");
	cout << endl << endl << endl << endl;
	cout << "                                 �湮 ����                                 " << endl << endl << endl;
	cout << "                   �����忡 ������ ������ �ֽ��ϱ�? Y / N                   " << endl;

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
			//cout << "                          ���� ��ȣ�� �Է����ּ���                         " << endl;
			cout << "                   ���� ��ȣ�� �Է����ּ��� : ";
			//cout << "                          >> ";
			cin >> input_num;
			cout << endl << endl;
			int success = isVisiter(input_num); // ����(-1), ����(0)
			if (success == 0) { // �α���
				printf("%s                       �湮 ������ Ȯ�εǾ����ϴ�.                         %s", GREEN, DEF);
				Sleep(1500);
				VisitingCar car;
				VisitingGetCarInfo(input_num, car);
				VisitingScreen(car);
				return;
			}
			else if (success == -1) {
				printf("%s          �Է��� ������ȣ�� ��ġ�ϴ� ������ȣ�� ã�� �� �����ϴ�.          %s\n\n", RED, DEF);
				printf("                        ���� ȭ������ ���ư��ϴ�...                        ");
				break;

			}
			else{
				printf("%s        �ش� ������ �ִ� ���� �Ⱓ�� �������ϴ�. ������ ��û�մϴ�.        %s\n\n", RED, DEF);
				Sleep(500);
				printf("%s                                 ���� �Ϸ�                                 %s\n\n", GREEN, DEF);
				printf("                        ���� ȭ������ ���ư��ϴ�...                        ");
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

	//���� �ð� ���ϱ�
	time_t curr_time;
	struct tm* curr_tm;
	curr_time = time(NULL);
	char buf[80];
	curr_tm = localtime(&curr_time);

	strftime(buf, sizeof(buf), "%Y.%m.%d.%X", curr_tm);
	//��� ����
	char* carNum = (char*)malloc(sizeof(char) * 10);
	char* phoneNum = (char*)malloc(sizeof(char) * 20);
	int period;

	cout << endl << endl << endl << endl;

	cout << "                               �湮 ���� ���                              ";
	cout << endl << endl << endl;
	int parkingAvailNum = parkingAvailableNum();
	if (parkingAvailNum == 0) {
		cout << "                         ���� ���� ��Ȳ  |  0 / 100                         " << endl << endl;
		printf("%s             ���� �������� ���������̹Ƿ� ������ �� �����ϴ�.             %s\n\n", RED, DEF);
		printf("                        ���� ȭ������ ���ư��ϴ�...                        ");
		Sleep(2000);
		return;
	}
	cout << "                   ���� ��ȣ : ";
	cin >> carNum;
	int isCarNum = SearchCarNum(carNum, 1);
	if (isCarNum == -1) {
		printf("\n%s                        �̹� ��ϵ� ������ȣ�Դϴ�.                         %s\n", RED, DEF);
		printf("                        ���� ȭ������ ���ư��ϴ�...                        ");
		Sleep(1500);
		return;
	}
	cout << "                   ��ȭ ��ȣ : ";
	cin >> phoneNum;
	cout << endl << "                                    ---                                    " << endl << endl;
	printf("%s                �湮 ������ �ִ� 3�ϱ��� ������ �� �ֽ��ϴ�.               %s", GREEN, DEF);
	printf("%s                        3���� ��� %s3%s�� �Է����ּ���.                       %s\n\n", GREEN, RED, GREEN, DEF);
	while (true) {
		gotoxy(0, 16);
		cout << "                                                  ";
		gotoxy(0, 19);
		cout << "                                                                             ";
		gotoxy(0, 16);
		cout << "                   �湮 �Ⱓ : ";
		cin >> period;
		if (period > 0 && period <= 3) break;

		gotoxy(0, 19);
		printf("%s  1 ~ 3 ������ ���ڸ� �Է����ּ���. �ִ� �ӹ��� �� �ִ� �Ⱓ�� 3���Դϴ�.  %s", RED, DEF);
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
	cout << "                                   ������                                  " << endl << endl;
	cout << "                         ���� ���� ���� ��Ȳ " << availableNum << " / 100" << endl << endl;
	DrewParkingLot();
	while (true) {
		gotoxy(0, 40);
		cout << "                                                                                ";
		gotoxy(0, 42);
		cout << "                                                                                ";
		gotoxy(0, 40);
		cout << "                     ���� ������ �Է����ּ��� >> ";
		cin >> parkingSpace;
		char* car_num = car.getNum();
		int checkingParking = parkingLotState(1, parkingSpace, car_num, 1);
		gotoxy(0, 42);
		if (checkingParking == -1) {
			printf("%s        ���� ������ �߸� �Է��߽��ϴ�. �ٽ� �Է����ּ���.%s", RED, DEF);
			Sleep(1500);
		}
		else if (checkingParking == 1) {
			printf("%s        �̹� ������ �����Դϴ�. �ٽ� �Է����ּ���.%s", RED, DEF);
			Sleep(1500);
		}
		else if (checkingParking == 0) {
			car.setSpace(parkingSpace);
			cout << "                              �����Ǿ����ϴ�.                              ";
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
		cout << "                             �湮 ���� �޴� â                             ";
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
	cout << "                            �湮 ���� ���� ����                            " << endl << endl;
	cout << "                         * �ڷΰ��� : �����̽���                           " << endl << endl;
	cout << "                           ���� ��ȣ   : " << car.getNum() << endl;
	cout << "                           ���� ��¥   : " << getDate(car.getNow(), 0) << endl;
	cout << "                        �ִ� ���� ��¥ : " << getDate(car.getNow(), car.getPeriod()) << endl;
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
	cout << "                             �湮 ���� : " << car.getNum() << endl << endl;
	cout << "                              �����Ǿ����ϴ�.                              " << endl;
	ExitVisitingCar(car.getNum());
	Sleep(2000);
	system("cls");
	return;
}