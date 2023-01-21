#ifndef __COURSE_H_
#define __COURSE_H_

class Course
{
private:
    string courseName;
    int courseCode;
    string courseSyllabus;
    Date courseStartDate;
    Date courseEndDate;
    Date midTermDate;
    Date finalExamDate;
    Exam *exams;
    int examNums;

public:
    Course(string courseName, int courseCode,
           string courseSyllabus, Date courseStartDate,
           Date courseEndDate, Date midTermDate,
           Date finalExamDate, Exam *exams, int examNums);

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

    void setCourseName(string courseName);
    void setCourseCode(int courseCode);
    void setCourseSyllabus(string courseSyllabus);
    void setCourseStartDate(Date courseStartDate);
    void setCourseEndDate(Date courseEndDate);
    void setMidTermDate(Date midTermDate);
    void setFinalExamDate(Date finalExamDate);
    void setExams(Exam *exams);
    void setExamNums(int examNums);
    void printCourse();
    ~Course();
};

Course::Course(string courseName, int courseCode,
               string courseSyllabus, Date courseStartDate,
               Date courseEndDate, Date midTermDate,
               Date finalExamDate, Exam *exams, int examNums)
{
    this->courseName = courseName;
    this->courseCode = courseCode;
    this->courseSyllabus = courseSyllabus;
    this->courseStartDate = courseStartDate;
    this->courseEndDate = courseEndDate;
    this->midTermDate = midTermDate;
    this->finalExamDate = finalExamDate;
    this->exams = exams;
    this->examNums = examNums;
}

Course::Course()
{
    this->courseName = "";
    this->courseCode = 0;
    this->courseSyllabus = "";
    this->courseStartDate = Date();
    this->courseEndDate = Date();
    this->midTermDate = Date();
    this->finalExamDate = Date();
    this->exams = nullptr;
    this->examNums = 0;
}

string Course::getCourseName()
{
    return this->courseName;
}

int Course::getCourseCode()
{
    return this->courseCode;
}

string Course::getCourseSyllabus()
{
    return this->courseSyllabus;
}

Date Course::getCourseStartDate()
{
    return this->courseStartDate;
}

Date Course::getCourseEndDate()
{
    return this->courseEndDate;
}

Date Course::getMidTermDate()
{
    return this->midTermDate;
}

Date Course::getFinalExamDate()
{
    return this->finalExamDate;
}

Exam *Course::getExams()
{
    return this->exams;
}

int Course::getExamNums()
{
    return this->examNums;
}

void Course::setCourseName(string courseName)
{
    this->courseName = courseName;
}

void Course::setCourseCode(int courseCode)
{
    this->courseCode = courseCode;
}

void Course::setCourseSyllabus(string courseSyllabus)
{
    this->courseSyllabus = courseSyllabus;
}

void Course::setCourseStartDate(Date courseStartDate)
{
    this->courseStartDate = courseStartDate;
}

void Course::setCourseEndDate(Date courseEndDate)
{
    this->courseEndDate = courseEndDate;
}

void Course::setMidTermDate(Date midTermDate)
{
    this->midTermDate = midTermDate;
}

void Course::setFinalExamDate(Date finalExamDate)
{
    this->finalExamDate = finalExamDate;
}

void Course::setExams(Exam *exams)
{
    this->exams = exams;
}

void Course::setExamNums(int examNums)
{
    this->examNums = examNums;
}

void Course::printCourse()
{
    cout << "Course Name: " << this->courseName << endl;
    cout << "Course Code: " << this->courseCode << endl;
    cout << "Course Syllabus: " << this->courseSyllabus << endl;
    cout << "Course Start Date: " << this->courseStartDate.getDay() << "/" << this->courseStartDate.getMonth() << "/" << this->courseStartDate.getYear() << endl;
    cout << "Course End Date: " << this->courseEndDate.getDay() << "/" << this->courseEndDate.getMonth() << "/" << this->courseEndDate.getYear() << endl;
    cout << "Midterm Date: " << this->midTermDate.getDay() << "/" << this->midTermDate.getMonth() << "/" << this->midTermDate.getYear() << endl;
    cout << "Final Exam Date: " << this->finalExamDate.getDay() << "/" << this->finalExamDate.getMonth() << "/" << this->finalExamDate.getYear() << endl;
    cout << "Exams: " << endl;
    for (int i = 0; i < this->examNums; i++)
    {
        if (i != 0)
            cout << "\n"
                 << "========= Next Exam ========="
                 << "\n"
                 << endl;
        this->exams[i].printExam();
    }
}

Course::~Course()
{
    delete[] this->exams;
}

#endif