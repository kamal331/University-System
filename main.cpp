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

#define LOADING_SCREEN()                                  \
    int index = 0;                                        \
    char loadingArr[26];                                  \
    while (index < 25)                                    \
    {                                                     \
        CLEAR_SCREEN();                                   \
        loadingArr[index++] = '#';                        \
        loadingArr[index] = '\0';                         \
        cout << "Loading [" << loadingArr << "]" << endl; \
        usleep(70000);                                    \
    }                                                     \
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

void addStudent();
void addProfessor();
void addCourse();
Term addTerm();
void setCourseToProfessor();

void addNewExam(Professor &professor);

int _getNewStudentId();
int _getNewProfessorId();
int _getNewCourseCode();
int _getNewTermCode();

Problem getAProblem();
Problem _getMultipleChoice();
Problem _getTrueFalse();
Problem _getFillInTheBlank();
Problem _getLongAnswer();

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

    LOADING_SCREEN();

    uint8_t *salt = randomString(32);

    Admin admin("Natasha", getArgon2Hash("1234", salt), salt, 0);
    gAdmins.push_back(admin);
    gAdminId++;

    mainMenu();

    return 0;
}

// ================= Main Menu =================
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
            professorMenu();
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

// ================= Professor Menu =================
void professorMenu()
{
    int id;
    string password;

    while (true)
    {
        CLEAR_SCREEN();
        cout << "Enter your ID: ";
        cin >> id;
        password = getpass("Enter your password: ");
        if (professorLogin(id, password))
            break;
        cout << "Try again? (y/n)" << endl;
        string choice;
        cin >> choice;
        if (choice == "n")
            return;
    }

    cout << "=========== 🧑‍🏫  Welcome to the Professor Menu 🧑‍🏫  ===========" << endl;
    string choices[4] = {"1. View your courses and exams 📚 📝",
                         "2. Add a new exam \U0000002b",
                         "3. Back to last page 🔙",
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
            gProfessors.at(id).print();
            BACK_TO_LAST_PAGE();
        }
        else if (choice == "2")
        {
            addNewExam(gProfessors.at(id));
            BACK_TO_LAST_PAGE();
        }
        else if (choice == "3")
            break;
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

bool professorLogin(int &id, string &password)
{
    CLEAR_SCREEN();

    for (int i = 0; i < gProfessorId; i++)
    {
        if (gProfessors.at(i).getId() == id)
        {
            if (verifyArgon2Hash(password, gProfessors.at(i).getPassword(), gProfessors.at(i).getSalt()))
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

void addNewExam(Professor &professor)
{
    CLEAR_SCREEN();
    cout << "=========== 📝  Add a new exam 📝  ===========" << endl;
    cout << "Enter the course code: ";
    int courseCode;
    cin >> courseCode;

    bool isDone = false;

    for (int i = 0; i < professor.getCourseNums(); i++)
    {
        cout << "=========" << endl;
        if (professor.getCourses().at(i).getCourseCode() == courseCode)
        {
            cout << "Course found ✅" << endl;

            cout << "Enter the exam name: ";
            string examName;
            cin >> examName;

            cout << "How many problems do you want to add? ";
            int problemNums;
            cin >> problemNums;

            // Problem *problems = new Problem[problemNums];
            vector<Problem> problems;
            for (int j = 0; j < problemNums; j++)
            {
                cout << "======== Problem " << j + 1 << " ========" << endl;
                problems.push_back(getAProblem());
            }

            // Exam *exams = new Exam[professor.getCourses()[i].getExamNums() + 1];
            // for (int j = 0; j < professor.getCourses()[i].getExamNums(); j++)
            // {
            //     exams[j] = professor.getCourses()[i].getExams()[j];
            // }
            // exams[professor.getCourses()[i].getExamNums()] = Exam(examName, _getNewExamCode());
            // professor.getCourses()[i].setExams(exams);

            Exam exam(examName, problems, problemNums);
            professor.getCourses().at(i).setExams(exam);
            isDone = true;
            cout << "Exam added successfully ✅" << endl;
            return;
        }
    }
    if (!isDone)
        cout << "Course not found ❌" << endl;
}

Problem getAProblem()
{
    string choice;

    while (true)
    {
        CLEAR_SCREEN();
        cout << "Choose a problem type:" << endl;
        cout << "1. Multiple Choice 1️⃣ 2️⃣ 3️⃣ 4️⃣" << endl;
        cout << "2. True or False ✅ ❌" << endl;
        cout << "3. Fill in the blank ✏" << endl;
        cout << "4. Long Answer 📄" << endl;
        cin >> choice;
        if (choice == "1")
            return _getMultipleChoice();

        else if (choice == "2")
            return _getTrueFalse();

        else if (choice == "3")
            return _getFillInTheBlank();

        else if (choice == "4")
            return _getLongAnswer();

        else
        {
            cout << "Invalid choice" << endl;
        }
    }
}
Problem _getMultipleChoice()
{
    string question;
    string problemType;
    string choices[4];
    string correctChoice;

    EMPTY_BUFFER();
    cout << "Enter the question: ";
    getline(cin, question);

    cout << "Enter the problem type: ";
    getline(cin, problemType);

    cout << "Enter the choices: " << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << i + 1 << ". ";
        getline(cin, choices[i]);
    }

    cout << "Enter the correct choice: ";
    cin >> correctChoice;
    return Problem(problemType, question, correctChoice, choices, true);
}

Problem _getTrueFalse()
{
    string question;
    string problemType;
    string correctChoice;

    EMPTY_BUFFER();
    cout << "Enter the question: ";
    getline(cin, question);

    cout << "Enter the problem type: ";
    getline(cin, problemType);

    cout << "Enter the correct choice: ";
    cin >> correctChoice;
    return Problem(problemType, question, correctChoice, nullptr, false);
}

Problem _getFillInTheBlank()
{
    string question;
    string problemType;
    string correctChoice;

    EMPTY_BUFFER();
    cout << "Enter the question: ";
    getline(cin, question);

    cout << "Enter the problem type: ";
    getline(cin, problemType);

    cout << "Enter the correct choice: ";
    cin >> correctChoice;
    return Problem(problemType, question, correctChoice, nullptr, false);
}

Problem _getLongAnswer()
{
    string question;
    string problemType;
    string correctChoice;

    EMPTY_BUFFER();
    cout << "Enter the question: ";
    getline(cin, question);

    cout << "Enter the problem type: ";
    getline(cin, problemType);

    cout << "Enter the correct choice: ";
    getline(cin, correctChoice);

    return Problem(problemType, question, correctChoice, nullptr, false);
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
