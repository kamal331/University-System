#ifndef __TERM_H_
#define __TERM_H_

class Term
{
private:
    string mTermName;
    int mTermCode;
    Date mTermStartDate;
    Date mTermEndDate;
    Date mGradesDeadline;
    Course *mPCourses;
    int mCourseNums;

public:
    Term(string termName, int termCode,
         Date termStartDate, Date termEndDate,
         Date gradesDeadline, Course *courses, int courseNums);
    Term(); // default constructor
    string getTermName();
    int getTermCode();
    Date getTermStartDate();
    Date getTermEndDate();
    Date getGradesDeadline();
    Course *getCourses();
    int getCourseNums();

    void setTermName(string termName);
    void setTermCode(int termCode);
    void setTermStartDate(Date termStartDate);
    void setTermEndDate(Date termEndDate);
    void setGradesDeadline(Date GradesDeadline);
    void setCourses(Course *courses);
    void setCourseNums(int courseNums);
    void printTerm();

    Term *operator=(Term *term);
    // ~Term();
};

Term::Term(string termName, int termCode, Date termStartDate,
           Date termEndDate, Date gradesDeadline, Course *courses, int courseNums)
{
    this->mTermName = termName;
    this->mTermCode = termCode;
    this->mTermStartDate = termStartDate;
    this->mTermEndDate = termEndDate;
    this->mGradesDeadline = gradesDeadline;
    this->mPCourses = courses;
    this->mCourseNums = courseNums;
}

Term::Term()
{
    this->mTermName = "";
    this->mTermCode = 0;
    this->mTermStartDate = Date();
    this->mTermEndDate = Date();
    this->mGradesDeadline = Date();
    this->mPCourses = nullptr;
    this->mCourseNums = 0;
}

string Term::getTermName()
{
    return this->mTermName;
}

int Term::getTermCode()
{
    return this->mTermCode;
}

Date Term::getTermStartDate()
{
    return this->mTermStartDate;
}

Date Term::getTermEndDate()
{
    return this->mTermEndDate;
}

Date Term::getGradesDeadline()
{
    return this->mGradesDeadline;
}

Course *Term::getCourses()
{
    return this->mPCourses;
}

int Term::getCourseNums()
{
    return this->mCourseNums;
}

void Term::setTermName(string termName)
{
    this->mTermName = termName;
}

void Term::setTermCode(int termCode)
{
    this->mTermCode = termCode;
}

void Term::setTermStartDate(Date termStartDate)
{
    this->mTermStartDate = termStartDate;
}

void Term::setTermEndDate(Date termEndDate)
{
    this->mTermEndDate = termEndDate;
}

void Term::setGradesDeadline(Date gradesDeadline)
{
    this->mGradesDeadline = gradesDeadline;
}

void Term::setCourses(Course *courses)
{
    this->mPCourses = courses;
}

void Term::setCourseNums(int courseNums)
{
    this->mCourseNums = courseNums;
}

void Term::printTerm()
{
    cout << "========== Term ===========" << endl;
    cout << "Term Name: " << this->mTermName << endl;
    cout << "Term Code: " << this->mTermCode << endl;
    cout << "Term Start Date: " << this->mTermStartDate.getDay() << "/" << this->mTermStartDate.getMonth() << "/" << this->mTermStartDate.getYear() << endl;
    cout << "Term End Date: " << this->mTermEndDate.getDay() << "/" << this->mTermEndDate.getMonth() << "/" << this->mTermEndDate.getYear() << endl;
    cout << "Grades Deadline: " << this->mGradesDeadline.getDay() << "/" << this->mGradesDeadline.getMonth() << "/" << this->mGradesDeadline.getYear() << endl;
    cout << "Course Numbers: " << this->mCourseNums << endl;
    cout << "========== Course ===========" << endl;
    for (int i = 0; i < this->mCourseNums; i++)
    {
        this->mPCourses[i].printCourse();
    }
}

Term *Term::operator=(Term *term)
{
    this->mTermName = term->mTermName;
    this->mTermCode = term->mTermCode;
    this->mTermStartDate = term->mTermStartDate;
    this->mTermEndDate = term->mTermEndDate;
    this->mGradesDeadline = term->mGradesDeadline;
    this->mPCourses = term->mPCourses;
    this->mCourseNums = term->mCourseNums;
    return this;
}

// Term::~Term()
// {
//     delete[] this->courses;
// }

#endif