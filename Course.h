#ifndef __COURSE_H_
#define __COURSE_H_

#define MAX_EXAM_NUM 10
#define MAX_SYLLABUS_SIZE 40

/*******************************************************************
 * @brief Course class which will be used for storing course data. *
 *        Course class has a vector of Exam objects.               *
 *        Course class has a pointer to its professor.             *
 *                                                                 *
 * @param CourseName, CourseCode, CourseSyllabus, CourseStartDate, *
 *        CourseEndDate, MidTermDate, FinalExamDate, Exams,        *
 *        ExamNums, Professor                                      *
 *******************************************************************/
class Course
{
private:
    string mCourseName;
    int mCourseCode;
    char *mPCourseSyllabus;
    // char[] mCourseSyllabus;
    Date *mPCourseStartDate;
    Date *mPCourseEndDate;
    Date *mPMidTermDate;
    Date *mPFinalExamDate;
    vector<Exam> mExams;
    int mExamNums;
    Professor *mProfessor;

public:
    Course(string courseName, int courseCode,
           char *pCourseSyllabus, Date *courseStartDate,
           Date *courseEndDate, Date *midTermDate,
           Date *finalExamDate, vector<Exam> &mExams,
           int examNums, Professor *professor);

    Course(); // default constructor
    string getCourseName();
    int getCourseCode();
    char *getCourseSyllabus();
    Date *getCourseStartDate();
    Date *getCourseEndDate();
    Date *getMidTermDate();
    Date *getFinalExamDate();
    vector<Exam> &getExams();
    int getExamNums();
    Professor *getProfessor();

    void setCourseName(string courseName);
    void setCourseCode(int courseCode);
    void setCourseSyllabus(char *pCourseSyllabus);
    void setCourseStartDate(Date *courseStartDate);
    void setCourseEndDate(Date *courseEndDate);
    void setMidTermDate(Date *midTermDate);
    void setFinalExamDate(Date *finalExamDate);
    void setExams(Exam &exams);
    void setExamNums(int examNums);
    void setProfessor(Professor *professor);

    void print();

    // operator overloading for = gets a course* and assigns it to another course*:
    // Course operator=(Course *course);
    // ~Course();
};

Course::Course(string courseName, int courseCode,
               char *pCourseSyllabus, Date *courseStartDate,
               Date *courseEndDate, Date *midTermDate,
               Date *finalExamDate, vector<Exam> &exams,
               int examNums, Professor *professor)
{
    this->mCourseName = courseName;
    this->mCourseCode = courseCode;
    this->mPCourseSyllabus = pCourseSyllabus;
    this->mPCourseStartDate = courseStartDate;
    this->mPCourseEndDate = courseEndDate;
    this->mPMidTermDate = midTermDate;
    this->mPFinalExamDate = finalExamDate;
    this->mExams = exams;
    this->mExamNums = examNums;
    this->mProfessor = professor;
}

Course::Course()
{
    this->mCourseName = "";
    this->mCourseCode = 0;
    this->mPCourseSyllabus = nullptr;
    this->mPCourseStartDate = new Date();
    this->mPCourseEndDate = new Date();
    this->mPMidTermDate = new Date();
    this->mPFinalExamDate = new Date();
    this->mExamNums = 0;
}

string Course::getCourseName()
{
    return this->mCourseName;
}

int Course::getCourseCode()
{
    return this->mCourseCode;
}

char *Course::getCourseSyllabus()
{
    return this->mPCourseSyllabus;
}

Date *Course::getCourseStartDate()
{
    return this->mPCourseStartDate;
}

Date *Course::getCourseEndDate()
{
    return this->mPCourseEndDate;
}

Date *Course::getMidTermDate()
{
    return this->mPMidTermDate;
}

Date *Course::getFinalExamDate()
{
    return this->mPFinalExamDate;
}

vector<Exam> &Course::getExams()
{
    return this->mExams;
}

int Course::getExamNums()
{
    return this->mExamNums;
}

Professor *Course::getProfessor()
{
    return this->mProfessor;
}

void Course::setCourseName(string courseName)
{
    this->mCourseName = courseName;
}

void Course::setCourseCode(int courseCode)
{
    this->mCourseCode = courseCode;
}

void Course::setCourseSyllabus(char *pCourseSyllabus)
{
    this->mPCourseSyllabus = pCourseSyllabus;
}

void Course::setCourseStartDate(Date *courseStartDate)
{
    this->mPCourseStartDate = courseStartDate;
}

void Course::setCourseEndDate(Date *courseEndDate)
{
    this->mPCourseEndDate = courseEndDate;
}

void Course::setMidTermDate(Date *midTermDate)
{
    this->mPMidTermDate = midTermDate;
}

void Course::setFinalExamDate(Date *finalExamDate)
{
    this->mPFinalExamDate = finalExamDate;
}

void Course::setExams(Exam &exams)
{
    mExams.push_back(exams);
}

void Course::setExamNums(int examNums)
{
    this->mExamNums = examNums;
}

void Course::setProfessor(Professor *professor)
{
    this->mProfessor = professor;
}

void Course::print()
{
    cout << "Course Name: " << this->mCourseName << endl;
    cout << "Course Code: " << this->mCourseCode << endl;

    /// @bug @ERROR: invalid use of incomplete type 'class Professor'
    // cout << "Course Proffesor: " << this->professor->getName() << endl;
    cout << "Course Syllabus: ";
    for (int i = 0; mPCourseSyllabus[i] != '\0'; i++)
    {
        cout << mPCourseSyllabus[i];
    }

    cout << endl;

    cout << "Course Start Date: " << *mPCourseStartDate << endl;
    cout << "Course End Date: " << *mPCourseEndDate << endl;
    cout << "Midterm Date: " << *mPMidTermDate << endl;
    cout << "Final Exam Date: " << *mPFinalExamDate << endl;
    cout << "Exams: " << endl;
    for (int i = 0; i < this->mExamNums; i++)
    {
        if (i != 0)
            cout << "\n"
                 << "========= Next Exam ========="
                 << "\n"
                 << endl;
        this->mExams.at(i).printExam();
    }
}

// Course Course::operator=(Course *course)
// {
//     cout << "operator= called" << endl;
//     setCourseName(course->getCourseName());
//     cout << "111111111111" << endl;
//     mCourseCode = course->getCourseCode();
//     cout << "222222222222" << endl;
//     mPCourseSyllabus = course->getCourseSyllabus();
//     cout << "333333333333" << endl;
//     mPCourseStartDate = course->getCourseStartDate();
//     cout << "444444444444" << endl;
//     mPCourseEndDate = course->getCourseEndDate();
//     cout << "555555555555" << endl;
//     mPMidTermDate = course->getMidTermDate();
//     cout << "666666666666" << endl;
//     mPFinalExamDate = course->getFinalExamDate();
//     cout << "777777777777" << endl;
//     mPExams = course->getExams();
//     cout << "888888888888" << endl;
//     mExamNums = course->getExamNums();
//     cout << "999999999999" << endl;
//     mPProfessor = course->getProfessor();
//     cout << "000000000000" << endl;
//     return *this;
// }

// Course::~Course()
// {
//     delete[] this->exams;
// }

#endif