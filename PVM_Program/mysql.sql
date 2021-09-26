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
	unit SMALLINT(4) NOT NULL
);

-- 관리자 계정
insert into user values ('damin1', 'aaaa', 1);
insert into user values ('damin2', 'ssss', 1);

insert into user values ('admin1', 'aaaa', 1);
insert into user values ('admin2', 'ssss', 1);

- 입주민 계정
insert into user values ('101', '101', 0);
insert into user values ('resident', 'aaaa', 0);