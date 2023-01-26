#ifndef __PROFESSOR_H_
#define __PROFESSOR_H_
#define MAX_COURSE_NUM 10

/****************************************************************************
 * \class Professor                                                         *
 * \brief Professor class which will be used for storing professor data.    *
 * \param courses, courseNums                                               *
 *        name, password, salt, id (are inherited from Person class)        *
 *                                                                          *
 ***************************************************************************/

class Professor : public Person
{
private:
    vector<Course> mCourses;
    int mCourseNums;

public:
    Professor(string name, string password, uint8_t *salt,
              int id, int courseNums);
    Professor();

    vector<Course> &getCourses();
    int getCourseNums();

    void setCourse(Course &courses);
    void setCourseNums(int courseNums);

    void print();
};

Professor::Professor(string name, string password, uint8_t *salt,
                     int id, int courseNums) : Person(name, password, salt, id)
{
    this->mCourseNums = courseNums;
}

Professor::Professor() : Person(), mCourseNums(0)
{
}

int Professor::getCourseNums()
{
    return this->mCourseNums;
}

vector<Course> &Professor::getCourses()
{
    return this->mCourses;
}

void Professor::setCourse(Course &courses)
{
    mCourses.push_back(courses);
}

void Professor::setCourseNums(int courseNums)
{
    this->mCourseNums = courseNums;
}

void Professor::print()
{
    cout << MAGENTA "+ Name: " RESET << this->getName() << endl;
    cout << CYAN "+ ID: " RESET << this->getId() << endl;
    cout << YELLOW "+ Course Numbers: " RESET << this->getCourseNums() << endl;
    for (int i = 0; i < this->getCourseNums(); i++)
    {
        cout << BLUE "Course " << i << ": " RESET
             << " Name: " << this->getCourses()[i].getCourseName() << endl;
        cout << WHITE "Exam Numbers: " RESET << this->getCourses()[i].getExamNums() << endl;
        for (int j = 0; j < this->getCourses()[i].getExamNums(); j++)
            cout << "Exam " << j << " => "
                 << "Name: " << this->getCourses()[i].getExams()[j].getExamName() << endl;
    }
}

#endif // __PROFESSOR_H_