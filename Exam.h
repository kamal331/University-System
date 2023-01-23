#ifndef __EXAM_H_
#define __EXAM_H_

class Exam
{
private:
    string mSubject;
    Problem *mPProblems;
    int mProblemNums;

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

    Exam *operator=(Exam *exam);
    // ~Exam();
};

Exam::Exam(string subject, Problem *problems, int problemNums)
{
    this->mSubject = subject;
    this->mPProblems = problems;
    this->mProblemNums = problemNums;
}

Exam::Exam()
{
    this->mSubject = "";
    this->mPProblems = nullptr;
    this->mProblemNums = 0;
}

string Exam::getSubject()
{
    return this->mSubject;
}

string Exam::getExamName()
{
    return this->mSubject;
}

Problem *Exam::getProblems()
{
    return this->mPProblems;
}

int Exam::getProblemNums()
{
    return this->mProblemNums;
}

void Exam::setSubject(string subject)
{
    this->mSubject = subject;
}

void Exam::setProblems(Problem *problems)
{
    this->mPProblems = problems;
}

void Exam::setproblemNums(int problemNums)
{
    this->mProblemNums = problemNums;
}

void Exam::printExam()
{
    cout << "Subject: " << this->mSubject << endl;
    cout << "Problem Numbers: " << this->mProblemNums << endl;
    cout << "Problems: " << endl;
    for (int i = 0; i < this->mProblemNums; i++)
    {
        cout << "===== ✳  Problem " << i + 1 << "✳  =====" << endl;
        mPProblems[i].printProblem();
    }
}

Exam *Exam::operator=(Exam *exam)
{
    this->mSubject = exam->mSubject;
    this->mPProblems = exam->mPProblems;
    this->mProblemNums = exam->mProblemNums;
    return this;
}

// Exam::~Exam()
// {
//     delete[] problems;
// }

#endif