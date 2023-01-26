#ifndef __TERM_H_
#define __TERM_H_
#define MAX_COURSE_NUM 10

/*****************************************************************
 * \class Term                                                   *
 * \brief Term class which will be used for storing term data.   *
 *        Each term has a set of courses.                        *
 * \param termName, termCode, termStartDate, termEndDate,        *
 *       gradesDeadline, courses, courseNums                     *
 *****************************************************************/

class Term
{
private:
    string mTermName;
    int mTermCode;
    Date *mPTermStartDate;
    Date *mPTermEndDate;
    Date *mPGradesDeadline;
    // Course *mPCourses;
    vector<Course> mCourses;
    int mCourseNums;

public:
    Term(string termName, int termCode,
         Date *termStartDate, Date *termEndDate,
         Date *gradesDeadline, int courseNums);
    Term(); // default constructor
    string getTermName();
    int getTermCode();
    Date *getTermStartDate();
    Date *getTermEndDate();
    Date *getGradesDeadline();
    vector<Course> &getCourses();
    int getCourseNums();

    void setTermName(string termName);
    void setTermCode(int termCode);
    void setTermStartDate(Date *termStartDate);
    void setTermEndDate(Date *termEndDate);
    void setGradesDeadline(Date *GradesDeadline);
    void setCourse(Course &courses);
    void setCourseNums(int courseNums);
    void print();

    // Term operator=(Term *term);
    // ~Term();
};

Term::Term(string termName, int termCode, Date *termStartDate,
           Date *termEndDate, Date *gradesDeadline, int courseNums)
{
    this->mTermName = termName;
    this->mTermCode = termCode;
    this->mPTermStartDate = termStartDate;
    this->mPTermEndDate = termEndDate;
    this->mPGradesDeadline = gradesDeadline;
    this->mCourseNums = courseNums;
}

Term::Term()
{
    this->mTermName = "";
    this->mTermCode = 0;
    this->mPTermStartDate = new Date();
    this->mPTermEndDate = new Date();
    this->mPGradesDeadline = new Date();
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

Date *Term::getTermStartDate()
{
    return this->mPTermStartDate;
}

Date *Term::getTermEndDate()
{
    return this->mPTermEndDate;
}

Date *Term::getGradesDeadline()
{
    return this->mPGradesDeadline;
}

vector<Course> &Term::getCourses()
{
    return this->mCourses;
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

void Term::setTermStartDate(Date *termStartDate)
{
    this->mPTermStartDate = termStartDate;
}

void Term::setTermEndDate(Date *termEndDate)
{
    this->mPTermEndDate = termEndDate;
}

void Term::setGradesDeadline(Date *gradesDeadline)
{
    this->mPGradesDeadline = gradesDeadline;
}

void Term::setCourse(Course &courses)
{
    this->mCourses.push_back(courses);
}

void Term::setCourseNums(int courseNums)
{
    this->mCourseNums = courseNums;
}

void Term::print()
{
    cout << MAGENTA "========== Term ===========" RESET << endl;
    cout << GREEN "Term Name: " RESET << this->mTermName << endl;
    cout << BLUE "Term Code: " RESET << this->mTermCode << endl;
    cout << YELLOW "Term Start Date: " RESET << *mPTermStartDate << endl;
    cout << CYAN "Term End Date: " RESET << *mPTermEndDate << endl;
    cout << WHITE "Grades Deadline: " RESET << *mPGradesDeadline << endl;
    cout << GREEN "Course Numbers: " RESET << this->mCourseNums << endl;
    cout << MAGENTA "========== Course ===========" RESET << endl;
    for (int i = 0; i < this->mCourseNums; i++)
    {
        this->mCourses.at(i).print();
    }
}

// Term Term::operator=(Term *term)
// {
//     this->mTermName = term->mTermName;
//     this->mTermCode = term->mTermCode;
//     this->mPTermStartDate = term->mPTermStartDate;
//     this->mPTermEndDate = term->mPTermEndDate;
//     this->mPGradesDeadline = term->mPGradesDeadline;
//     this->mPCourses = term->mPCourses;
//     this->mCourseNums = term->mCourseNums;
//     return *this;
// }

// Term::~Term()
// {
//     delete[] this->courses;
// }

#endif