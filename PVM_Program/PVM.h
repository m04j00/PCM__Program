#ifndef PVM_H
#define PVM_H
#include <iostream>
#include <Windows.h>
#include <conio.h>

//키보드 값
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4
#define BACK 5
#define EXIT 6

using namespace std;
void init();
void gotoxy(int, int);
int keyControl();
void titleText();
int mainMenu();
void infoDraw();

#endif