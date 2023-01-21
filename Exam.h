#ifndef __EXAM_H_
#define __EXAM_H_

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

#endif