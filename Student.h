#ifndef __STUDENT_H_
#define __STUDENT_H_
class Student
{
private:
    string name;
    string password;
    uint8_t *salt;
    int id;
    Course *courses;
    int courseNums;

public:
    Student(string name, string password, uint8_t *salt,
            int id, Course *courses, int courseNums);
    Student();

    string getName();
    string getPassword();
    uint8_t *getSalt();

    int getId();
    Course *getCourses();
    int getCourseNums();

    void setName(string name);
    void setPassword(string password);
    void setSalt(uint8_t *salt);
    void setId(int id);
    void setCourses(Course *courses);
    void setCourseNums(int courseNums);
    void printStudent();
    ~Student();
};

Student::Student(string name, string password, uint8_t *salt,
                 int id, Course *courses, int courseNums)
{
    this->name = name;
    this->password = password;
    this->salt = salt;
    this->id = id;
    this->courses = courses;
    this->courseNums = courseNums;
}

Student::Student()
{
    this->name = "";
    this->password = "";
    this->id = 0;
    this->courses = nullptr;
    this->courseNums = 0;
}

string Student::getName()
{
    return this->name;
}

string Student::getPassword()
{
    return this->password;
}

uint8_t *Student::getSalt()
{
    return this->salt;
}

int Student::getId()
{
    return this->id;
}

Course *Student::getCourses()
{
    return this->courses;
}

int Student::getCourseNums()
{
    return this->courseNums;
}

void Student::setName(string name)
{
    this->name = name;
}

void Student::setPassword(string password)
{
    this->password = password;
}

void Student::setSalt(uint8_t *salt)
{
    this->salt = salt;
}

void Student::setId(int id)
{
    this->id = id;
}

void Student::setCourses(Course *courses)
{
    this->courses = courses;
}

void Student::setCourseNums(int courseNums)
{
    this->courseNums = courseNums;
}

void Student::printStudent()
{
    cout << "Name: " << this->name << endl;
    cout << "Password: " << this->password << endl;
    cout << "ID: " << this->id << endl;
    cout << "Courses: " << endl;
    for (int i = 0; i < this->courseNums; i++)
        this->courses[i].printCourse();
}

Student::~Student()
{
    delete[] this->courses;
    delete[] this->salt;
}

#endif