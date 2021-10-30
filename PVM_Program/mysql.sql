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
insert into user values ('1001', '1001', 0);
insert into resident values ('1001', '1001', '010-5135-3215', '101','501','A007',1);
insert into parking_lot values ('A007', '1001', 1, 0);
insert into user values ('5252', '5252', 0);
insert into resident values ('5252', '5252', '010-0125-8321', '103','201','B001',1);
insert into parking_lot values ('B001', '5252', 1, 0);

-- 방문 차량
insert into visiting values ('1122', '010-1122-1122', '2021-11-09', 2, 'D001', 1);
insert into visiting values ('1133', '010-1133-1133', '2021-11-08', 2, 'B009', 1);
UPDATE parking_lot SET car_info = 1, state = 1, car_num = '1122' where space_num = 'D001';
UPDATE parking_lot SET car_info = 1, state = 1, car_num = '1133' where space_num = 'B009';