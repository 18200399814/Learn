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
COMMIT;
