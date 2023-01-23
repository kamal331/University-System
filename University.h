#ifndef __UNIVERSITY_H_
#define __UNIVERSITY_H_

class University
{
private:
    string universityName;

    Term *terms;
    Course *courses;
    Student *students;
    Professor *professors;
    int termNums;
    int courseNums;
    int studentNums;
    int professorNums;

public:
    University(string universityName, Term *terms, int termNums,
               Course *courses, int courseNums,
               Student *students, int studentNums,
               Professor *professors, int professorNums);
    University();
    string getUniversityName();
    Term *getTerms();
    Course *getCourses();
    Student *getStudents();
    Professor *getProfessors();
    int getTermNums();
    int getCourseNums();
    int getStudentNums();
    int getProfessorNums();

    void setUniversityName(string universityName);
    void setTerms(Term *terms);
    void setCourses(Course *courses);
    void setStudents(Student *students);
    void setProfessors(Professor *professors);
    void setTermNums(int termNums);
    void setCourseNums(int courseNums);
    void setStudentNums(int studentNums);
    void setProfessorNums(int professorNums);

    void print();
    // ~University();
};

University::University(string universityName, Term *terms, int termNums,
                       Course *courses, int courseNums,
                       Student *students, int studentNums,
                       Professor *professors, int professorNums)
{
    this->universityName = universityName;
    this->terms = terms;
    this->termNums = termNums;
    this->courses = courses;
    this->courseNums = courseNums;
    this->students = students;
    this->studentNums = studentNums;
    this->professors = professors;
    this->professorNums = professorNums;
}

University::University()
{
    this->universityName = "Unknown";
    this->terms = nullptr;
    this->termNums = 0;
    this->courses = nullptr;
    this->courseNums = 0;
    this->students = nullptr;
    this->studentNums = 0;
    this->professors = nullptr;
    this->professorNums = 0;
}

string University::getUniversityName()
{
    return this->universityName;
}

Term *University::getTerms()
{
    return this->terms;
}

Course *University::getCourses()
{
    return this->courses;
}

Student *University::getStudents()
{
    return this->students;
}

Professor *University::getProfessors()
{
    return this->professors;
}

int University::getTermNums()
{
    return this->termNums;
}

int University::getCourseNums()
{
    return this->courseNums;
}

int University::getStudentNums()
{
    return this->studentNums;
}

int University::getProfessorNums()
{
    return this->professorNums;
}

void University::setUniversityName(string universityName)
{
    this->universityName = universityName;
}

void University::setTerms(Term *terms)
{
    this->terms = terms;
}

void University::setCourses(Course *courses)
{
    this->courses = courses;
}

void University::setStudents(Student *students)
{
    this->students = students;
}

void University::setProfessors(Professor *professors)
{
    this->professors = professors;
}

void University::setTermNums(int termNums)
{
    this->termNums = termNums;
}

void University::setCourseNums(int courseNums)
{
    this->courseNums = courseNums;
}

void University::setStudentNums(int studentNums)
{
    this->studentNums = studentNums;
}

void University::setProfessorNums(int professorNums)
{
    this->professorNums = professorNums;
}

void University::print()
{
    cout << "University Name: " << this->universityName << endl;
    cout << "Terms: " << endl;
    for (int i = 0; i < this->termNums; i++)
    {
        cout << "Term " << i << ": " << endl;
        this->terms[i].printTerm();
    }

    cout << "Courses: " << endl;
    for (int i = 0; i < this->courseNums; i++)
    {
        cout << "Course " << i << ": " << endl;
        this->courses[i].printCourse();
    }

    cout << "Students: " << endl;
    for (int i = 0; i < this->studentNums; i++)
    {
        cout << "Student " << i << ": " << endl;
        this->students[i].print();
    }

    cout << "Professors: " << endl;
    for (int i = 0; i < this->professorNums; i++)
    {
        cout << "Professor " << i << ": " << endl;
        this->professors[i].print();
    }
}

// University::~University()
// {
//     delete[] this->terms;
//     delete[] this->courses;
//     delete[] this->students;
//     delete[] this->professors;
// }

#endif