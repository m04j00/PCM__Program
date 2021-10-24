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
	int isCarNum = SearchCarNum(carNum);
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
	Sleep(1000);
	gotoParkingLot(car, parkingAvailNum);
	system("cls");
	visitingInfoScreen(car);
	system("cls");
	return;
}
VisitingCar gotoParkingLot(VisitingCar& car, int availableNum) {
	system("cls");
	char* parkingSpace = (char*)malloc(sizeof(char) * 10);
	cout << endl << endl << endl << endl;
	cout << "                                   ������                                  " << endl << endl;
	cout << "                         ���� ���� ���� ��Ȳ " << availableNum << " / 100" << endl << endl;
	DrewParkingLot(NULL);
	while (true) {
		gotoxy(0, 40);
		cout << "                                                                                ";
		gotoxy(0, 42);
		cout << "                                                                                ";
		gotoxy(0, 40);
		cout << "                     ���� ������ �Է����ּ��� >> ";
		cin >> parkingSpace;
		int checkingParking = parkingLotState(1, parkingSpace, car.getNum());
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
	while (1) {
		if (keyControl() == SUBMIT) {
			break;
		}
		system("cls");
	}
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
			return 0;
		}
		else if (menuCode == 2) {
			return 0;
		}
		system("cls");
	}
	return 0;

}
int VisitingMenu() {
	int x = 31;
	int y = 7;
	gotoxy(x - 2, y);
	cout << ">      ����  ����      ";
	gotoxy(x, y + 1);
	cout << "      ����  �ϱ�      ";
	gotoxy(x, y + 2);
	cout << "������ ���¿��� ������";

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
			if (y < 9) {
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
VisitingCar visitingInfoScreen(VisitingCar& car) {
	system("cls");
	cout << endl << endl << endl << endl;
	cout << "                            �湮 ���� ���� ����                            " << endl << endl << endl;
	car.showCarInfo();
	while (1) {
		if (keyControl() == SUBMIT) {
			break;
		}
	}
	VisitingScreen(car);
	system("cls");
	return car;
}