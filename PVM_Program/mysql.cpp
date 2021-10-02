#include "main.h"
#include <string>
#include <mysql.h>
#define MYSQLIP "localhost"	
#define MYSQLUSER "root"
#define MYSQLPW "0620"	
#define MYSQLDB "pcm_db"	
MYSQL* mysql = mysql_init(NULL);
MYSQL_RES* res;
MYSQL_ROW row;
int fields;
int i;

void connect() {
	if (!mysql_real_connect(mysql, MYSQLIP, MYSQLUSER, MYSQLPW, MYSQLDB, 3306, NULL, 0))
		cout << "error" << endl;
	else {
		cout << "success" << endl;
		mysql_set_character_set(mysql, "euckr");
	}

}
//id ����
int SearchUserId(const char* id) {
	char query[100];
	sprintf(query, "select * from user where id = '%s'", id);
	mysql_query(mysql, query);
	res = mysql_store_result(mysql);
	fields = mysql_num_fields(res);

	int cnt = 0;
	while (row = mysql_fetch_row(res))
	{
		cnt++;
		for (i = 0; i < fields; i++) {
			printf("%s  ", row[i]);
		}
		cout << endl;
	}
	cout << cnt;
	return 0;
}
//login��
int FindUser(const char* id, const char* pw) {
	// ���̵� x : 0
	// ��� x : -1
	// ��� o : 1
	// ������ o : 2
	char query[100];
	sprintf(query, "select * from user where id = '%s'", id);
	mysql_query(mysql, query);
	res = mysql_store_result(mysql);
	fields = mysql_num_fields(res);

	int cnt = 0;
	if (row = mysql_fetch_row(res))
	{
		cnt++;
		//row[1] : ��� in ���ڵ�
		if (!strcmp(row[1], pw)) {
			if (!strcmp(row[2], "1")) return 2;
			return 1;
		}
		else return -1;

	}
	return 0;
}
//���� ���
int JoinUser(const char* id, const char* pw) {
	char query[100];
	sprintf(query, "INSERT INTO user VALUES('%s', '%s', 0)", id, pw);
	int state = mysql_query(mysql, query);
	if (state != 0) {
		return 1;
	}
	return 0;
}
//���� ���
int JoinCarInfo(const char* id, const char* num, const char* pNum, int building, int unit) {
	char query[100];
	sprintf(query, "INSERT INTO resident VALUES('%s', '%s', '%s', %d, %d)", id, num, pNum, building, unit);
	int state = mysql_query(mysql, query);
	if (state != 0) {
		return 1;
	}
	return 0;
}
//
Resident getCarInfo(const char* id, Resident& resi) {
	// 0 : ���� ����
	// -1 : ���� ����

	char* num;
	char* phoneNum;
	char* _id;
	char* _building;
	char* _unit;
	char query[100];
	sprintf(query, "select * from resident where id = '%s'", id);
	int state = mysql_query(mysql, query);
	res = mysql_store_result(mysql);
	fields = mysql_num_fields(res);
	row = mysql_fetch_row(res);

	//Resident(const char* num, const char* phoneNum, int state, const char* _id, const char* _building, const char* _unit)

	num = row[1];
	phoneNum = row[2];
	_building = row[3];
	_unit = row[4];
	//Resident resi(num, phoneNum, 0, id, _building, _unit);
	resi.setInfo(num, phoneNum, 0, _building, _unit);

	return resi;
}
//������ȣ�� ���� �ҷ�����
int FindCarInfo(const char* id) {
	// 0 : ���� ����
	// -1 : ���� ����
	char query[100];
	sprintf(query, "select building, unit, phone_num from resident where car_num = '%s'", id);
	mysql_query(mysql, query);
	res = mysql_store_result(mysql);
	fields = mysql_num_fields(res);

	int cnt = 0;
	if (row = mysql_fetch_row(res))
	{
		cnt++;
		//cout << "                  000�� / 000ȣ / ��ȭ��ȣ: 000-0000-0000                  " << endl;
		//cout << "                     " << row[0] << "�� / " << row[1] << "ȣ / ��ȭ��ȣ: " << row[2] << endl;
		cout << "                    " << row[0] << "��" << endl;
		cout << "                    " << row[1] << "ȣ" << endl;
		cout << "                    ��ȭ��ȣ : " << row[2] << endl;
		return 0;
	}
	return -1;
}
// ���� ���� ����
int DeleteCarInfo(const char* num) {
	char query[100];
	sprintf(query, "delete from resident where car_num = '%s'", num);

	int state = mysql_query(mysql, query);

	if (state != 0) {
		printf("error : %s", mysql_error(mysql));
		return 1;
	}
	return 0;
}
int ResidentList() {
	char query[100];
	sprintf(query, "select * from resident");
	int state = mysql_query(mysql, query);
	res = mysql_store_result(mysql);
	fields = mysql_num_fields(res);

	if (state != 0) return -1;
	int cnt = 0;
	printf("            ������ȣ      ��ȭ��ȣ      �� ��   ȣ �� \n");
	while (row = mysql_fetch_row(res))
	{
		cnt++;

		printf("           %7s  %14s  %7s  %6s", row[1], row[2], row[3], row[4]);

		cout << endl;
	}
	if (cnt == 0) return 1;
	return 0;
}
// �湮���� ���
int visitingCarRegister(const char* num, const char* pNum, int exit) {
	char query[100];
	sprintf(query, "INSERT INTO visiting VALUES('%s', '%s', NOW(), '%d')", num, pNum, exit);
	int state = mysql_query(mysql, query);
	if (state != 0) {
		printf("error : %s", mysql_error(mysql));
		return 1;
	}
	return 0;
}
//�湮 ���� ��ȸ
int VisitingList() {
	char query[100];
	sprintf(query, "select * from visiting");
	int state = mysql_query(mysql, query);
	res = mysql_store_result(mysql);
	fields = mysql_num_fields(res);

	if (state != 0) return -1;
	int cnt = 0;
	printf("        ������ȣ      ��ȭ��ȣ        ������¥    ���� ���� ��¥ \n");
	while (row = mysql_fetch_row(res))
	{
		cnt++;

		// ���� ���� ��¥ ���ϱ� 
		string str = row[2];
		string eixtDay = str.substr(9, 1);
		int exitDayI = stoi(eixtDay);
		int eixted = atoi(row[3]);
		string exit_day = to_string((exitDayI + eixted));
		string _finalExit;
		if(exitDayI + eixted >= 10)
			_finalExit = str.substr(0, 8) + exit_day;
		else _finalExit = str.substr(0, 8) + '0' + exit_day;
		char* finalExit = new char[_finalExit.length() + 1];
		strcpy(finalExit, _finalExit.c_str());
		char* equalExit = new char[_finalExit.length() + 1]; 
		strcpy(equalExit, finalExit);

		//���� ��¥�� ��� ���� ���ϱ�
		//�� ���� ��¥ ���ϱ�
		time_t curr_time;
		struct tm* curr_tm;
		curr_time = time(NULL);
		char buf[80];
		curr_tm = localtime(&curr_time);
		strftime(buf, sizeof(buf), "%Y%m%d", curr_tm);
		
		string ahk;
		for (i = 0; i < 10; i++) {
			if (isdigit(equalExit[i]) == 0) continue;
			ahk += equalExit[i];
		}
		
		// ��¥����¥�� ���ڷ� ����� ���� ���� ��¥�� �� Ŭ ��� ��ġ�� �� �ֵ��� ��. 
		if(buf < ahk)
			printf("       %7s    %14s  %13s %13s", row[0], row[1], row[2], finalExit);
		else printf("%s       %7s    %14s  %13s %13s", RED, row[0], row[1], row[2], finalExit);
		cout << endl;
	}
	if (cnt == 0) return 1;
	return 0;
}
int mysqlClose() {
	mysql_close(mysql);
	return 0;
}

int mysqlMain()
{
	connect();
	return 0;
}