#ifndef __COURSE_H_
#define __COURSE_H_

class Course
{
private:
    string mCourseName;
    int mCourseCode;
    string mCourseSyllabus;
    Date mCourseStartDate;
    Date mCourseEndDate;
    Date mMidTermDate;
    Date mFinalExamDate;
    Exam *mPExams;
    int mExamNums;
    Professor *mPProfessor;

public:
    Course(string courseName, int courseCode,
           string courseSyllabus, Date courseStartDate,
           Date courseEndDate, Date midTermDate,
           Date finalExamDate, Exam *exams, int examNums, Professor *professor);

    Course(); // default constructor
    string getCourseName();
    int getCourseCode();
    string getCourseSyllabus();
    Date getCourseStartDate();
    Date getCourseEndDate();
    Date getMidTermDate();
    Date getFinalExamDate();
    Exam *getExams();
    int getExamNums();
    Professor *getProfessor();

    void setCourseName(string courseName);
    void setCourseCode(int courseCode);
    void setCourseSyllabus(string courseSyllabus);
    void setCourseStartDate(Date courseStartDate);
    void setCourseEndDate(Date courseEndDate);
    void setMidTermDate(Date midTermDate);
    void setFinalExamDate(Date finalExamDate);
    void setExams(Exam *exams);
    void setExamNums(int examNums);
    void setProfessor(Professor *professor);

    void printCourse();

    // operator overloading for = gets a course* and assigns it to another course*:
    Course *operator=(Course *course);
    // ~Course();
};

Course::Course(string courseName, int courseCode,
               string courseSyllabus, Date courseStartDate,
               Date courseEndDate, Date midTermDate,
               Date finalExamDate, Exam *exams, int examNums, Professor *professor)
{
    this->mCourseName = courseName;
    this->mCourseCode = courseCode;
    this->mCourseSyllabus = courseSyllabus;
    this->mCourseStartDate = courseStartDate;
    this->mCourseEndDate = courseEndDate;
    this->mMidTermDate = midTermDate;
    this->mFinalExamDate = finalExamDate;
    this->mPExams = exams;
    this->mExamNums = examNums;
    this->mPProfessor = professor;
}

Course::Course()
{
    this->mCourseName = "";
    this->mCourseCode = 0;
    this->mCourseSyllabus = "";
    this->mCourseStartDate = Date();
    this->mCourseEndDate = Date();
    this->mMidTermDate = Date();
    this->mFinalExamDate = Date();
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

string Course::getCourseSyllabus()
{
    return this->mCourseSyllabus;
}

Date Course::getCourseStartDate()
{
    return this->mCourseStartDate;
}

Date Course::getCourseEndDate()
{
    return this->mCourseEndDate;
}

Date Course::getMidTermDate()
{
    return this->mMidTermDate;
}

Date Course::getFinalExamDate()
{
    return this->mFinalExamDate;
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

void Course::setCourseSyllabus(string courseSyllabus)
{
    this->mCourseSyllabus = courseSyllabus;
}

void Course::setCourseStartDate(Date courseStartDate)
{
    this->mCourseStartDate = courseStartDate;
}

void Course::setCourseEndDate(Date courseEndDate)
{
    this->mCourseEndDate = courseEndDate;
}

void Course::setMidTermDate(Date midTermDate)
{
    this->mMidTermDate = midTermDate;
}

void Course::setFinalExamDate(Date finalExamDate)
{
    this->mFinalExamDate = finalExamDate;
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

void Course::printCourse()
{
    cout << "Course Name: " << this->mCourseName << endl;
    cout << "Course Code: " << this->mCourseCode << endl;
    /// @bug @ERROR: invalid use of incomplete type 'class Professor'
    // cout << "Course Proffesor: " << this->professor->getName() << endl;
    cout << "Course Syllabus: " << this->mCourseSyllabus << endl;
    cout << "Course Start Date: " << this->mCourseStartDate.getDay() << "/" << this->mCourseStartDate.getMonth() << "/" << this->mCourseStartDate.getYear() << endl;
    cout << "Course End Date: " << this->mCourseEndDate.getDay() << "/" << this->mCourseEndDate.getMonth() << "/" << this->mCourseEndDate.getYear() << endl;
    cout << "Midterm Date: " << this->mMidTermDate.getDay() << "/" << this->mMidTermDate.getMonth() << "/" << this->mMidTermDate.getYear() << endl;
    cout << "Final Exam Date: " << this->mFinalExamDate.getDay() << "/" << this->mFinalExamDate.getMonth() << "/" << this->mFinalExamDate.getYear() << endl;
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
    this->mCourseSyllabus = course->getCourseSyllabus();
    this->mCourseStartDate = course->getCourseStartDate();
    this->mCourseEndDate = course->getCourseEndDate();
    this->mMidTermDate = course->getMidTermDate();
    this->mFinalExamDate = course->getFinalExamDate();
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