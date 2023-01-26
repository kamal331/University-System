
/************************************************
 * @file main.cpp
 * @author Mohammad Kamal
 * @brief This is a simulation of a university system.
 * @version ---
 * @date 2023-01-25
 *
 * @copyright Copyright (c) 2023
 *
 ***********************************************/

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

// Admin *gPAdmins = new Admin[MAX_ADMIN_NUM];
// Professor *gPProfessors = new Professor[MAX_PROFESSOR_NUM];
// Course *gPCourses = new Course[MAX_COURSE_NUM];
// Term *gPTerms = new Term[MAX_TERM_NUM];

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

    LOADING_BAR();

    uint8_t *salt = randomString(32);

    Admin admin("Natasha", getArgon2Hash("1234", salt), salt, 0);
    gAdmins.push_back(admin);
    gAdminId++;

    mainMenu();

    return 0;
}

// ================= Main Menu =================

/**
 * @brief Main menu of the program
 * - Login as a student
 * - Login as a professor
 * - Login as an admin
 * - Daily Message
 * - License
 * - Privacy Policy
 * - About Us
 * - Exit
 */
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

void studentMenu()
{
    int id;
    string password;

    while (true)
    {
        CLEAR_SCREEN();
        cout << BLUE "Enter your ID: " RESET;
        cin >> id;

        cout << BLUE;
        password = getpass("Enter your password: ");
        cout << RESET;
        if (studentLogin(id, password))
            break;
        cout << RED "Try again? (y/n)" RESET << endl;
        string choice;
        cin >> choice;
        if (choice == "n")
            return;
    }

    cout << MAGENTA "=========== 🧑‍🎓  Welcome to the Student Menu 🧑‍🎓  ===========" RESET << endl;
    string choices[4] = {GREEN "1. View Courses and exams 📚" RESET,
                         BLUE "2. signup for a course 📝" RESET,
                         YELLOW "3. Do a Exam 📄" RESET,
                         RED "4. Logout 🚪" RESET};
    string choice;
    while (true)
    {
        CLEAR_SCREEN();
        cout << MAGENTA "What would you like to do?" RESET << endl;
        for (string choice : choices)
            cout << choice << endl;
        cin >> choice;

        if (choice == "1")
        {
            gStudents.at(id).print();
            BACK_TO_LAST_PAGE();
        }
        else if (choice == "2")
        {
            signUpForACourse(gStudents.at(id));
            BACK_TO_LAST_PAGE();
        }
        else if (choice == "3")
        {
            attendExam(gStudents.at(id));
        }
        else if (choice == "4")
        {
            break;
        }
        else
        {
            cout << RED "Invalid choice" RESET << endl;
        }
    }
}

bool studentLogin(int &id, string &password)
{
    CLEAR_SCREEN();

    for (int i = 0; i < gStudentId; i++)
    {
        if (gStudents.at(i).getId() == id)
        {
            if (verifyArgon2Hash(password, gStudents.at(i).getPassword(), gStudents.at(i).getSalt()))
            {
                cout << GREEN "Login successful ✅" RESET << endl;
                return true;
            }
            else
                cout << RED "Wrong password ❌" RESET << endl;
        }
    }
    cout << RED "Login Failed!" RESET << endl;
    return false;
}

void signUpForACourse(Student &s1)
{
    CLEAR_SCREEN();
    printAllCourses();
    cout << endl
         << MAGENTA "Which course do you want to signup for?" RESET << endl;
    cout << WHITE "=========== 📝  Signup for a course 📝  ===========" RESET << endl;
    cout << BLUE "Enter the course code: " RESET;
    int courseCode;
    cin >> courseCode;
    s1.setCourses(gCourses.at(courseCode));

    cout << GREEN "Signed up the course successfully ✅" RESET << endl;
}

void attendExam(Student &s1)
{
    CLEAR_SCREEN();
    s1.print();

    cout << MAGENTA "=========== 📄  Attend an Exam 📄  ===========" RESET << endl;
    cout << BLUE "Which Course do you want to attend? (Enter the code) " RESET << endl;
    int courseCode;
    cin >> courseCode;

    cout << BLUE "Which exam do you want to attend? (Enter the code) " RESET << endl;
    int examCode;
    cin >> examCode;

    double score = 100.0 / s1.getCourses().at(courseCode).getExams().at(examCode).getProblemNums();
    double totalScore = 0;

    bool isFirstTime = true;

    for (int i = 0; i < s1.getCourses().at(courseCode).getExams().at(examCode).getProblemNums(); i++)
    {
        s1.getCourses().at(courseCode).getExams().at(examCode).getProblems().at(i).printProblem();
        cout << BLUE "Enter your answer: " RESET;
        char *answer = new char[MAX_ANSWER_SIZE];
        if (isFirstTime)
        {
            EMPTY_BUFFER();
            isFirstTime = false;
        }

        cin.getline(answer, MAX_ANSWER_SIZE);
        if (s1.getCourses().at(courseCode).getExams().at(examCode).getProblems().at(i).getProblemAnswer() == answer)
        {
            totalScore += score;
            cout << GREEN "Correct answer ✅" RESET << endl
                 << endl;
        }
        else
        {
            cout << RED "Wrong answer ❌" RESET << endl
                 << endl;
        }
    }
    if (totalScore == 100)
    {
        cout << GREEN "You got 100% ✅" RESET << endl;
        system("vlc goodJob.ogg --run-time 17 --stop-time=17 vlc://quit");
    }
    else
        cout << RED "You got " << totalScore << "% ❌" RESET << endl;

    CLEAR_SCREEN();
    BACK_TO_LAST_PAGE();

    // s1.getCourses().at(courseCode).getExams().at(examCode).printExam();
    // cout << BLUE "Enter your answer: " RESET;
    // char *answer = new char[MAX_ANSWER_SIZE];
    // EMPTY_BUFFER();
    // cin.getline(answer, MAX_ANSWER_SIZE);
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

// int _getNewExamCode()
// {
//     return gExamCode++;
// }
