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
    // Course *mPCourses;
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

    // Professor *operator=(Professor *professor);
    // gets a professor pointer and returns a professor
    // Professor operator=(Professor *professor)
    // {
    //     this->mName = professor->getName();
    //     this->mPassword = professor->getPassword();
    //     this->mPSalt = professor->getSalt();
    //     this->mId = professor->getId();
    //     vector<Course> mCourses = professor->getCourses();
    //     this->mCourseNums = professor->getCourseNums();
    //     return *this;
    // }
    // ~Professor();
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

// Professor *Professor::operator=(Professor *professor)
// {
//     this->setName(professor->getName());
//     this->setPassword(professor->getPassword());
//     this->setSalt(professor->getSalt());
//     this->setId(professor->getId());
//     this->setCourses(professor->getCourses());
//     this->setCourseNums(professor->getCourseNums());
//     return this;
// }

// Professor::~Professor()
// {
//     delete[] this->courses;
// }

#endif // __PROFESSOR_H_