PRAGMA foreign_keys=OFF;
BEGIN TRANSACTION;
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
COMMIT;
