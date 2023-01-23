#ifndef __COURSE_H_
#define __COURSE_H_
#define MAX_SYLLABUS_SIZE 40
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
    Exam *mPExams;
    int mExamNums;
    Professor *mPProfessor;

public:
    Course(string courseName, int courseCode,
           char *pCourseSyllabus, Date *courseStartDate,
           Date *courseEndDate, Date *midTermDate,
           Date *finalExamDate, Exam *exams, int examNums, Professor *professor);

    Course(); // default constructor
    string getCourseName();
    int getCourseCode();
    char *getCourseSyllabus();
    Date *getCourseStartDate();
    Date *getCourseEndDate();
    Date *getMidTermDate();
    Date *getFinalExamDate();
    Exam *getExams();
    int getExamNums();
    Professor *getProfessor();

    void setCourseName(string courseName);
    void setCourseCode(int courseCode);
    void setCourseSyllabus(char *pCourseSyllabus);
    void setCourseStartDate(Date *courseStartDate);
    void setCourseEndDate(Date *courseEndDate);
    void setMidTermDate(Date *midTermDate);
    void setFinalExamDate(Date *finalExamDate);
    void setExams(Exam *exams);
    void setExamNums(int examNums);
    void setProfessor(Professor *professor);

    void print();

    // operator overloading for = gets a course* and assigns it to another course*:
    Course *operator=(Course *course);
    // ~Course();
};

Course::Course(string courseName, int courseCode,
               char *pCourseSyllabus, Date *courseStartDate,
               Date *courseEndDate, Date *midTermDate,
               Date *finalExamDate, Exam *exams, int examNums, Professor *professor)
{
    this->mCourseName = courseName;
    this->mCourseCode = courseCode;
    this->mPCourseSyllabus = pCourseSyllabus;
    this->mPCourseStartDate = courseStartDate;
    this->mPCourseEndDate = courseEndDate;
    this->mPMidTermDate = midTermDate;
    this->mPFinalExamDate = finalExamDate;
    this->mPExams = exams;
    this->mExamNums = examNums;
    this->mPProfessor = professor;
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
    this->mPExams = nullptr;
    this->mExamNums = 0;
    this->mPProfessor = nullptr;
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

Exam *Course::getExams()
{
    return this->mPExams;
}

int Course::getExamNums()
{
    return this->mExamNums;
}

Professor *Course::getProfessor()
{
    return this->mPProfessor;
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

void Course::setExams(Exam *exams)
{
    this->mPExams = exams;
}

void Course::setExamNums(int examNums)
{
    this->mExamNums = examNums;
}

void Course::setProfessor(Professor *professor)
{
    this->mPProfessor = professor;
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
        this->mPExams[i].printExam();
    }
}

Course *Course::operator=(Course *course)
{
    this->mCourseName = course->getCourseName();
    this->mCourseCode = course->getCourseCode();
    this->mPCourseSyllabus = course->getCourseSyllabus();
    this->mPCourseStartDate = course->getCourseStartDate();
    this->mPCourseEndDate = course->getCourseEndDate();
    this->mPMidTermDate = course->getMidTermDate();
    this->mPFinalExamDate = course->getFinalExamDate();
    this->mPExams = course->getExams();
    this->mExamNums = course->getExamNums();
    this->mPProfessor = course->getProfessor();
    return this;
}

// Course::~Course()
// {
//     delete[] this->exams;
// }

#endif