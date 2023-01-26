#ifndef __PROBLEM_H_
#define __PROBLEM_H_

/************************************************************************
 * \class Problem                                                       *
 * \brief A class for problem in exam. Which can be used for            *
 *        multiple choice, true/false, fill in the blank, short answer. *
 * \param problemType, problemText, problemAnswer,                      *
 *        problemChoices, isMultipleChoice                              *
 ***********************************************************************/

class Problem
{
private:
    string mProblemType;
    string mProblemText;
    string mProblemAnswer;
    vector<string> mProblemChoices;

    bool mIsMultipleChoice;

public:
    Problem(string problemType, string problemText,
            string problemAnswer, vector<string> &problemChoices,
            bool isMultipleChoice);
    Problem(); // default constructor

    string getProblemType();
    string getProblemText();
    string getProblemAnswer();
    vector<string> &getProblemChoices();

    void setProblemType(string problemType);
    void setProblemText(string problemText);
    void setProblemAnswer(string problemAnswer);
    void setProblemChoices(vector<string> &problemChoices);

    void printProblem();
    void printProblemChoices();
    void printProblemAnswer();

    bool getIsMultipleChoice();
};

Problem::Problem(string problemType, string problemText,
                 string problemAnswer, vector<string> &problemChoices,
                 bool isMultipleChoice)
{
    this->mProblemChoices = problemChoices;
    this->mProblemType = problemType;
    this->mProblemText = problemText;
    this->mProblemAnswer = problemAnswer;
    this->mIsMultipleChoice = isMultipleChoice;
}

Problem::Problem()
{
    this->mProblemType = "";
    this->mProblemText = "";
    this->mProblemAnswer = "";
}

string Problem::getProblemType()
{
    return this->mProblemType;
}

string Problem::getProblemText()
{
    return this->mProblemText;
}

vector<string> &Problem::getProblemChoices()
{
    return this->mProblemChoices;
}

string Problem::getProblemAnswer()
{
    return this->mProblemAnswer;
}

void Problem::setProblemType(string problemType)
{
    this->mProblemType = problemType;
}

void Problem::setProblemText(string problemText)
{
    this->mProblemText = problemText;
}

void Problem::setProblemChoices(vector<string> &problemChoices)
{
    this->mProblemChoices = problemChoices;
}

void Problem::setProblemAnswer(string problemAnswer)
{
    this->mProblemAnswer = problemAnswer;
}

void Problem::printProblem()
{

    cout << GREEN "▶ Problem Type: " RESET << this->mProblemType << endl;
    cout << BLUE "▶ Problem Text:\n" RESET
         << this->mProblemText << endl;
    if (getIsMultipleChoice())
    {
        cout << MAGENTA "▶ Problem Choices:\n" RESET;
        this->printProblemChoices();
    }
}

void Problem::printProblemChoices()
{
    for (int i = 0; i < 4; i++)
        cout << this->mProblemChoices[i] << endl;
}

void Problem::printProblemAnswer()
{
    cout << YELLOW "Problem Answer:\n" RESET
         << this->mProblemAnswer << endl;
}

bool Problem::getIsMultipleChoice()
{
    return this->mIsMultipleChoice;
}

#endif