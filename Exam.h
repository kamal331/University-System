#ifndef __EXAM_H_
#define __EXAM_H_
#define MAX_PROBLEM_NUM 10

/****************************************************************
 * \class Exam                                                  *
 * \brief Exam class which will be used for storing exam data.  *
 * \param subject, problems, problemNums                        *
 ***************************************************************/

class Exam
{
private:
    string mSubject;
    // Problem *mPProblems;
    vector<Problem> mProblems;
    int mProblemNums;

public:
    Exam(string subject, vector<Problem> &problems, int problemNums);
    Exam(); // default constructor
    string getSubject();
    string getExamName();
    // Problem *getProblems();
    vector<Problem> &getProblems();
    int getProblemNums();

    void setSubject(string subject);
    void setProblems(Problem &problem);
    void setproblemNums(int problemNums);
    void printExam();

    // Exam operator=(Exam *exam);
    // ~Exam();
};

Exam::Exam(string subject, vector<Problem> &problems, int problemNums)
{
    this->mProblems = problems;
    this->mSubject = subject;
    this->mProblemNums = problemNums;
}

Exam::Exam()
{
    this->mSubject = "";
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

vector<Problem> &Exam::getProblems()
{
    return mProblems;
}

int Exam::getProblemNums()
{
    return this->mProblemNums;
}

void Exam::setSubject(string subject)
{
    this->mSubject = subject;
}

void Exam::setProblems(Problem &problem)
{
    mProblems.push_back(problem);
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
        mProblems.at(i).printProblem();
    }
}

// Exam::~Exam()
// {
//     delete[] problems;
// }

#endif