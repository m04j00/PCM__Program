#include "main.h"
   
void infoScreen() {
	system("cls");
	cout << endl << endl << endl << endl;
	cout << "                                 조작 방법                                 " << endl << endl;
	cout << "                           이동 : 화살표 ↑ ↓ ← →                          " << endl << endl;
	cout << "                           선택 : 엔터                           " << endl << endl << endl;
	
	cout << "                                    ---                                    " << endl;
		cout << "                         * 뒤로가기 : 스페이스바                           " << endl << endl << endl << endl;
	cout << "       1. 로그인                                 " << endl << endl;
	cout << "       관리자 : 사전에  등록된  계정으로  로그인할  수  있습니다.        " << endl;
	cout << "       입주민 : 관리자를 통해 등록된 계정으로 로그인할 수 있습니다.      " << endl << endl << endl;

	cout << "       1-2. 입주민 등록 방법               " << endl;
	cout << "       * 관리자만이 입주민을 등록할 수 있습니다.         " << endl << endl;
	cout << "       1) 관리자가 관리자 계정으로 로그인합니다.        " << endl;
	cout << "       2) 입주민 차량 관리 -> 차량 등록을 들어갑니다.         " << endl;
	cout << "       3) 입주민 정보에 맞게 정보를 입력합니다.     " << endl << endl << endl;

	cout << "       2. 방문 차량                       " << endl << endl;
	cout << "       * 방문 차량은 최대 하루동안 주차가 가능합니다.       " << endl;
	cout << "       1) 차량 정보를 입력하고 최대 주차할 날짜를 입력합니다.      " << endl;
	cout << "       2) 20일날 입차 후 21일까지 출차하지 않았다면" << endl;
	cout << "          관리자 권한으로 차량이 견인됩니다." << endl;
	cout << "       3) 주차장은 입주민 우선으로 주차가 가능하며,       " << endl;
	cout << "          만차일 경우 방문 차량 순으로 차량 출차가 요청됩니다.      " << endl << endl << endl;


	while (1) {
		if (keyControl() == SUBMIT) {
			break;
		}
	}
}