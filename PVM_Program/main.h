#ifndef MAIN_H
#define MAIN_H
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <conio.h>
using namespace std;

//키보드 값
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4
#define BACK 5
#define EXIT 6

//색깔
#define DEF "\033[0m"
#define RED  "\033[31m"
#define BLUE "\033[34m"
#define GREEN "\033[32m"
#define WHITE "\033[37m"
#define YELLOW "\033[33m"

class User {
protected:
	char* id = 0;
public:
	User() {}
	User(const char* _id) {
		id = new char[strlen(_id) + 1];
		strcpy(id, _id);
	}
};
class carInfo {
protected:
	char* carNum = 0;
	char* phoneNum = 0;
	int parkingState = 0;
	char* spaceNum = 0;
public:
	carInfo() {}
	carInfo(const char* num, const char* phone, int state) : parkingState(state) {
		carNum = new char[strlen(num) + 1];
		strcpy(carNum, num);
		phoneNum = new char[strlen(phone) + 1];
		strcpy(phoneNum, phone);
	}

	int parkingCheck() {
		cout << "                                   " << carNum;
		if (parkingState == 0) {
			//cout << "----------------------------------- 0000"  << carNum;
			cout << endl << endl;
			cout << "                             차량이 입차합니다.                            ";
			parkingState = 1;
			return 1;
		}
		else if (parkingState == 1) {
			cout << endl << endl;
			cout << "                             차량이 출차합니다.                            ";
			parkingState = 0;
			return 0;
		}
		return -1;
	}
	void showCarNum() {
		//cout << "-----------------------------차량 번호 : 0000 -----------------------------" << carNum;
		cout << "                             차량 번호 : " << carNum;
	}
	int getState() {
		return parkingState;

	}
	int showState() {
		if (parkingState == 1) {
			printf("                    차량번호 %s은/는 %s입차%s 상태입니다.                    ", carNum, BLUE, DEF);
			return 1;
		}
		else if (parkingState == 0) {
			printf("                    차량번호 %s은/는 %s출차%s 상태입니다.                    ", carNum, GREEN, DEF);
			parkingState = 0;
			return 0;
		}
		return 0;
	}
	char* getNum() { return carNum; }
	char* getSpace() { return spaceNum; }
	void setNum(char* num) {
		carNum = new char[strlen(num) + 1];
		strcpy(carNum, num);
	};
	void setSpace(char* space) {
		spaceNum = new char[strlen(space) + 1];
		strcpy(spaceNum, space);
	}
	void setphoneNum(char* phone) {
		phoneNum = new char[strlen(phone) + 1];
		strcpy(phoneNum, phone);
	};
	void setState(int state) {
		parkingState = state;
	}
};

class Resident : public carInfo {

	char* building = 0;
	char* unit = 0;
public:
	Resident() {}
	void setInfo(char* num, char* phoneNum, int state, const char* _building, const char* _unit, char* space)
	{
		carInfo(num, phoneNum, state);
		setNum(num);
		setSpace(space);
		setphoneNum(phoneNum);
		setState(state);
		building = new char[strlen(_building) + 1];
		strcpy(building, _building);
		unit = new char[strlen(_unit) + 1];
		strcpy(unit, _unit);
	}
};
class VisitingCar : public carInfo {
	int period;
	char* now;
public:
	VisitingCar() {}
	VisitingCar(const char* num, const char* phoneNum, int state, int period, char* _now, char* space)
		: carInfo(num, phoneNum, state), period(period) {
		now = new char[strlen(_now) + 1];
		strcpy(now, _now);
		cout << "                       방문 차량이 등록 되었습니다.                        ";
	}
	void setInfo(char* num, char* phoneNum, int period, char* _now, char* space) {
		setNum(num);
		setSpace(space);
		setphoneNum(phoneNum);
		setState(1);
		this->period = period;
		now = new char[strlen(_now) + 1];
		strcpy(now, _now);
	}
	int getPeriod() { return period; }
	char* getNow() { return now; }
	
};
//console.cpp
void init();
void gotoxy(int, int);
int keyControl();

//main.cpp
void mainTitle();
int mainMenu();
void login();
int afterLoginMain(const char*);
int afterLoginMainMenu();
void parkingLotScreen();
int MgtMenu();

//info.cpp
void infoScreen();

//parkingM.cpp
void parkingMgtScreen(const char*);

//carM.cpp
int carMgtScreen();

//mysql.cpp
int mysqlClose();
int mysqlMain();
int FindUser(const char*, const char*);
int SearchUserId(const char*);
int SearchCarNum(const char*);
int FindCarInfo(const char*);
int JoinUser(const char*, const char*);
int JoinCarInfo(const char* id, const char* num, const char* pNum, int building, int unit);
int DeleteCarInfo(const char*, const char*);
int ResidentList();
Resident getCarInfo(const char*, Resident&);
int visitingCarRegister(const char*, const char*, int);
int VisitingList();
int addParkingLot();
int parkingAvailableNum();
void DrewParkingLot(char* car_num);
int parkingLotState(int num, const char* space_num, const char* car_num, int);
int delParkingLot(int num);
void ResidentState(int what_s, const char* car_num, const char* space_num);
void VisitingState(int what_s, const char* car_num, const char* space_num);
void drewParkingLotToCarNum(int);
int ExitVisitingCar(char* car_num);
int isVisiter(char* car_num);
VisitingCar VisitingGetCarInfo(const char* car_num, VisitingCar& car);
char* getDate(char* date, int day);

//residentPM
void residentInit(const char* id);
Resident ParkingScreen(Resident&);
Resident MgtScreen(Resident& resi);
Resident gotoParkingLot(Resident&, int availableNum);

//visitingCar
void visitingInit();
VisitingCar gotoParkingLot(VisitingCar& car, int availableNum);
int VisitingScreen(VisitingCar& car);
int VisitingMenu();
VisitingCar visitingInfoScreen(VisitingCar& car);
void VisitingExitCar(VisitingCar& car);
void isVisitant();

//admin
void AdminParkingLotScreen();
#endif