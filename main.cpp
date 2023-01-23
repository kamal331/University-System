#include <iostream>
// #include <string>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <random>

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
void addCourse();
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

Student *pStudents = new Student[MAX_STUDENT_NUM];
Admin *pAdmins = new Admin[MAX_ADMIN_NUM];
Professor *pProfessors = new Professor[MAX_PROFESSOR_NUM];
Course *pCourses = new Course[MAX_COURSE_NUM];
Term *pTerms = new Term[MAX_TERM_NUM];

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

    uint8_t *salt = randomString(32);

    Admin *admin = new Admin("Natasha", getArgon2Hash("1234", salt), salt, 0);
    pAdmins[gAdminId++] = admin;

    mainMenu();

    return 0;
}

void mainMenu()
{
    cout << "=========== 🏢  Welcome to the University 🏢  ===========" << endl;
    string choices[5] = {"1. Login as a student 🧑‍🎓",
                         "2. Login as a professor 🧑‍🏫",
                         "3. Login as an admin 🧑‍💻",
                         "4. Exit 🚪"};
    string choice;
    while (true)
    {
        CLEAR_SCREEN();
        cout << "What would you like to do?" << endl;
        for (string choice : choices)
            cout << choice << endl;
        cin >> choice;

        if (choice == "1")
        {
            cout << "You chose to login as a student" << endl;
            break;
        }
        else if (choice == "2")
        {
            cout << "You chose to login as a professor" << endl;
            break;
        }
        else if (choice == "3")
        {
            adminMenu();
        }
        else if (choice == "4")
        {
            cout << "You chose to exit" << endl;
            exit(0);
        }
        else
        {
            cout << "Invalid choice" << endl;
        }
    }
}

// ================== Admin Menu ==================

void adminMenu()
{
    while (!adminLogin())
    {
        cout << "Try again? (y/n)" << endl;
        string choice;
        cin >> choice;
        if (choice == "n")
            return;
    }
    cout << "=========== 🧑‍💻  Welcome to the Admin Menu 🧑‍💻  ===========" << endl;
    string choices[6] = {"1. Add a student 🧑‍🎓",
                         "2. Add a professor 🧑‍🏫",
                         "3. Add a course 📚",
                         "4. Add a term 📅",
                         "5. Back to Last Page 🔙",
                         "6. Exit 🚪"};
    string choice;

    while (true)
    {
        CLEAR_SCREEN();
        cout << "What would you like to do?" << endl;
        for (string choice : choices) // Print Menu
            cout << choice << endl;
        cin >> choice;

        if (choice == "1")
        {
            addStudent();
            pStudents[gStudentId - 1].print();
            BACK_TO_LAST_PAGE();
        }
        else if (choice == "2")
        {
            addProfessor();
            pProfessors[gProfessorId - 1].print();
            BACK_TO_LAST_PAGE();
        }
        else if (choice == "3")
        {
            addCourse();
            pCourses[gCourseCode - 1].print();
            BACK_TO_LAST_PAGE();
        }
        else if (choice == "4")
        {
            cout << "You chose to add a term" << endl;
        }
        else if (choice == "5")
        {
            break;
        }
        else if (choice == "6")
        {
            cout << "You chose to exit" << endl;
            exit(0);
        }

        else
        {
            cout << "Invalid choice" << endl;
        }
    }
}

bool adminLogin()
{
    CLEAR_SCREEN();
    int id;
    string password;

    cout << "Enter your ID: ";
    cin >> id;
    cout << "Enter your password: ";
    cin >> password;

    for (int i = 0; i < gAdminId; i++)
    {
        if (pAdmins[i].getId() == id)
        {
            if (verifyArgon2Hash(password, pAdmins[i].getPassword(), pAdmins[i].getSalt()))
            {
                cout << "Login successful ✅" << endl;
                return true;
            }
            else
                cout << "Wrong password ❌" << endl;
        }
    }
    cout << "Login Failed!" << endl;
    return false;
}

void addStudent()
{
    CLEAR_SCREEN();
    string name;
    string password;
    uint8_t *salt = new uint8_t[32];

    salt = randomString(32);
    int id = _getNewStudentId();

    cout << "Enter student's name: ";
    cin >> name;

    _getPaasword();

    Student *s = new Student(name, getArgon2Hash(password, salt), salt, id, nullptr, 0);
    pStudents[gStudentId - 1] = s;
    cout << "Student added successfully ✅" << endl;
}

void addProfessor()
{
    CLEAR_SCREEN();
    string name;
    string password;
    uint8_t *salt = new uint8_t[32];

    salt = randomString(32);
    int id = _getNewProfessorId();

    cout << "Enter professor's name: ";
    cin >> name;

    _getPaasword();

    Professor *prof = new Professor(name, getArgon2Hash(password, salt), salt, id, nullptr, 0);
    pProfessors[gProfessorId - 1] = prof;
    cout << "Professor added successfully ✅" << endl;
}

void addCourse()
{
    CLEAR_SCREEN();
    string name;

    cout << "Enter course's name: ";
    cin >> name;

    int code = _getNewCourseCode();

    char *pSyllabus = new char[MAX_SYLLABUS_SIZE];

    cout << "Enter course's syllabus: ";
    char c = '=';
    int i = 0;
    EMPTY_BUFFER();

    c = getchar();
    while ((c != '\n') && (c != EOF) && (i < MAX_SYLLABUS_SIZE))
    {
        pSyllabus[i] = c;
        ++i;
        c = getchar();
    }
    pSyllabus[i] = '\0';

    Date *pStartDate = new Date();
    Date *pEndDate = new Date();
    Date *pMidTermDate = new Date();
    Date *pFinalExamDate = new Date();

    cout << "Enter course's start date: ";
    cin >> *pStartDate;

    cout << "Enter course's end date: ";
    cin >> *pEndDate;

    cout << "Enter course's mid term date: ";
    cin >> *pMidTermDate;

    cout << "Enter course's final exam date: ";
    cin >> *pFinalExamDate;

    Exam *pExams = new Exam[MAX_EXAM_NUM];
    int examNum = 0;

    Professor *pProfessors = new Professor;

    Course *course = new Course(name, code, pSyllabus, pStartDate, pEndDate,
                                pMidTermDate, pFinalExamDate, pExams, examNum, pProfessors);

    pCourses[gCourseCode - 1] = course;
    cout << "Course added successfully ✅" << endl;
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
