#ifndef __PROFESSOR_H_
#define __PROFESSOR_H_

class Professor : public Person
{
private:
    Course *mPCourses;
    int mCourseNums;

public:
    Professor(string name, string password, uint8_t *salt,
              int id, Course *courses, int courseNums);
    Professor();
    Course *getCourses();
    int getCourseNums();

    void setCourses(Course *courses);
    void setCourseNums(int courseNums);

    void print();

    Professor *operator=(Professor *professor);
    // ~Professor();
};

Professor::Professor(string name, string password, uint8_t *salt,
                     int id, Course *courses,
                     int courseNums) : Person(name, password, salt, id)
{
    this->mPCourses = courses;
    this->mCourseNums = courseNums;
}

Professor::Professor() : Person()
{
    this->mPCourses = nullptr;
    this->mCourseNums = 0;
}

Course *Professor::getCourses()
{
    return this->mPCourses;
}

int Professor::getCourseNums()
{
    return this->mCourseNums;
}

void Professor::setCourses(Course *courses)
{
    this->mPCourses = courses;
}

void Professor::setCourseNums(int courseNums)
{
    this->mCourseNums = courseNums;
}

void Professor::print()
{
    cout << "Name: " << this->getName() << endl;
    cout << "ID: " << this->getId() << endl;
    cout << "Course Num: " << this->getCourseNums() << endl;
    for (int i = 0; i < this->getCourseNums(); i++)
        cout << "Course " << i << " Name: " << this->getCourses()[i].getCourseName() << endl;
}

Professor *Professor::operator=(Professor *professor)
{
    this->setName(professor->getName());
    this->setPassword(professor->getPassword());
    this->setSalt(professor->getSalt());
    this->setId(professor->getId());
    this->setCourses(professor->getCourses());
    this->setCourseNums(professor->getCourseNums());
    return this;
}

// Professor::~Professor()
// {
//     delete[] this->courses;
// }

#endif // __PROFESSOR_H_