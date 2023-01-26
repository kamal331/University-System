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
    vector<Problem> mProblems;
    int mProblemNums;
    double mScore;

public:
    Exam(string subject, vector<Problem> &problems, int problemNums);
    Exam(); // default constructor

    string getSubject();
    string getExamName();
    vector<Problem> &getProblems();
    int getProblemNums();
    double getScore();

    void setSubject(string subject);
    void setProblems(Problem &problem);
    void setproblemNums(int problemNums);
    void setScore(double score);

    void printExam();
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

double Exam::getScore()
{
    return this->mScore;
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

void Exam::setScore(double score)
{
    this->mScore = score;
}

void Exam::printExam()
{
    cout << GREEN "Subject: " RESET << this->mSubject << endl;
    cout << BLUE "Problem Numbers: " RESET << this->mProblemNums << endl;
    cout << MAGENTA "Problems: " RESET << endl;
    for (int i = 0; i < this->mProblemNums; i++)
    {
        cout << "===== ✳  Problem " << i + 1 << "✳  =====" << endl;
        mProblems.at(i).printProblem();
    }
}

#endif