
/**********************************************************************
 * @file main.cpp                                                     *
 * @author Mohammad Kamal                                             *
 * @brief This is a simulation of a university system.                *
 *        It has Admin, Professor, and Student classes.               *
 *        Admin can add new course, professors and students.          *
 *        Professor can add new exams and view his courses and exams. *
 *        Student can sign up for a course and attend an exam.        *
 * @version 0.9                                                       *
 * @date 2023-01-25                                                   *
 * @copyright Copyright (c) 2023                                      *
 **********************************************************************/

#include <iostream>
#include <string>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <random>
#include <unistd.h>
#include <vector>

using namespace std;

// Ansi bold color codes
#define BLACK "\033[1;30m"
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define CYAN "\033[1;36m"
#define WHITE "\033[1;37m"
#define RESET "\033[0m"

#define LOADING_BAR()                                         \
    for (int i = 0; i <= 100; ++i)                            \
    {                                                         \
        CLEAR_SCREEN();                                       \
        cout << GREEN "\n\n\n\n\n\n\n\n\n\t\t\t\tLoading: ["; \
        for (int j = 0; j < i / 10; ++j)                      \
            cout << "██";                                     \
        for (int j = 0; j < 10 - i / 10; ++j)                 \
            cout << "  ";                                     \
        cout << "] " << i << "%" RESET << endl;               \
        usleep(30000);                                        \
    }                                                         \
    CLEAR_SCREEN();

class Date;
class Problem;
class Exam;
class Professor;
class Course;
class Term;
class Argon2Hash;
class Person;
class Student;

// ================= Functions =================
void mainMenu();
bool adminLogin();
void adminMenu();

bool professorLogin(int &id, string &password);
void professorMenu();

void dailyMessage();
void licensePage();
void privacyPolicy();
void aboutUs();

void addStudent();
void addProfessor();
void addCourse();
Term addTerm();
void setCourseToProfessor();

void addNewExam(Professor &professor);

bool studentLogin(int &id, string &password);
void studentMenu();
void signUpForACourse(Student &s1);
void attendExam(Student &s1);

int _getNewStudentId();
int _getNewProfessorId();
int _getNewCourseCode();
int _getNewTermCode();

Problem &getAProblem();
Problem &_getMultipleChoice();
Problem &_getTrueFalse();
Problem &_getFillInTheBlank();
Problem &_getLongAnswer();

void printAllCourses();

bool _isPassStrong(string password);
string _getPaasword();

// ================= Custom Headers =================
#include "Date.h"
#include "Problem.h"
#include "Exam.h"
#include "Course.h"
#include "Term.h"
#include "Argon2Hash.h"
#include "Person.h"
#include "Student.h"
#include "Professor.h"
#include "Admin.h"
#include "OtherComponents.h"
#include "ProfessorLogin.h"

// ================= Global Variables =================
int gStudentId = 0;
int gProfessorId = 0;
int gAdminId = 0;
int gCourseCode = 0;
int gTermCode = 0;

vector<Student> gStudents;
vector<Admin> gAdmins;
vector<Professor> gProfessors;
vector<Course> gCourses;
vector<Term> gTerms;

#include "AdminLogin.h"
#include "StudentLogin.h"

// ================= Main =================

int main()
{
    LOADING_BAR();

    uint8_t *salt = randomString(32);

    Admin admin("Natasha", getArgon2Hash("1234", salt), salt, 0);
    gAdmins.push_back(admin);
    gAdminId++;

    mainMenu();

    return 0;
}

// ================= Main Menu =================

/***********************************
 * @brief Main menu of the program *
 * - Login as a student            *
 * - Login as a professor          *
 * - Login as an admin             *
 * - Daily Message                 *
 * - License                       *
 * - Privacy Policy                *
 * - About Us                      *
 * - Exit                          *
 ***********************************/

void mainMenu()
{
    cout << MAGENTA << "=========== 🏢  Welcome to the University 🏢  ===========" << endl;
    string choices[8] = {YELLOW "1. Login as a student 🧑‍🎓" RESET,
                         GREEN "2. Login as a professor 🧑‍🏫" RESET,
                         BLUE "3. Login as an admin 🧑‍💻" RESET,
                         YELLOW "4. Daily Message 📩" RESET,
                         CYAN "5. License 📜" RESET,
                         WHITE "6. Privacy Policy 📝" RESET,
                         GREEN "7. About Us 📖" RESET,
                         RED "8. Exit 🚪" RESET};
    string choice;
    while (true)
    {
        CLEAR_SCREEN();
        cout << MAGENTA << "What would you like to do?" << RESET << endl;
        for (string choice : choices)
            cout << choice << endl;
        cin >> choice;

        if (choice == "1")
        {
            studentMenu();
        }
        else if (choice == "2")
        {
            professorMenu();
        }
        else if (choice == "3")
        {
            adminMenu();
        }
        else if (choice == "4")
        {
            dailyMessage();
        }
        else if (choice == "5")
        {
            licensePage();
        }
        else if (choice == "6")
        {
            privacyPolicy();
        }
        else if (choice == "7")
        {
            aboutUs();
        }
        else if (choice == "8")
        {
            exit(0);
        }
        else
        {
            cout << RED "Invalid choice" RESET << endl;
        }
    }
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