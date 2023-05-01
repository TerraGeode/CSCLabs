-- Felecia Gonzalez

-- 1
SELECT firstName
FROM student
GROUP BY firstName
ORDER BY COUNT(studentid) DESC, firstName;

-- 2
SELECT major, COUNT(student.studentid)
FROM student JOIN enroll ON student.studentid = enroll.studentID JOIN class ON enroll.classCode = class.classCode JOIN course ON class.courseCode = course.courseCode
WHERE course.courseCredit = 4 AND transfer = 'N'
GROUP BY major
ORDER BY COUNT(student.studentid) DESC;

-- 3
SELECT firstName
FROM student JOIN enroll ON student.studentid = enroll.studentID
WHERE enroll.enrollGrade = 'B' AND enroll.enrollYear = 2018 AND enroll.enrollSemester = 1
GROUP BY student.studentid
HAVING COUNT(student.studentid) = 1
ORDER BY firstName;

-- 4
SELECT CONCAT('GPA=', ROUND(AVG(GPA),2)) AS "Average"
FROM student JOIN enroll ON enroll.studentID = student.studentid JOIN class ON enroll.classCode = class.classCode
WHERE class.classTime LIKE 'Th %';

-- 5
SELECT courseDescription, COUNT(enroll.studentID)
FROM course JOIN class ON course.courseCode = class.courseCode JOIN enroll ON enroll.classCode = class.classCode
WHERE enroll.enrollSemester = '2'
GROUP BY course.courseCode
ORDER BY COUNT(enroll.studentid) DESC;
