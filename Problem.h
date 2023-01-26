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
    // string mProblemChoices[4]; // it is used for multiple choice
    vector<string> mProblemChoices;

    bool mIsMultipleChoice;

public:
    Problem(string problemType, string problemText,
            string problemAnswer, vector<string> &problemChoices,
            bool isMultipleChoice);
    Problem(); // default constructor
    // string getSubject();
    string getProblemType();
    string getProblemText();
    string getProblemAnswer();
    vector<string> &getProblemChoices();

    // void setSubject(string subject);
    void setProblemType(string problemType);
    void setProblemText(string problemText);
    void setProblemAnswer(string problemAnswer);
    void setProblemChoices(vector<string> &problemChoices);

    void printProblem();
    void printProblemChoices();
    void printProblemAnswer();

    bool getIsMultipleChoice();

    // bool isTrueFalseCorrect(string answer);
    // bool isMultipleChoiceCorrect(string answer);
    // bool isFillInTheBlankCorrect(string answer); //==== professor need to check it
    // bool isShortAnswerCorrect(string answer);    //==== professor need to check it
    // Problem *operator=(Problem *problem);

    // bool isCorrect(string answer);  //==== professor need to check it
};

Problem::Problem(string problemType, string problemText,
                 string problemAnswer, vector<string> &problemChoices,
                 bool isMultipleChoice)
{
    // this->mSubject = subject;
    this->mProblemChoices = problemChoices;
    this->mProblemType = problemType;
    this->mProblemText = problemText;
    this->mProblemAnswer = problemAnswer;
    this->mIsMultipleChoice = isMultipleChoice;
}

Problem::Problem()
{
    // this->mSubject = "";
    this->mProblemType = "";
    this->mProblemText = "";
    this->mProblemAnswer = "";
}

// string Problem::getSubject()
// {
//     return this->mSubject;
// }

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

// void Problem::setSubject(string subject)
// {
//     this->mSubject = subject;
// }

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
    // cout << "▶ Subject: " << this->mSubject << endl;

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

// bool Problem::isTrueFalseCorrect(string answer)
// {
//     if (this->mProblemType == "True or False")
//     {
//         return this->mProblemAnswer == answer;
//     }
//     return false;
// }

// bool Problem::isMultipleChoiceCorrect(string answer)
// {
//     if (this->mProblemType == "Multiple Choice")
//     {
//         return this->mProblemAnswer == answer;
//     }
//     return false;
// }

// bool Problem::isFillInTheBlankCorrect(string answer)
// {
//     if (this->mProblemType == "Fill in the Blank")
//     {
//         return this->mProblemAnswer == answer;
//     }
//     return false;
// }

// bool Problem::isShortAnswerCorrect(string answer)
// {
//     if (this->mProblemType == "Short Answer")
//     {
//         return this->mProblemAnswer == answer;
//     }
//     return false;
// }

#endif