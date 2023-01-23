#ifndef __STUDENT_H_
#define __STUDENT_H_
class Student : public Person
{
private:
    Course *courses;
    int courseNums;

public:
    Student(string name, string password, uint8_t *salt,
            int id, Course *courses, int courseNums);
    Student();
    Course *getCourses();
    int getCourseNums();

    void setCourses(Course *courses);
    void setCourseNums(int courseNums);

    void print();

    Student *operator=(Student *student);
    // ~Student();
};

Student::Student(string name, string password, uint8_t *salt,
                 int id, Course *courses,
                 int courseNums) : Person(name, password, salt, id)
{
    this->courses = courses;
    this->courseNums = courseNums;
}

Student::Student() : Person()
{
    this->courses = nullptr;
    this->courseNums = 0;
}

Course *Student::getCourses()
{
    return this->courses;
}

int Student::getCourseNums()
{
    return this->courseNums;
}

void Student::setCourses(Course *courses)
{
    this->courses = courses;
}

void Student::setCourseNums(int courseNums)
{
    this->courseNums = courseNums;
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

Student *Student::operator=(Student *student)
{
    this->setName(student->getName());
    this->setPassword(student->getPassword());
    this->setSalt(student->getSalt());
    this->setId(student->getId());
    this->setCourses(student->getCourses());
    this->setCourseNums(student->getCourseNums());
    return this;
}

// Student::~Student()
// {
//     delete[] this->courses;
// }

#endif