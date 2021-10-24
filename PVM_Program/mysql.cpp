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
	char* car_state;
	char* space;
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
	space = row[5];
	car_state = row[6];
	//Resident resi(num, phoneNum, 0, id, _building, _unit);
	resi.setInfo(num, phoneNum, atoi(car_state), _building, _unit, space);

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
	cout << "      ����  ��ȣ        ��ȭ ��ȣ       �� ��     ȣ ��     ����  ����      " << endl;
	while (row = mysql_fetch_row(res))
	{
		cnt++;
		if (row[6] == (string)"0") printf("        %5s%22s%9s%10s%13s", row[1], row[2], row[3], row[4], "����");
		else printf("%s        %5s%22s%9s%10s%13s%s", BLUE, row[1], row[2], row[3], row[4], "����", DEF);

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
	sprintf(query, "select * from visiting order by date asc");
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
		string str = row[2]; // ���� ��¥ 2021-10-07
		int eixtDay = stoi(str.substr(8, 2)); // ��
		int eixteNum = atoi(row[3]); // �� �� 
		string exit_day = to_string((eixtDay + eixteNum)); // ���� �� + ���� �� ��
		string _finalExit;
		if (eixtDay + eixteNum >= 10)
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
		char today[80];
		curr_tm = localtime(&curr_time);
		strftime(today, sizeof(today), "%Y%m%d", curr_tm);

		//string tomorrow;
		//tomorrow += to_string(curr_tm->tm_year + 1900) += to_string(curr_tm->tm_mon + 1) += to_string(curr_tm->tm_mday + 1);

		string ahk;
		for (i = 0; i < 10; i++) {
			if (isdigit(equalExit[i]) == 0) continue;
			ahk += equalExit[i];
		}
		// ��¥����¥�� ���ڷ� ����� ���� ���� ��¥�� �� Ŭ ��� ��ġ�� �� �ֵ��� ��. 
		// ���ó�¥ == ���� ���� ��¥ ���� ��� ������ ������ �˸�
		// ���ó�¥ > ���� ���� ��¥�� ��� ���� ���� ��Ŵ
		if (today == ahk) {
			printf("%s       %7s    %14s  %13s %13s", RED, row[0], row[1], row[2], finalExit);
			printf("%s", DEF);
		}
		else if (today > ahk) {
			char del[100];
			sprintf(del, "delete from visiting where car_num = '%s'", row[0]);
			int state = mysql_query(mysql, del);
			if (state != 0) {
				printf("error : %s", mysql_error(mysql));
			}
			else {
				printf("       %7s    %14s  %13s %13s\n", row[0], row[1], row[2], finalExit);
				printf("%s                           �湮 ���� %s ���� ����", BLUE, row[0]);
				printf("%s", DEF);
			}
		}
		else {
			printf("       %7s    %14s  %13s %13s", row[0], row[1], row[2], finalExit);
		}
		cout << endl;
	}
	if (cnt == 0) return 1;
	return 0;
}
int addParkingLot() {
	char query[100];
	for (char j = 'A'; j <= 'E'; j++) {
		for (int k = 1; k <= 20; k++) {
			char num[5];
			if (k < 10) sprintf(num, "%c%d%d%d", j, 0, 0, k);
			else sprintf(num, "%c%d%d", j, 0, k);
			cout << num << endl;
			sprintf(query, "INSERT INTO parking_lot(space_num, car_num, state, car_info) VALUES('%s', 'not', %d, 0)", num, 0);
			int state = mysql_query(mysql, query);
			if (state != 0) return -1;
		}

	}
	return 0;
}
void DrewParkingLot(char* car_num) {
	char query[100];
	sprintf(query, "select * from parking_lot");
	int state = mysql_query(mysql, query);
	res = mysql_store_result(mysql);
	fields = mysql_num_fields(res);
	int cnt = 0;

	if (car_num != NULL) {
		//if (row[1] == car_num) cout << "true" << endl;
		int num = -1;

		//while (row = mysql_fetch_row(res))
		//{
		//	if (strcmp(row[1], car_num) == 0) num = 0;
		//	else num = -1;
		//	if(num == 0) printf("   [  %s%s%s  ]  ", WHITE , row[0], DEF);
		//	else if (row[2] == (string)"0") printf("   [  %s%s%s  ]  ", GREEN, row[0], DEF);
		//	else if (row[2] == (string)"1") printf("   [  %s%s%s  ]  ", RED, row[0], DEF);
		//	cnt++;
		//	if (cnt % 5 == 0) cout << endl;
		//	if (cnt % 10 == 0) cout << endl;
		//}
	}
	else {
		while (row = mysql_fetch_row(res))
		{
			if (row[3] == (string)"1") printf("   [  %s%s%s  ]  ", BLUE, row[0], DEF);
			else if (row[2] == (string)"0") printf("   [  %s%s%s  ]  ", GREEN, row[0], DEF);
			else if (row[2] == (string)"1") printf("   [  %s%s%s  ]  ", RED, row[0], DEF);
			cnt++;
			if (cnt % 5 == 0) cout << endl;
			if (cnt % 10 == 0) cout << endl;
		}
	}


}
//���� ���� ���� ����
int parkingAvailableNum() {
	char query[100];
	sprintf(query, "SELECT count(if (state = 0, state, null)) FROM parking_lot");
	int state = mysql_query(mysql, query);
	res = mysql_store_result(mysql);
	fields = mysql_num_fields(res);
	if (row = mysql_fetch_row(res))
	{

		return atoi(row[0]);
	}
}
int parkingLotState(int num, char* space_num, const char* car_num) {
	// -1 : �߸� �Է�
	// 0 : ���� ����
	// 1 : �̹� ������ ����
	if (num == 1) { // ���� �ÿ��� �ڵ��� ����
		char query1[100];
		sprintf(query1, "SELECT * FROM parking_lot where space_num = '%s'", space_num); // �Էµ� ���������� �����ϴ� ���ڵ�����

		int state1 = mysql_query(mysql, query1);
		res = mysql_store_result(mysql);
		row = mysql_fetch_row(res);
		if (row == nullptr) return -1; // row�� nullptr�̸� �������� �ʴ� ��������
	}
	mysql_free_result(res);
	char query[100];
	sprintf(query, "UPDATE parking_lot SET car_num = '%s', state = %d WHERE space_num = '%s' AND state = %d", car_num, num, space_num, !num);

	int state = mysql_query(mysql, query);
	res = mysql_store_result(mysql);
	my_ulonglong rows = mysql_affected_rows(mysql); // update ����� ���ڵ��� �� ��ȯ
	if (rows == 0) { // rows�� 0�� ��� �̹� ������ ����
		return 1;
	}
	return 0;
}
//������ �������� ����
int delParkingLot(int num) {
	//case 1 : �湮���� �������� ����
	char query[100];
	switch (num) {
	case 1: sprintf(query, "UPDATE parking_lot SET car_num = NULL, state = 0, car_info = 0 where car_info = %d", num); break;
	case 2: sprintf(query, "delete from parking_lot where car_info = %d", 1); break;
	}

	int state = mysql_query(mysql, query);

	if (state != 0) { return -1; }
	return 0;
}
//���� ���� �� ���� ���� ����
void ResidentState(int what_s, const char* space_num, const char* car_num) {
	char query[100];
	sprintf(query, "UPDATE resident SET parking_state = %d, parking_space_num = '%s' WHERE car_num = '%s'", what_s, space_num, car_num);
	int state = mysql_query(mysql, query);
	if (state != 0) cout << mysql_error(mysql);
}
//��������������������
//��  A001  ��
//��  0000  ��
//��������������������
void drewParkingLotToCarNum() {
	char* ptr_space[100]; // ���� ���� �̸� ��� �迭
	char* ptr_car[100]; // ������ ���� ��ȣ ��� �迭
	int arr_state[100] = { 0, }; // ���� ���¶�� 1 �ƴϸ� 0
	int arr_info[100] = { 0, }; // �湮 �����̶�� 1 ���ֹθ� 0
	char query[100];

	sprintf(query, "select * from parking_lot");
	int state = mysql_query(mysql, query);
	res = mysql_store_result(mysql);
	fields = mysql_num_fields(res);
	int cnt = 0;
	i = 0;
	while (row = mysql_fetch_row(res)) {
		ptr_space[i] = row[0];
		if (row[1] == NULL || row[1] == (string)"NULL") {
			ptr_car[i] = new char(5);
			strcpy(ptr_car[i], "    ");
		}
		else ptr_car[i] = row[1];
		if (row[2] == (string)"1") arr_state[i] = 1;
		if (row[3] == (string)"1") arr_info[i] = 1;
		//cout << ptr_space[i] << "   " << ptr_car[i] << "   " << arr_state[i] << "   " << arr_info[i] << endl;
		i++;
	}
	int k = 0; // ���� ����
	int j = 0; // ���� ��ȣ 
	int what_s = 0; // state
	int what_i = 0; // info
	for (i = 0; i < 20; i++) {
		cout << " ������������������������" << "  " << " ������������������������" << "  " << " ������������������������" << "  " << " ������������������������" << "  " << " ������������������������" << endl;
		for (int z = 0; z < 5; z++) {
			if (arr_info[k] == 1) {
				printf(" ��   %s%s%s   ��  ", BLUE, ptr_space[k++], DEF);
				what_i = 1;
			}
			else if (arr_state[k] == 1) {
				printf(" ��   %s%s%s   ��  ", RED, ptr_space[k++], DEF);
				what_s = 1;
			}
			else printf(" ��   %s%s%s   ��  ", GREEN, ptr_space[k++], DEF);
		}
		cout << endl;
		for (int z = 0; z < 5; z++) {
			if (what_i == 1) {
				printf(" ��   %s%s%s   ��  ", BLUE, ptr_car[j++], DEF);
				what_i = 1;
			}
			else if (what_s == 1) {
				printf(" ��   %s%s%s   ��  ", RED, ptr_car[j++], DEF);
				what_s = 1;
			}
			else printf(" ��   %s%s%s   ��  ", GREEN, ptr_car[j++], DEF);
		}
		cout << endl;
		cout << " ������������������������  " << " ������������������������  " << " ������������������������  " << " ������������������������  " << " ������������������������  " << endl;
	}
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