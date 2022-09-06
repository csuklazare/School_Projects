CREATE table fisher25_students (name varchar(255), id int AUTO_INCREMENT, gpa double, PRIMARY KEY (id));
ALTER TABLE fisher25_students AUTO_INCREMENT=800000001;
SHOW CREATE TABLE fisher25_students;
INSERT INTO fisher25_students (name, gpa) VALUES ('Aaa', RAND()*(2)+2;
INSERT INTO fisher25_students (name, gpa) VALUES ('Bbb', RAND()*(2)+2;
INSERT INTO fisher25_students (name, gpa) VALUES ('Ccc', RAND()*(2)+2;
INSERT INTO fisher25_students (name, gpa) VALUES ('Ddd', RAND()*(2)+2;
INSERT INTO fisher25_students (name, gpa) VALUES ('Eee', RAND()*(2)+2;
INSERT INTO fisher25_students (name, gpa) VALUES ('Fff', RAND()*(2)+2;
INSERT INTO fisher25_students (name, gpa) VALUES ('Ggg', RAND()*(2)+2;
INSERT INTO fisher25_students (name, gpa) VALUES ('Hhh', RAND()*(2)+2;
INSERT INTO fisher25_students (name, gpa) VALUES ('Iii', RAND()*(2)+2;
INSERT INTO fisher25_students (name, gpa) VALUES ('Jjj', RAND()*(2)+2;
INSERT INTO fisher25_students (name, gpa) VALUES ('Kkk', RAND()*(2)+2;
INSERT INTO fisher25_students (name, gpa) VALUES ('Lll', RAND()*(2)+2;
INSERT INTO fisher25_students (name, gpa) VALUES ('Mmm', RAND()*(2)+2;
INSERT INTO fisher25_students (name, gpa) VALUES ('Nnn', RAND()*(2)+2;
INSERT INTO fisher25_students (name, gpa) VALUES ('Ooo', RAND()*(2)+2;
INSERT INTO fisher25_students (name, gpa) VALUES ('Ppp', RAND()*(2)+2;
INSERT INTO fisher25_students (name, gpa) VALUES ('Qqq', RAND()*(2)+2;
INSERT INTO fisher25_students (name, gpa) VALUES ('Rrr', RAND()*(2)+2;
INSERT INTO fisher25_students (name, gpa) VALUES ('Sss', RAND()*(2)+2;
INSERT INTO fisher25_students (name, gpa) VALUES ('Ttt', RAND()*(2)+2;
INSERT INTO fisher25_students (name, gpa) VALUES ('Uuu', RAND()*(2)+2;
INSERT INTO fisher25_students (name, gpa) VALUES ('Vvv', RAND()*(2)+2;
INSERT INTO fisher25_students (name, gpa) VALUES ('Www', RAND()*(2)+2;
INSERT INTO fisher25_students (name, gpa) VALUES ('Xxx', RAND()*(2)+2;
INSERT INTO fisher25_students (name, gpa) VALUES ('Yyy', RAND()*(2)+2;
INSERT INTO fisher25_students (name, gpa) VALUES ('Zzz', RAND()*(2)+2;
SELECT * FROM fisher25_students;
CREATE TABLE fisher25_classes (deparment_code varchar(255), course_number int, credits int);
INSERT INTO fisher25_classes (department_code, course_number, credits) VALUES ('CS', 163, 3);
INSERT INTO fisher25_classes (department_code, course_number, credits) VALUES ('CS', 165, 3);
INSERT INTO fisher25_classes (department_code, course_number, credits) VALUES ('CS', 220, 4);
INSERT INTO fisher25_classes (department_code, course_number, credits) VALUES ('CS', 270, 4);
INSERT INTO fisher25_classes (department_code, course_number, credits) VALUES ('CS', 253, 4);
INSERT INTO fisher25_classes (department_code, course_number, credits) VALUES ('DSCI', 369, 3);
INSERT INTO fisher25_classes (department_code, course_number, credits) VALUES ('CS', 320, 3);
INSERT INTO fisher25_classes (department_code, course_number, credits) VALUES ('CS', 370, 3);
INSERT INTO fisher25_classes (department_code, course_number, credits) VALUES ('CS', 356, 3);
INSERT INTO fisher25_classes (department_code, course_number, credits) VALUES ('CS', 314, 3);
INSERT INTO fisher25_classes (department_code, course_number, credits) VALUES ('CS', 312, 3);
INSERT INTO fisher25_classes (department_code, course_number, credits) VALUES ('STAT', 301, 3);
SHOW CREATE TABLE fisher25_classes;
SELECT * FROM fisher25_classes;
/*The class is already named CS312, but to change it use the following command: */
UPDATE fisher25_classes SET department_code='CS', course_number=312 WHERE department_code="CT";
SELECT * FROM fisher25_classes;
CREATE TABLE fisher25_enrollments (id int, course_number int, FOREIGN KEY(id) REFERENCES fisher25_students(id), FOREIGN KEY(course_number) REFERENCES fisher25_classes(course_number));
ALTER TABLE fisher25_enrollments ADD semester CHAR(4);
INSERT INTO fisher25_enrollments (id, course_number, semester) VALUES (800000001, 163, 'FA22'), (800000001, 165, 'FA22'), (800000001, 220, 'FA22'), (800000001, 312, 'FA22');
INSERT INTO fisher25_enrollments (id, course_number, semester) VALUES (800000002, 370, 'FA22'), (800000002, 314, 'FA22'), (800000002, 320, 'FA22'), (800000002, 312, 'FA22');
INSERT INTO fisher25_enrollments (id, course_number, semester) VALUES (800000003, 270, 'FA22'), (800000003, 356, 'FA22'), (800000003, 165, 'FA22'), (800000003, 312, 'FA22');
INSERT INTO fisher25_enrollments (id, course_number, semester) VALUES (800000004, 320, 'FA22'), (800000004, 165, 'FA22'), (800000004, 220, 'FA22'), (800000004, 312, 'FA22');
INSERT INTO fisher25_enrollments (id, course_number, semester) VALUES (800000005, 320, 'FA22'), (800000005, 165, 'FA22'), (800000005, 220, 'FA22'), (800000005, 312, 'FA22');
INSERT INTO fisher25_enrollments (id, course_number, semester) VALUES (800000006, 320, 'FA22'), (800000006, 165, 'FA22'), (800000006, 220, 'FA22'), (800000006, 312, 'FA22');
INSERT INTO fisher25_enrollments (id, course_number, semester) VALUES (800000007, 320, 'FA22'), (800000007, 165, 'FA22'), (800000007, 220, 'FA22'), (800000007, 312, 'FA22');
INSERT INTO fisher25_enrollments (id, course_number, semester) VALUES (800000008, 320, 'FA22'), (800000008, 165, 'FA22'), (800000008, 220, 'FA22'), (800000008, 312, 'FA22');
INSERT INTO fisher25_enrollments (id, course_number, semester) VALUES (800000009, 320, 'FA22'), (800000009, 165, 'FA22'), (800000009, 220, 'FA22'), (800000009, 312, 'FA22');
INSERT INTO fisher25_enrollments (id, course_number, semester) VALUES (800000010, 320, 'FA22'), (800000010, 165, 'FA22'), (800000010, 220, 'FA22'), (800000010, 312, 'FA22');
INSERT INTO fisher25_enrollments (id, course_number, semester) VALUES (800000011, 320, 'FA22'), (800000011, 165, 'FA22'), (800000011, 220, 'FA22'), (800000011, 312, 'FA22');
INSERT INTO fisher25_enrollments (id, course_number, semester) VALUES (800000012, 320, 'FA22'), (800000012, 165, 'FA22'), (800000012, 220, 'FA22'), (800000012, 312, 'FA22');
INSERT INTO fisher25_enrollments (id, course_number, semester) VALUES (800000013, 320, 'FA22'), (800000013, 165, 'FA22'), (800000013, 220, 'FA22'), (800000013, 312, 'FA22');
INSERT INTO fisher25_enrollments (id, course_number, semester) VALUES (800000014, 320, 'FA22'), (800000014, 165, 'FA22'), (800000014, 220, 'FA22'), (800000014, 312, 'FA22');
INSERT INTO fisher25_enrollments (id, course_number, semester) VALUES (800000015, 320, 'FA22'), (800000015, 165, 'FA22'), (800000015, 220, 'FA22'), (800000015, 312, 'FA22');
INSERT INTO fisher25_enrollments (id, course_number, semester) VALUES (800000016, 320, 'FA22'), (800000016, 165, 'FA22'), (800000016, 220, 'FA22'), (800000016, 312, 'FA22');
INSERT INTO fisher25_enrollments (id, course_number, semester) VALUES (800000017, 320, 'FA22'), (800000017, 165, 'FA22'), (800000017, 220, 'FA22'), (800000017, 312, 'FA22');
INSERT INTO fisher25_enrollments (id, course_number, semester) VALUES (800000018, 320, 'FA22'), (800000018, 165, 'FA22'), (800000018, 220, 'FA22'), (800000018, 312, 'FA22');
INSERT INTO fisher25_enrollments (id, course_number, semester) VALUES (800000019, 320, 'FA22'), (800000019, 165, 'FA22'), (800000019, 220, 'FA22'), (800000019, 312, 'FA22');
INSERT INTO fisher25_enrollments (id, course_number, semester) VALUES (800000020, 320, 'FA22'), (800000020, 165, 'FA22'), (800000020, 220, 'FA22'), (800000020, 312, 'FA22');
INSERT INTO fisher25_enrollments (id, course_number, semester) VALUES (800000021, 320, 'FA22'), (800000021, 165, 'FA22'), (800000021, 220, 'FA22'), (800000021, 312, 'FA22');
INSERT INTO fisher25_enrollments (id, course_number, semester) VALUES (800000022, 320, 'FA22'), (800000022, 165, 'FA22'), (800000022, 220, 'FA22'), (800000022, 312, 'FA22');
INSERT INTO fisher25_enrollments (id, course_number, semester) VALUES (800000023, 320, 'FA22'), (800000023, 165, 'FA22'), (800000023, 220, 'FA22'), (800000023, 312, 'FA22');
INSERT INTO fisher25_enrollments (id, course_number, semester) VALUES (800000024, 320, 'FA22'), (800000024, 165, 'FA22'), (800000024, 220, 'FA22'), (800000024, 312, 'FA22');
INSERT INTO fisher25_enrollments (id, course_number, semester) VALUES (800000025, 320, 'FA22'), (800000025, 165, 'FA22'), (800000025, 220, 'FA22'), (800000025, 312, 'FA22');
INSERT INTO fisher25_enrollments (id, course_number, semester) VALUES (800000026, 320, 'FA22'), (800000026, 165, 'FA22'), (800000026, 220, 'FA22'), (800000026, 312, 'FA22');
COUNT rows IN fisher25_enrollments;
SELECT fisher25_students.name FROM fisher25_students INNER JOIN fisher25_enrollments ON fisher25_enrollments.id = fisher25_students.id WHERE course_number = '312';
SELECT DISTINCT fisher25_classes.course_number, fisher25_classes.department_code, fisher25_classes.credits FROM fisher25_enrollments INNER JOIN fisher25_classes ON fisher25_enrollments.course_number = fisher25_classes.course_number;

SELECT SUM(credits) FROM fisher25_classes INNER JOIN fisher25_enrollments ON fisher25_enrollments.course_number = fisher25_classes.course_number;




















































































