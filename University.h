#ifndef __UNIVERSITY_H_
#define __UNIVERSITY_H_

class University
{
private:
    string mUniversityName;

    Term *mPTerms;
    Course *mPCourses;
    Student *mPStudents;
    Professor *mPProfessors;
    int mTermNums;
    int mCourseNums;
    int mStudentNums;
    int mProfessorNums;

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
    this->mUniversityName = universityName;
    this->mPTerms = terms;
    this->mTermNums = termNums;
    this->mPCourses = courses;
    this->mCourseNums = courseNums;
    this->mPStudents = students;
    this->mStudentNums = studentNums;
    this->mPProfessors = professors;
    this->mProfessorNums = professorNums;
}

University::University()
{
    this->mUniversityName = "Unknown";
    this->mPTerms = nullptr;
    this->mTermNums = 0;
    this->mPCourses = nullptr;
    this->mCourseNums = 0;
    this->mPStudents = nullptr;
    this->mStudentNums = 0;
    this->mPProfessors = nullptr;
    this->mProfessorNums = 0;
}

string University::getUniversityName()
{
    return this->mUniversityName;
}

Term *University::getTerms()
{
    return this->mPTerms;
}

Course *University::getCourses()
{
    return this->mPCourses;
}

Student *University::getStudents()
{
    return this->mPStudents;
}

Professor *University::getProfessors()
{
    return this->mPProfessors;
}

int University::getTermNums()
{
    return this->mTermNums;
}

int University::getCourseNums()
{
    return this->mCourseNums;
}

int University::getStudentNums()
{
    return this->mStudentNums;
}

int University::getProfessorNums()
{
    return this->mProfessorNums;
}

void University::setUniversityName(string universityName)
{
    this->mUniversityName = universityName;
}

void University::setTerms(Term *terms)
{
    this->mPTerms = terms;
}

void University::setCourses(Course *courses)
{
    this->mPCourses = courses;
}

void University::setStudents(Student *students)
{
    this->mPStudents = students;
}

void University::setProfessors(Professor *professors)
{
    this->mPProfessors = professors;
}

void University::setTermNums(int termNums)
{
    this->mTermNums = termNums;
}

void University::setCourseNums(int courseNums)
{
    this->mCourseNums = courseNums;
}

void University::setStudentNums(int studentNums)
{
    this->mStudentNums = studentNums;
}

void University::setProfessorNums(int professorNums)
{
    this->mProfessorNums = professorNums;
}

void University::print()
{
    cout << "University Name: " << this->mUniversityName << endl;
    cout << "Terms: " << endl;
    for (int i = 0; i < this->mTermNums; i++)
    {
        cout << "Term " << i << ": " << endl;
        this->mPTerms[i].printTerm();
    }

    cout << "Courses: " << endl;
    for (int i = 0; i < this->mCourseNums; i++)
    {
        cout << "Course " << i << ": " << endl;
        this->mPCourses[i].print();
    }

    cout << "Students: " << endl;
    for (int i = 0; i < this->mStudentNums; i++)
    {
        cout << "Student " << i << ": " << endl;
        this->mPStudents[i].print();
    }

    cout << "Professors: " << endl;
    for (int i = 0; i < this->mProfessorNums; i++)
    {
        cout << "Professor " << i << ": " << endl;
        this->mPProfessors[i].print();
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