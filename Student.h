#ifndef __STUDENT_H_
#define __STUDENT_H_
class Student : public Person
{
private:
    vector<Course> mCourses;
    int mCourseNums;

public:
    Student(string name, string password, uint8_t *salt,
            int id, int courseNums);
    Student();
    vector<Course> &getCourses();
    int getCourseNums();

    void setCourses(Course courses);
    void setCourseNums(int courseNums);

    void print();

    // Student *operator=(Student *student);
    // ~Student();
};

Student::Student(string name, string password, uint8_t *salt,
                 int id, int courseNums) : Person(name, password, salt, id)
{
    this->mCourseNums = courseNums;
}

Student::Student() : Person()
{
    this->mCourseNums = 0;
}

vector<Course> &Student::getCourses()
{
    return this->mCourses;
}

int Student::getCourseNums()
{
    return this->mCourseNums;
}

void Student::setCourses(Course courses)
{
    this->mCourses.push_back(courses);
}

void Student::setCourseNums(int courseNums)
{
    this->mCourseNums = courseNums;
}

void Student::print()
{
    cout << "Name: " << this->getName() << endl;
    cout << "ID: " << this->getId() << endl;
    cout << "Course Num: " << this->getCourseNums() << endl;
    for (int i = 0; i < this->getCourseNums(); i++)
        cout << "Course " << i + 1 << ": "
             << this->getCourses()[i].getCourseName() << endl;
}

// Student *Student::operator=(Student *student)
// {
//     this->setName(student->getName());
//     this->setPassword(student->getPassword());
//     this->setSalt(student->getSalt());
//     this->setId(student->getId());
//     this->setCourses(student->getCourses());
//     this->setCourseNums(student->getCourseNums());
//     return this;
// }

// Student::~Student()
// {
//     delete[] this->courses;
// }

#endif