#ifndef __PROBLEM_H_
#define __PROBLEM_H_

class Problem
{
private:
    string subject;
    string problemType; // it cann be "multiple choice" or "fill in the blank" or "true or false" or "short answer"
    string problemText;
    string problemAnswer;
    string problemHint;

public:
    Problem(string subject, string problemType,
            string problemText, string problemAnswer, string problemHint);
    Problem(); // default constructor
    string getSubject();
    string getProblemType();
    string getProblemText();
    string getProblemAnswer();
    string getProblemHint();
    void setSubject(string subject);
    void setProblemType(string problemType);
    void setProblemText(string problemText);
    void setProblemAnswer(string problemAnswer);
    void setProblemHint(string problemHint);

    void printProblem();
    void printProblemHint();
    void printProblemAnswer();

    bool isTrueFalseCorrect(string answer);
    bool isMultipleChoiceCorrect(string answer);
    bool isFillInTheBlankCorrect(string answer); //==== professor need to check it
    bool isShortAnswerCorrect(string answer);    //==== professor need to check it

    // bool isCorrect(string answer);  //==== professor need to check it
};

Problem::Problem(string subject, string problemType,
                 string problemText, string problemAnswer, string problemHint)
{
    this->subject = subject;
    this->problemType = problemType;
    this->problemText = problemText;
    this->problemAnswer = problemAnswer;
    this->problemHint = problemHint;
}

Problem::Problem()
{
    this->subject = "";
    this->problemType = "";
    this->problemText = "";
    this->problemAnswer = "";
    this->problemHint = "";
}

string Problem::getSubject()
{
    return this->subject;
}

string Problem::getProblemType()
{
    return this->problemType;
}

string Problem::getProblemText()
{
    return this->problemText;
}

string Problem::getProblemAnswer()
{
    return this->problemAnswer;
}

string Problem::getProblemHint()
{
    return this->problemHint;
}

void Problem::setSubject(string subject)
{
    this->subject = subject;
}

void Problem::setProblemType(string problemType)
{
    this->problemType = problemType;
}

void Problem::setProblemText(string problemText)
{
    this->problemText = problemText;
}

void Problem::setProblemAnswer(string problemAnswer)
{
    this->problemAnswer = problemAnswer;
}

void Problem::setProblemHint(string problemHint)
{
    this->problemHint = problemHint;
}

void Problem::printProblem()
{
    cout << "▶ Subject: " << this->subject << endl;
    cout << "▶ Problem Type: " << this->problemType << endl;
    cout << "▶ Problem Text:\n"
         << this->problemText << endl;
}

void Problem::printProblemHint()
{
    cout << "Problem Hint: 💡 \n"
         << this->problemHint << endl;
}

void Problem::printProblemAnswer()
{
    cout << "Problem Answer:\n"
         << this->problemAnswer << endl;
}

bool Problem::isTrueFalseCorrect(string answer)
{
    if (this->problemType == "True or False")
    {
        return this->problemAnswer == answer;
    }
    return false;
}

bool Problem::isMultipleChoiceCorrect(string answer)
{
    if (this->problemType == "Multiple Choice")
    {
        return this->problemAnswer == answer;
    }
    return false;
}

bool Problem::isFillInTheBlankCorrect(string answer)
{
    if (this->problemType == "Fill in the Blank")
    {
        return this->problemAnswer == answer;
    }
    return false;
}

bool Problem::isShortAnswerCorrect(string answer)
{
    if (this->problemType == "Short Answer")
    {
        return this->problemAnswer == answer;
    }
    return false;
}

#endif