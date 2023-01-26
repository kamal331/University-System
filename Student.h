#ifndef __STUDENT_H_
#define __STUDENT_H_

/*********************************************************************
 * \class Student                                                    *
 * \brief Student class which will be used for storing student data. *
 *        Student can see its courses, exams.                        *
 *        Student can take exams.                                    *
 * \param courses, courseNums,                                       *
 *        (name, password, salt, id are inherited from Person class) *
 *********************************************************************/

class Student : public Person
{
private:
    vector<Course> mCourses;
    int mCourseNums;
    double mScore;

public:
    Student(string name, string password, uint8_t *salt,
            int id, int courseNums);
    Student();
    vector<Course> &getCourses();
    int getCourseNums();
    double getScore();

    void setCourses(Course &courses);
    void setCourseNums(int courseNums);
    void setScore(double score);

    void print();
};

Student::Student(string name, string password, uint8_t *salt,
                 int id, int courseNums) : Person(name, password, salt, id)
{
    this->mCourseNums = courseNums;
    this->mScore = 0.0;
}

Student::Student() : Person()
{
    this->mCourseNums = 0;
    this->mScore = 0.0;
}

vector<Course> &Student::getCourses()
{
    return this->mCourses;
}

int Student::getCourseNums()
{
    return this->mCourseNums;
}

double Student::getScore()
{
    return this->mScore;
}

void Student::setCourses(Course &courses)
{
    this->mCourses.push_back(courses);
    mCourseNums++;
}

void Student::setCourseNums(int courseNums)
{
    this->mCourseNums = courseNums;
}

void Student::setScore(double score)
{
    this->mScore = score;
}

void Student::print()
{
    cout << BLUE "Name: " RESET << this->getName() << endl;
    cout << BLUE "ID: " RESET << this->getId() << endl;
    cout << BLUE "Course Num: " RESET << this->getCourseNums() << endl;
    for (int i = 0; i < getCourses().size(); i++)
    {
        cout << BLUE "Course " RESET << i << ": "
             << this->getCourses()[i].getCourseName() << endl;

        cout << BLUE "Syllabus: " RESET << this->getCourses()[i].getCourseSyllabus() << endl;
        cout << GREEN "Exam Numbers: " RESET << this->getCourses()[i].getExams().size() << endl;
        for (int j = 0; j < this->getCourses()[i].getExams().size(); j++)
        {
            cout << "Exam " << j + 1 << ": "
                 << this->getCourses()[i].getExams()[j].getExamName() << endl;
        }
    }
    cout << YELLOW "Score: " RESET << this->getScore() << endl;
}

#endif