#include "main.h"
   
void infoScreen() {
	system("cls");
	cout << endl << endl << endl << endl;
	cout << "                                 ���� ���                                 " << endl << endl;
	cout << "                           �̵� : ȭ��ǥ �� �� �� ��                          " << endl << endl;
	cout << "                           ���� : ����                           " << endl << endl << endl;
	
	cout << "                                    ---                                    " << endl;
		cout << "                         * �ڷΰ��� : �����̽���                           " << endl << endl << endl << endl;
	cout << "       1. �α���                                 " << endl << endl;
	cout << "       ������ : ������  ��ϵ�  ��������  �α�����  ��  �ֽ��ϴ�.        " << endl;
	cout << "       ���ֹ� : �����ڸ� ���� ��ϵ� �������� �α����� �� �ֽ��ϴ�.      " << endl << endl << endl;

	cout << "       1-2. ���ֹ� ��� ���               " << endl;
	cout << "       * �����ڸ��� ���ֹ��� ����� �� �ֽ��ϴ�.         " << endl << endl;
	cout << "       1) �����ڰ� ������ �������� �α����մϴ�.        " << endl;
	cout << "       2) ���ֹ� ���� ���� -> ���� ����� ���ϴ�.         " << endl;
	cout << "       3) ���ֹ� ������ �°� ������ �Է��մϴ�.     " << endl << endl << endl;

	cout << "       2. �湮 ����                       " << endl << endl;
	cout << "       * �湮 ������ �ִ� �Ϸ絿�� ������ �����մϴ�.       " << endl;
	cout << "       1) ���� ������ �Է��ϰ� �ִ� ������ ��¥�� �Է��մϴ�.      " << endl;
	cout << "       2) 20�ϳ� ���� �� 21�ϱ��� �������� �ʾҴٸ�" << endl;
	cout << "          ������ �������� ������ ���ε˴ϴ�." << endl;
	cout << "       3) �������� ���ֹ� �켱���� ������ �����ϸ�,       " << endl;
	cout << "          ������ ��� �湮 ���� ������ ���� ������ ��û�˴ϴ�.      " << endl << endl << endl;


	while (1) {
		if (keyControl() == SUBMIT) {
			break;
		}
	}
}