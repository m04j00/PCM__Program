create database pcm_db;
use pcm_db;
create table user(
	id VARCHAR(20) PRIMARY KEY,
	pw VARCHAR(20) NOT NULL,
	-- 입주민 0, 관리자 1
	admin BOOLEAN NOT NULL
);

create table resident(
	id VARCHAR(20) NOT NULL,
	car_num VARCHAR(10) PRIMARY KEY,
	phone_num VARCHAR(14) NOT NULL,
	building SMALLINT(4) NOT NULL,
	unit SMALLINT(4) NOT NULL,
	parking_space_num VARCHAR(10),
	parking_state BOOLEAN
);

create table visiting(
	car_num VARCHAR(10) PRIMARY KEY,
	phone_num VARCHAR(14) NOT NULL,
	date DATE,
	exit_date SMALLINT(2),
	parking_space_num VARCHAR(10),
	parking_state BOOLEAN
);

create table parking_lot(
	space_num VARCHAR(10) PRIMARY KEY,
	car_num VARCHAR(10),
	state BOOLEAN NOT NULL,
	car_info SMALLINT(2)
);


-- 관리자 계정
insert into user values ('admin1','aaaa', 1);
insert into user values ('admin2', 'ssss', 1);

-- 입주민 계정
insert into user values ('101', '101', 0);
insert into user values ('resident', 'aaaa', 0);

-- 방문 차량
insert into visiting values ('1122', '010-1122-1122', '2021-10-20', 2);
insert into visiting values ('1133', '010-1133-1133', '2021-10-19', 2);
insert into visiting values ('1144', '010-1144-1144', '2021-10-19', 3);
insert into visiting values ('1155', '010-1155-1155', '2021-10-19', 1);