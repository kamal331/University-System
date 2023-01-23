#ifndef __PROBLEM_H_
#define __PROBLEM_H_

class Problem
{
private:
    string mSubject;
    string mProblemType; // it cann be "multiple choice" or "fill in the blank" or "true or false" or "short answer"
    string mProblemText;
    string mProblemAnswer;

public:
    Problem(string subject, string problemType,
            string problemText, string problemAnswer);
    Problem(); // default constructor
    string getSubject();
    string getProblemType();
    string getProblemText();
    string getProblemAnswer();
    void setSubject(string subject);
    void setProblemType(string problemType);
    void setProblemText(string problemText);
    void setProblemAnswer(string problemAnswer);

    void printProblem();
    void printProblemAnswer();

    bool isTrueFalseCorrect(string answer);
    bool isMultipleChoiceCorrect(string answer);
    bool isFillInTheBlankCorrect(string answer); //==== professor need to check it
    bool isShortAnswerCorrect(string answer);    //==== professor need to check it

    // bool isCorrect(string answer);  //==== professor need to check it
};

Problem::Problem(string subject, string problemType,
                 string problemText, string problemAnswer)
{
    this->mSubject = subject;
    this->mProblemType = problemType;
    this->mProblemText = problemText;
    this->mProblemAnswer = problemAnswer;
}

Problem::Problem()
{
    this->mSubject = "";
    this->mProblemType = "";
    this->mProblemText = "";
    this->mProblemAnswer = "";
}

string Problem::getSubject()
{
    return this->mSubject;
}

string Problem::getProblemType()
{
    return this->mProblemType;
}

string Problem::getProblemText()
{
    return this->mProblemText;
}

string Problem::getProblemAnswer()
{
    return this->mProblemAnswer;
}

void Problem::setSubject(string subject)
{
    this->mSubject = subject;
}

void Problem::setProblemType(string problemType)
{
    this->mProblemType = problemType;
}

void Problem::setProblemText(string problemText)
{
    this->mProblemText = problemText;
}

void Problem::setProblemAnswer(string problemAnswer)
{
    this->mProblemAnswer = problemAnswer;
}

void Problem::printProblem()
{
    cout << "▶ Subject: " << this->mSubject << endl;
    cout << "▶ Problem Type: " << this->mProblemType << endl;
    cout << "▶ Problem Text:\n"
         << this->mProblemText << endl;
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