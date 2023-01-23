#ifndef __PROFESSOR_H_
#define __PROFESSOR_H_

class Professor : public Person
{
private:
    Course *courses;
    int courseNums;

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
    this->courses = courses;
    this->courseNums = courseNums;
}

Professor::Professor() : Person()
{
    this->courses = nullptr;
    this->courseNums = 0;
}

Course *Professor::getCourses()
{
    return this->courses;
}

int Professor::getCourseNums()
{
    return this->courseNums;
}

void Professor::setCourses(Course *courses)
{
    this->courses = courses;
}

void Professor::setCourseNums(int courseNums)
{
    this->courseNums = courseNums;
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