CREATE TABLE EMP_1 (
EMP_NUM CHAR(3) NOT NULL UNIQUE,
EMP_LNAME VARCHAR(15) NOT NULL,
EMP_FNAME VARCHAR(15) NOT NULL,
EMP_INITIAL CHAR(1),
EMP_HIREDATE DATE,
JOB_CODE CHAR(3) NOT NULL,
PRIMARY KEY(EMP_NUM),
FOREIGN KEY(JOB_CODE) REFERENCES JOB(JOB_CODE));