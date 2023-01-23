#include <iostream>
// #include <string>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <random>
#include <unistd.h>

using namespace std;

class Date;
class Problem;
class Exam;
class Course;
class Term;
class Argon2Hash;
class Person;
class Student;
class Professor;

// ================= Functions =================
void mainMenu();
bool adminLogin();
void adminMenu();
void addStudent();
void addProfessor();
Course *addCourse();
Term *addTerm();

int _getNewStudentId();
int _getNewProfessorId();
int _getNewCourseCode();
int _getNewTermCode();

bool _isPassStrong(string password);
string _getPaasword();

#include "Date.h"
#include "Problem.h"
#include "Exam.h"
#include "Course.h"
#include "Term.h"
#include "Argon2Hash.h"
#include "Person.h"
#include "Student.h"
#include "Professor.h"
#include "University.h"
#include "Admin.h"
#include "OtherComponents.h"

// ================= Global Variables =================
int gStudentId = 0;
int gProfessorId = 0;
int gAdminId = 0;
int gCourseCode = 0;
int gTermCode = 0;

Student *gPStudents = new Student[MAX_STUDENT_NUM];
Admin *gPAdmins = new Admin[MAX_ADMIN_NUM];
Professor *gPProfessors = new Professor[MAX_PROFESSOR_NUM];
Course *gPCourses = new Course[MAX_COURSE_NUM];
Term *gPTerms = new Term[MAX_TERM_NUM];

#include "AdminLogin.h"

// ================= Main =================

int main()
{
    // // ================== Exam test ==================
    // Problem p1("Math", "Multiple Choice", "What is 1 + 1?", "2", "1 + 1 = 2");
    // Problem p2("Math", "Multiple Choice", "What is 2 + 2?", "4", "2 + 2 = 4");
    // Problem p3("Math", "Multiple Choice", "What is 3 + 3?", "6", "3 + 3 = 6");
    // Problem p4("Math", "Multiple Choice", "What is 4 + 4?", "8", "4 + 4 = 8");
    // Problem p5("Math", "Multiple Choice", "What is 5 + 5?", "10", "5 + 5 = 10");
    // Problem p6("Math", "Multiple Choice", "What is 6 + 6?", "12", "6 + 6 = 12");

    // Problem *problems = new Problem[3];
    // Problem *problems2 = new Problem[3];

    // problems[0] = p1;
    // problems[1] = p2;
    // problems[2] = p3;

    // problems2[0] = p4;
    // problems2[1] = p5;
    // problems2[2] = p6;

    // Exam e1("Math", problems, 3);
    // Exam e2("Math", problems2, 3);

    // // ===================== Professor test =====================
    // uint8_t *salt1 = randomString(32);
    // // Professor prof1("Maryam Mirzakhani", getArgon2Hash("qF@sHYu$iO-sVx!w&wE", salt1), salt1, 1, nullptr, 0);
    // Professor *prof1 = new Professor("Maryam Mirzakhani", getArgon2Hash("qF@sHYu$iO-sVx!w&wE", salt1), salt1, 1, nullptr, 0);
    // prof1->print();

    // // cout << "Verify password: " << endl;
    // // cout << verifyArgon2Hash("qF@sHYu$iO-sVx!w&wE", prof1->getPassword(), prof1->getSalt()) << endl;

    // // cout << "Check saved password: " << endl;
    // // cout << prof1->getPassword() << endl;

    // // ================== Course test ==================
    // Exam *exams = new Exam[2];
    // exams[0] = e1;
    // exams[1] = e2;
    // Course *c1 = new Course("Math", 101, "Math Syllabus", Date(1, 1, 2020),
    //                         Date(1, 1, 2021), Date(1, 1, 2020), Date(1, 1, 2021), exams, 2, prof1);
    // Course *c2 = new Course("Physics", 101, "Physics Syllabus", Date(1, 1, 2020),
    //                         Date(1, 1, 2021), Date(1, 1, 2020), Date(1, 1, 2021), exams, 2, prof1);
    // prof1->setCourses(c1);
    // // ================== Term test ==================
    // Course *courses = new Course[2];
    // courses[0] = c1;
    // courses[1] = c2;

    // Term t1("Fall", 2020, Date(1, 1, 2020), Date(1, 1, 2021), Date(1, 1, 2021), courses, 2);
    // t1.printTerm();

    // // // ================== Student test ==================
    // uint8_t *salt2 = randomString(32);
    // // Student s1("John", getArgon2Hash("qF@sHYu$iO-sVx!w&wE", salt2), salt2, 1, nullptr, 0);
    // Student *s1 = new Student("John", getArgon2Hash("qF@sHYu$iO-sVx!w&wE", salt2), salt2, 1, nullptr, 0);
    // s1->print();

    // Student *s2 = new Student("Mary", getArgon2Hash("qF@sHYu$iO-sVx!w&wE", salt2), salt2, 1, nullptr, 0);

    // // cout << "Verify password: " << endl;
    // // cout << verifyArgon2Hash("qF@sHYu$iO-sVx!w&wE", s1->getPassword(), s1->getSalt()) << endl;

    // // cout << "Check saved password: " << endl;
    // // cout << s1->getPassword() << endl;

    // // ================== University test ==================
    // Term *terms = new Term[1];
    // terms[0] = t1;

    // Course *courses2 = new Course[2];
    // courses2[0] = c1;
    // courses2[1] = c2;

    // Student *students = new Student[2];
    // students[0] = *s1;
    // students[1] = *s2;

    // Professor *professors = new Professor[1];
    // professors[0] = *prof1;

    // University u1("Sharif University", terms, 1, courses2, 2, students, 1, professors, 1);
    // u1.setCourseNums(2);
    // u1.setProfessorNums(1);
    // u1.setStudentNums(1);
    // u1.setTermNums(1);
    // u1.print();

    // ================== Admin test ==================

    uint8_t *salt = randomString(32);

    Admin *admin = new Admin("Natasha", getArgon2Hash("1234", salt), salt, 0);
    gPAdmins[gAdminId++] = admin;

    mainMenu();

    return 0;
}

int _getNewStudentId()
{
    return gStudentId++;
}

int _getNewProfessorId()
{
    return gProfessorId++;
}

int _getNewAdminId()
{
    return gAdminId++;
}

int _getNewCourseCode()
{
    return gCourseCode++;
}

int _getNewTermCode()
{
    return gTermCode++;
}