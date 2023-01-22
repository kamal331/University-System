#include <iostream>
// #include <string>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <random>

using namespace std;

#include "Date.h"
#include "Problem.h"
#include "Exam.h"
#include "Course.h"
#include "Term.h"
#include "Argon2Hash.h"
#include "Person.h"
#include "Student.h"

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

    // // ================== Course test ==================
    // Exam *exams = new Exam[2];
    // exams[0] = e1;
    // exams[1] = e2;
    // Course c1("Math", 101, "Math Syllabus", Date(1, 1, 2020), Date(1, 1, 2021), Date(1, 1, 2020), Date(1, 1, 2021), exams, 2);
    // Course c2("Physics", 101, "Physics Syllabus", Date(1, 1, 2020), Date(1, 1, 2021), Date(1, 1, 2020), Date(1, 1, 2021), exams, 2);

    // // ================== Term test ==================
    // Course *courses = new Course[2];
    // courses[0] = c1;
    // courses[1] = c2;

    // Term t1("Fall", 2020, Date(1, 1, 2020), Date(1, 1, 2021), Date(1, 1, 2021), courses, 2);
    // t1.printTerm();

    // // ================== Student test ==================
    // uint8_t *salt = randomString(32);
    // Student s1("John", getArgon2Hash("qF@sHYu$iO-sVx!w&wE", salt), salt, 1, nullptr, 0);
    // s1.print();

    // cout << "Verify password: " << endl;
    // cout << verifyArgon2Hash("qF@sHYu$iO-sVx!w&wE", s1.getPassword(), s1.getSalt()) << endl;

    // cout << "Check saved password: " << endl;
    // cout << s1.getPassword() << endl;
}