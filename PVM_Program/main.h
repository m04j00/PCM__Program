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

class User {
	char* id;
	char* pw;
public: 
	User(const char* _id, const char* _pw) {
		id = new char[strlen(_id) + 1];
		strcpy(id, _id);
		pw = new char[strlen(_pw) + 1];
		strcpy(pw, _pw);
	}
};
class carInfo {
	char* carNum;
	char* phoneNum;
	int parkingState;
public:
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
			return 1;
		}
		else if (parkingState == 1) {
			cout << endl << endl;
			cout << "                             차량이 출차합니다.                            ";
			return 0;
		}
	}
	void showCarNum() {
		//cout << "-----------------------------차량 번호 : 0000 -----------------------------" << carNum;
		cout << "                             차량 번호 : " << carNum;
	}
	int getSate() { return parkingState; }
	void setSate(int state) { 
		cout << endl << "class : " << parkingState;
		parkingState = state;
		cout << endl << "class : " << parkingState;
	}
};

class Resident : public carInfo, User {
	char* building;
	char* unit;
public:
	Resident(const char* num, const char* phoneNum, int state, const char* _id, const char* _pw, const char* _building, const char* _unit)
		: carInfo(num, phoneNum, state), User(_id, _pw) {
		building = new char[strlen(_building) + 1];
		strcpy(building, _building);
		unit = new char[strlen(_unit) + 1];
		strcpy(unit, _unit);
	}
};

class NonResident : public carInfo {
public:
	NonResident(const char* num, const char* phoneNum, int state) : carInfo(num, phoneNum, state) {}
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
int FindCarInfo(const char*);
int JoinUser(const char*, const char*);
int JoinCarInfo(const char* id, const char* num, const char* pNum, int building, int unit);
int DeleteCarInfo(const char*);
int ResidentList();
#endif