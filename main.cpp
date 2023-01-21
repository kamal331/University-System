#include <iostream>
#include <string>

using namespace std;

#include "Problem.h"

class Exam
{
private:
    string subject;
    Problem *problems;
    int problemNums;

public:
    Exam(string subject, Problem *problems, int problemNums);
    Exam(); // default constructor
    string getSubject();
    string getExamName();
    Problem *getProblems();
    int getProblemNums();

    void setSubject(string subject);
    void setProblems(Problem *problems);
    void setproblemNums(int problemNums);
    void printExam();
    ~Exam();
};

Exam::Exam(string subject, Problem *problems, int problemNums)
{
    this->subject = subject;
    this->problems = problems;
    this->problemNums = problemNums;
}

Exam::Exam()
{
    this->subject = "";
    this->problems = nullptr;
    this->problemNums = 0;
}

string Exam::getSubject()
{
    return this->subject;
}

string Exam::getExamName()
{
    return this->subject;
}

Problem *Exam::getProblems()
{
    return this->problems;
}

int Exam::getProblemNums()
{
    return this->problemNums;
}

void Exam::setSubject(string subject)
{
    this->subject = subject;
}

void Exam::setProblems(Problem *problems)
{
    this->problems = problems;
}

void Exam::setproblemNums(int problemNums)
{
    this->problemNums = problemNums;
}

void Exam::printExam()
{
    cout << "Subject: " << this->subject << endl;
    cout << "Problem Numbers: " << this->problemNums << endl;
    cout << "Problems: " << endl;
    for (int i = 0; i < this->problemNums; i++)
    {
        cout << "===== ✳  Problem " << i + 1 << "✳  =====" << endl;
        problems[i].printProblem();
    }
}

Exam::~Exam()
{
    delete[] problems;
}

int main()
{

    // ================== Exam test ==================
    Problem p1("Math", "Multiple Choice", "What is 1 + 1?", "2", "1 + 1 = 2");
    Problem p2("Math", "Multiple Choice", "What is 2 + 2?", "4", "2 + 2 = 4");
    Problem p3("Math", "Multiple Choice", "What is 3 + 3?", "6", "3 + 3 = 6");
    Problem p4("Math", "Multiple Choice", "What is 4 + 4?", "8", "4 + 4 = 8");
    Problem p5("Math", "Multiple Choice", "What is 5 + 5?", "10", "5 + 5 = 10");
    Problem p6("Math", "Multiple Choice", "What is 6 + 6?", "12", "6 + 6 = 12");

    Problem *problems = new Problem[6];
    problems[0] = p1;
    problems[1] = p2;
    problems[2] = p3;
    problems[3] = p4;
    problems[4] = p5;
    problems[5] = p6;

    Exam e1("Math", problems, 6);
    e1.printExam();
    // ================== Exam test ==================
}