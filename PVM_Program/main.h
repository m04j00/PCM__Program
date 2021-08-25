#ifndef MAIN_H
#define MAIN_H
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

//console.cpp
void init();
void gotoxy(int, int);
int keyControl();

//main.cpp
void mainTitle();
int mainMenu();

//info.cpp
void infoScreen();

//parkingM.cpp
void parkingMgtScreen();

//carM.cpp
int carMgtScreen();

#endif