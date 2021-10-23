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
//id 유무
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
//login용
int FindUser(const char* id, const char* pw) {
	// 아이디 x : 0
	// 비번 x : -1
	// 비번 o : 1
	// 관리자 o : 2
	char query[100];
	sprintf(query, "select * from user where id = '%s'", id);
	mysql_query(mysql, query);
	res = mysql_store_result(mysql);
	fields = mysql_num_fields(res);

	int cnt = 0;
	if (row = mysql_fetch_row(res))
	{
		cnt++;
		//row[1] : 비번 in 레코드
		if (!strcmp(row[1], pw)) {
			if (!strcmp(row[2], "1")) return 2;
			return 1;
		}
		else return -1;

	}
	return 0;
}
//계정 등록
int JoinUser(const char* id, const char* pw) {
	char query[100];
	sprintf(query, "INSERT INTO user VALUES('%s', '%s', 0)", id, pw);
	int state = mysql_query(mysql, query);
	if (state != 0) {
		return 1;
	}
	return 0;
}
//차량 등록
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
	// 0 : 계정 있음
	// -1 : 계정 없음

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
//차량번호로 정보 불러오기
int FindCarInfo(const char* id) {
	// 0 : 계정 있음
	// -1 : 계정 없음
	char query[100];
	sprintf(query, "select building, unit, phone_num from resident where car_num = '%s'", id);
	mysql_query(mysql, query);
	res = mysql_store_result(mysql);
	fields = mysql_num_fields(res);

	int cnt = 0;
	if (row = mysql_fetch_row(res))
	{
		cnt++;
		//cout << "                  000동 / 000호 / 전화번호: 000-0000-0000                  " << endl;
		//cout << "                     " << row[0] << "동 / " << row[1] << "호 / 전화번호: " << row[2] << endl;
		cout << "                    " << row[0] << "동" << endl;
		cout << "                    " << row[1] << "호" << endl;
		cout << "                    전화번호 : " << row[2] << endl;
		return 0;
	}
	return -1;
}
// 차량 정보 삭제
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
	printf("            차량번호      전화번호      동 수   호 수 \n");
	while (row = mysql_fetch_row(res))
	{
		cnt++;

		printf("           %7s  %14s  %7s  %6s", row[1], row[2], row[3], row[4]);

		cout << endl;
	}
	if (cnt == 0) return 1;
	return 0;
}
// 방문차량 기록
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
//방문 차량 조회
int VisitingList() {
	char query[100];
	sprintf(query, "select * from visiting order by date asc");
	int state = mysql_query(mysql, query);
	res = mysql_store_result(mysql);
	fields = mysql_num_fields(res);

	if (state != 0) return -1;
	int cnt = 0;
	printf("        차량번호      전화번호        입차날짜    예상 출차 날짜 \n");
	while (row = mysql_fetch_row(res))
	{
		cnt++;

		// 예상 출차 날짜 구하기 
		string str = row[2]; // 입차 날짜 2021-10-07
		int eixtDay = stoi(str.substr(8, 2)); // 일
		int eixteNum = atoi(row[3]); // 일 수 
		string exit_day = to_string((eixtDay + eixteNum)); // 입차 일 + 출차 일 수
		string _finalExit;
		if(eixtDay + eixteNum >= 10)
			_finalExit = str.substr(0, 8) + exit_day;
		else _finalExit = str.substr(0, 8) + '0' + exit_day;
		char* finalExit = new char[_finalExit.length() + 1];
		strcpy(finalExit, _finalExit.c_str());
		char* equalExit = new char[_finalExit.length() + 1]; 
		strcpy(equalExit, finalExit);

		//출차 날짜를 어긴 차량 구하기
		//중 현재 날짜 구하기
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
		// 날짜월날짜를 숫자로 만들어 예상 출차 날짜가 더 클 경우 조치할 수 있도록 함. 
		// 오늘날짜 == 예상 출차 날짜 같을 경우 나가는 날임을 알림
		// 오늘날짜 > 예상 출차 날짜일 경우 출차 조취 시킴
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
				printf("%s                           방문 차량 %s 출차 조취", BLUE, row[0]);
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
			sprintf(query, "INSERT INTO parking_lot(space_num, state) VALUES('%s', %d)", num, 0);
			int state = mysql_query(mysql, query);
			if (state != 0) return -1;
		}

	}
	return 0;
}
void DrewParkingLot() {
	char query[100];
	sprintf(query, "select * from parking_lot");
	int state = mysql_query(mysql, query);
	res = mysql_store_result(mysql);
	fields = mysql_num_fields(res);
	int cnt = 0;
	while (row = mysql_fetch_row(res))
	{
		if (row[2] == (string)"0") printf("   [  %s%s%s  ]  ", GREEN, row[0], DEF);
		else if (row[2] == (string)"1") printf("   [  %s%s%s  ]  ", RED, row[0], DEF);
		cnt++;
		if (cnt % 5  == 0) cout << endl;
		if (cnt % 10  == 0) cout << endl;
	}
}
//주차 가능 구역 개수
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
int parkingLotState(int num, char* space_num, char* car_num) {
	// -1 : 잘못 입력
	// 0 : 주차 성공
	// 1 : 이미 주차된 구역
	if (num == 1) { // 입차 시에만 코드블록 동작
		char query1[100];
		sprintf(query1, "SELECT * FROM parking_lot where space_num = '%s'", space_num); // 입력된 주차구역이 존재하는 레코드인지

		int state1 = mysql_query(mysql, query1);
		res = mysql_store_result(mysql);
		row = mysql_fetch_row(res);
		if (row == nullptr) return -1; // row가 nullptr이면 존재하지 않는 주차구역
	}
	
	mysql_free_result(res);
	char query[100];
	sprintf(query, "UPDATE parking_lot SET car_num = '%s', state = %d WHERE space_num = '%s'", car_num, num, space_num); 

	int state = mysql_query(mysql, query);
	res = mysql_store_result(mysql);
	my_ulonglong rows = mysql_affected_rows(mysql); // update 적용된 레코드의 수 반환
	if (rows == 0) { // rows가 0일 경우 이미 주차된 구역
		return 1;
	}
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