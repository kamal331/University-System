#ifndef __PROBLEM_H_
#define __PROBLEM_H_

/*************************************************************************************
 * @brief A class for problem in exam. Which can be used for multiple choice,        *
 *  true/false, fill in the blank, short answer, and essay.                          *
 *                                                                                   *
 * @param problemType, problemText, problemAnswer, problemChoices, isMultipleChoice  *
 *                                                                                   *
 *************************************************************************************/
class Problem
{
private:
    string mProblemType;
    string mProblemText;
    string mProblemAnswer;
    string mProblemChoices[4]; // it is used for multiple choice

    bool isMultipleChoice;

public:
    Problem(string problemType, string problemText,
            string problemAnswer, string *problemChoices, bool isMultipleChoice);
    Problem(); // default constructor
    // string getSubject();
    string getProblemType();
    string getProblemText();
    string getProblemAnswer();
    string *getProblemChoices();

    // void setSubject(string subject);
    void setProblemType(string problemType);
    void setProblemText(string problemText);
    void setProblemAnswer(string problemAnswer);
    void setProblemChoices(string *problemChoices);

    void printProblem();
    void printProblemChoices();
    void printProblemAnswer();

    bool isTrueFalseCorrect(string answer);
    bool isMultipleChoiceCorrect(string answer);
    bool isFillInTheBlankCorrect(string answer); //==== professor need to check it
    bool isShortAnswerCorrect(string answer);    //==== professor need to check it
    // Problem *operator=(Problem *problem);

    // bool isCorrect(string answer);  //==== professor need to check it
};

Problem::Problem(string problemType, string problemText,
                 string problemAnswer, string *problemChoices, bool isMultipleChoice)
{
    // this->mSubject = subject;
    this->mProblemType = problemType;
    this->mProblemText = problemText;
    this->mProblemAnswer = problemAnswer;
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

string *Problem::getProblemChoices()
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

void Problem::setProblemChoices(string *problemChoices)
{
    for (int i = 0; i < 4; i++)
    {
        this->mProblemChoices[i] = problemChoices[i];
    }
}

void Problem::setProblemAnswer(string problemAnswer)
{
    this->mProblemAnswer = problemAnswer;
}

void Problem::printProblem()
{
    // cout << "▶ Subject: " << this->mSubject << endl;
    cout << "▶ Problem Type: " << this->mProblemType << endl;
    cout << "▶ Problem Text:\n"
         << this->mProblemText << endl;
}

void Problem::printProblemChoices()
{
    for (int i = 0; i < 4; i++)
        cout << this->mProblemChoices[i] << endl;
}

void Problem::printProblemAnswer()
{
    cout << "Problem Answer:\n"
         << this->mProblemAnswer << endl;
}

bool Problem::isTrueFalseCorrect(string answer)
{
    if (this->mProblemType == "True or False")
    {
        return this->mProblemAnswer == answer;
    }
    return false;
}

bool Problem::isMultipleChoiceCorrect(string answer)
{
    if (this->mProblemType == "Multiple Choice")
    {
        return this->mProblemAnswer == answer;
    }
    return false;
}

bool Problem::isFillInTheBlankCorrect(string answer)
{
    if (this->mProblemType == "Fill in the Blank")
    {
        return this->mProblemAnswer == answer;
    }
    return false;
}

bool Problem::isShortAnswerCorrect(string answer)
{
    if (this->mProblemType == "Short Answer")
    {
        return this->mProblemAnswer == answer;
    }
    return false;
}

#endif