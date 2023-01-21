#ifndef __TERM_H_
#define __TERM_H_

class Term
{
private:
    string termName;
    int termCode;
    Date termStartDate;
    Date termEndDate;
    Date gradesDeadline;
    Course *courses;
    int courseNums;

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
    ~Term();
};

Term::Term(string termName, int termCode, Date termStartDate, Date termEndDate, Date gradesDeadline, Course *courses, int courseNums)
{
    this->termName = termName;
    this->termCode = termCode;
    this->termStartDate = termStartDate;
    this->termEndDate = termEndDate;
    this->gradesDeadline = gradesDeadline;
    this->courses = courses;
    this->courseNums = courseNums;
}

Term::Term()
{
    this->termName = "";
    this->termCode = 0;
    this->termStartDate = Date();
    this->termEndDate = Date();
    this->gradesDeadline = Date();
    this->courses = nullptr;
    this->courseNums = 0;
}

string Term::getTermName()
{
    return this->termName;
}

int Term::getTermCode()
{
    return this->termCode;
}

Date Term::getTermStartDate()
{
    return this->termStartDate;
}

Date Term::getTermEndDate()
{
    return this->termEndDate;
}

Date Term::getGradesDeadline()
{
    return this->gradesDeadline;
}

Course *Term::getCourses()
{
    return this->courses;
}

int Term::getCourseNums()
{
    return this->courseNums;
}

void Term::setTermName(string termName)
{
    this->termName = termName;
}

void Term::setTermCode(int termCode)
{
    this->termCode = termCode;
}

void Term::setTermStartDate(Date termStartDate)
{
    this->termStartDate = termStartDate;
}

void Term::setTermEndDate(Date termEndDate)
{
    this->termEndDate = termEndDate;
}

void Term::setGradesDeadline(Date gradesDeadline)
{
    this->gradesDeadline = gradesDeadline;
}

void Term::setCourses(Course *courses)
{
    this->courses = courses;
}

void Term::setCourseNums(int courseNums)
{
    this->courseNums = courseNums;
}

void Term::printTerm()
{
    cout << "========== Term ===========" << endl;
    cout << "Term Name: " << this->termName << endl;
    cout << "Term Code: " << this->termCode << endl;
    cout << "Term Start Date: " << this->termStartDate.getDay() << "/" << this->termStartDate.getMonth() << "/" << this->termStartDate.getYear() << endl;
    cout << "Term End Date: " << this->termEndDate.getDay() << "/" << this->termEndDate.getMonth() << "/" << this->termEndDate.getYear() << endl;
    cout << "Grades Deadline: " << this->gradesDeadline.getDay() << "/" << this->gradesDeadline.getMonth() << "/" << this->gradesDeadline.getYear() << endl;
    cout << "Course Numbers: " << this->courseNums << endl;
    cout << "========== Course ===========" << endl;
    for (int i = 0; i < this->courseNums; i++)
    {
        this->courses[i].printCourse();
    }
}

Term::~Term()
{
    delete[] this->courses;
}

#endif