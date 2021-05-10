PRAGMA foreign_keys=OFF;
BEGIN TRANSACTION;
CREATE TABLE student_table(id int primary key,name varchar(16),class varchar(16),sex varchar(8),check(sex ='男' or sex ='女'));
INSERT INTO student_table VALUES(4,'张文华','二班','男');
INSERT INTO student_table VALUES(3,'李思雨','一班','女');
INSERT INTO student_table VALUES(1,'王小凤','一班','女');
INSERT INTO student_table VALUES(7,'李智瑞','三班','男');
INSERT INTO student_table VALUES(6,'徐文杰','二班','男');
INSERT INTO student_table VALUES(8,'徐雨秋','三班','男');
INSERT INTO student_table VALUES(5,'张青云','二班','女');
INSERT INTO student_table VALUES(9,'孙皓然','三班','男');
INSERT INTO student_table VALUES(10,'李春山','三班','男');
INSERT INTO student_table VALUES(2,'刘诗迪','一班','女');
CREATE TABLE score_table(id integer primary key autoincrement,name varchar(16),class varchar(16),score int,check(score >=0 and score <= 100));
INSERT INTO score_table VALUES(1,'王小凤','一班',88);
INSERT INTO score_table VALUES(2,'刘诗迪','一班',70);
INSERT INTO score_table VALUES(3,'李思雨','一班',92);
INSERT INTO score_table VALUES(4,'张文华','二班',55);
INSERT INTO score_table VALUES(5,'张青云','二班',77);
INSERT INTO score_table VALUES(6,'徐文杰','二班',77);
INSERT INTO score_table VALUES(7,'李智瑞','三班',56);
INSERT INTO score_table VALUES(8,'徐雨秋','三班',91);
INSERT INTO score_table VALUES(9,'孙皓然','三班',93);
INSERT INTO score_table VALUES(10,'李春山','三班',57);
CREATE TABLE month_table(id varchar(16),name varchar(16),month_num int,check(month_num >=1 and month_num <= 12));
INSERT INTO month_table VALUES('E002','王小凤',1);
INSERT INTO month_table VALUES('E001','张文华',2);
INSERT INTO month_table VALUES('E003','孙皓然',3);
INSERT INTO month_table VALUES('E001','张文华',4);
INSERT INTO month_table VALUES('E002','王小凤',5);
INSERT INTO month_table VALUES('E001','张文华',6);
INSERT INTO month_table VALUES('E004','李智瑞',7);
INSERT INTO month_table VALUES('E002','王小凤',8);
INSERT INTO month_table VALUES('E003','孙皓然',9);
CREATE TABLE sale_table(year_num int,month_num int,sales int,check(year_num >0),check(month_num >=1 and month_num <=12));
INSERT INTO sale_table VALUES(2019,1,2854);
INSERT INTO sale_table VALUES(2019,2,4772);
INSERT INTO sale_table VALUES(2019,3,3542);
INSERT INTO sale_table VALUES(2019,4,1336);
INSERT INTO sale_table VALUES(2019,5,3544);
INSERT INTO sale_table VALUES(2018,1,2293);
INSERT INTO sale_table VALUES(2018,2,2559);
INSERT INTO sale_table VALUES(2018,3,2597);
INSERT INTO sale_table VALUES(2018,4,2363);
CREATE TABLE score_info_table(id int,name varchar(16),subject varchar(16),score int,check(score >=0 and score <=100));
INSERT INTO score_info_table VALUES(1,'王小凤','语文',88);
INSERT INTO score_info_table VALUES(2,'张文华','语文',70);
INSERT INTO score_info_table VALUES(3,'徐雨秋','语文',92);
INSERT INTO score_info_table VALUES(1,'王小凤','数学',55);
INSERT INTO score_info_table VALUES(2,'张文华','数学',77);
INSERT INTO score_info_table VALUES(3,'徐雨秋','数学',77);
INSERT INTO score_info_table VALUES(1,'王小凤','英语',72);
INSERT INTO score_info_table VALUES(2,'张文华','英语',91);
INSERT INTO score_info_table VALUES(3,'徐雨秋','英语',93);
CREATE TABLE student_info_table(id integer primary key autoincrement,name varchar(16),class varchar(16),grade varchar(16));
INSERT INTO student_info_table VALUES(1,'王小凤','一班','一年级');
INSERT INTO student_info_table VALUES(2,'刘诗迪','一班','二年级');
INSERT INTO student_info_table VALUES(3,'李思雨','一班','一年级');
INSERT INTO student_info_table VALUES(4,'张文华','二班','二年级');
INSERT INTO student_info_table VALUES(5,'张青云','二班','一年级');
INSERT INTO student_info_table VALUES(6,'徐文杰','二班','二年级');
INSERT INTO student_info_table VALUES(7,'李智瑞','一班','一年级');
INSERT INTO student_info_table VALUES(8,'徐雨秋','二班','二年级');
INSERT INTO student_info_table VALUES(9,'孙皓然','一班','一年级');
CREATE TABLE column_table(column1 integer,column2 int,column3 int);
INSERT INTO column_table VALUES(5,10,7);
INSERT INTO column_table VALUES(1,10,6);
INSERT INTO column_table VALUES(9,3,5);
INSERT INTO column_table VALUES(5,2,9);
INSERT INTO column_table VALUES(10,4,3);
INSERT INTO column_table VALUES(5,2,9);
INSERT INTO column_table VALUES(5,8,6);
INSERT INTO column_table VALUES(8,8,6);
CREATE TABLE order_table(order_id integer primary key,order_date date);
INSERT INTO order_table VALUES(1,'2019-1-8');
INSERT INTO order_table VALUES(2,'2019-1-9');
INSERT INTO order_table VALUES(3,'2019-1-10');
INSERT INTO order_table VALUES(4,'2019-1-11');
INSERT INTO order_table VALUES(5,'2020-1-8');
INSERT INTO order_table VALUES(6,'2020-1-9');
INSERT INTO order_table VALUES(7,'2020-1-10');
INSERT INTO order_table VALUES(8,'2020-1-11');
INSERT INTO order_table VALUES(9,'2020-1-12');
CREATE TABLE winner_table(id integer,name varchar(16),primary key(id));
INSERT INTO winner_table VALUES(1,'王小凤');
INSERT INTO winner_table VALUES(2,'刘诗迪');
INSERT INTO winner_table VALUES(3,'李思雨');
INSERT INTO winner_table VALUES(7,'李智瑞');
INSERT INTO winner_table VALUES(8,'徐雨秋');
INSERT INTO winner_table VALUES(9,'孙皓然');
CREATE TABLE IF NOT EXISTS "winner_table;"(
  "id	name" TEXT
);
INSERT INTO "winner_table;" VALUES('1	王小凤');
INSERT INTO "winner_table;" VALUES('2	刘诗迪');
INSERT INTO "winner_table;" VALUES('3	李思雨');
INSERT INTO "winner_table;" VALUES('7	李智瑞');
INSERT INTO "winner_table;" VALUES('8	徐雨秋');
INSERT INTO "winner_table;" VALUES('9	孙皓然');
CREATE TABLE user_login(user_id int,login_time datetime);
INSERT INTO user_login VALUES(1,'2019/1/1 6:00');
INSERT INTO user_login VALUES(1,'2019/1/2 10:00');
INSERT INTO user_login VALUES(1,'2019/1/4 19:00');
INSERT INTO user_login VALUES(2,'2019/1/2 10:00');
INSERT INTO user_login VALUES(2,'2019/1/3 9:00');
INSERT INTO user_login VALUES(2,'2019/1/9 14:00');
INSERT INTO user_login VALUES(3,'2019/1/3 8:00');
INSERT INTO user_login VALUES(3,'2019/1/4 10:00');
CREATE TABLE course_table(id integer primary key autoincrement,name varchar(16),grade varchar(16),courses varchar(16));
INSERT INTO course_table VALUES(1,'王小凤','一年级','心理学');
INSERT INTO course_table VALUES(2,'刘诗迪','二年级','心理学');
INSERT INTO course_table VALUES(3,'李思雨','三年级','社会学');
INSERT INTO course_table VALUES(4,'张文华','一年级','心理学');
INSERT INTO course_table VALUES(5,'张青云','二年级','心理学');
INSERT INTO course_table VALUES(6,'徐文杰','三年级','计算机');
INSERT INTO course_table VALUES(7,'李智瑞','一年级','心理学');
INSERT INTO course_table VALUES(8,'徐雨秋','二年级','计算机');
INSERT INTO course_table VALUES(9,'孙皓然','三年级','社会学');
INSERT INTO course_table VALUES(10,'李春山','一年级','社会学');
CREATE TABLE consum_order_table(order_id integer primary key,user_id int,amount int);
INSERT INTO consum_order_table VALUES(201901,1,10);
INSERT INTO consum_order_table VALUES(201902,2,20);
INSERT INTO consum_order_table VALUES(201903,3,15);
INSERT INTO consum_order_table VALUES(201904,3,15);
INSERT INTO consum_order_table VALUES(201905,4,20);
INSERT INTO consum_order_table VALUES(201906,4,20);
INSERT INTO consum_order_table VALUES(201907,5,25);
INSERT INTO consum_order_table VALUES(201908,5,25);
INSERT INTO consum_order_table VALUES(201909,6,30);
INSERT INTO consum_order_table VALUES(201910,6,30);
INSERT INTO consum_order_table VALUES(201911,7,35);
INSERT INTO consum_order_table VALUES(201912,7,35);
DELETE FROM sqlite_sequence;
INSERT INTO sqlite_sequence VALUES('score_table',10);
INSERT INTO sqlite_sequence VALUES('student_info_table',9);
INSERT INTO sqlite_sequence VALUES('course_table',10);
COMMIT;