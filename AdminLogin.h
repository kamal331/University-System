#ifndef __ADMINLOGIN_H_
#define __ADMINLOGIN_H_

// ================== Admin Menu ==================

void adminMenu()
{
    while (!adminLogin())
    {
        cout << "Try again? (y/n)" << endl;
        string choice;
        cin >> choice;
        if (choice == "n")
            return;
    }
    cout << "=========== 🧑‍💻  Welcome to the Admin Menu 🧑‍💻  ===========" << endl;
    string choices[7] = {"1. Add a student 🧑‍🎓",
                         "2. Add a professor 🧑‍🏫",
                         "3. Add a course 📚",
                         "4. Add a term 📅",
                         "5. Set a course to a professor 📝",
                         "6. Back to Last Page 🔙",
                         "7. Exit 🚪"};
    string choice;

    while (true)
    {
        CLEAR_SCREEN();
        cout << "What would you like to do?" << endl;
        for (string choice : choices) // Print Menu
            cout << choice << endl;
        cin >> choice;

        if (choice == "1")
        {
            addStudent();
            gStudents.back().print();
            BACK_TO_LAST_PAGE();
        }
        else if (choice == "2")
        {
            addProfessor();
            gProfessors.back().print();
            BACK_TO_LAST_PAGE();
        }
        else if (choice == "3")
        {
            addCourse();
            gCourses.back().print();
            BACK_TO_LAST_PAGE();
        }
        else if (choice == "4")
        {
            addTerm();
            gTerms.back().print();
            BACK_TO_LAST_PAGE();
        }

        else if (choice == "5")
        {
            setCourseToProfessor();
            BACK_TO_LAST_PAGE();
        }

        else if (choice == "6")
        {
            break;
        }
        else if (choice == "7")
        {
            cout << "You chose to exit 🚪" << endl;
            exit(0);
        }

        else
            cout << "Invalid choice" << endl;
    }
}

bool adminLogin()
{
    CLEAR_SCREEN();
    int id;
    string password;

    cout << "Enter your ID: ";
    cin >> id;
    password = getpass("Enter your password: ");

    for (int i = 0; i < gAdminId; i++)
    {
        if (gAdmins.at(i).getId() == id)
        {
            if (verifyArgon2Hash(password, gAdmins.at(i).getPassword(), gAdmins.at(i).getSalt()))
            {
                cout << "Login successful ✅" << endl;
                return true;
            }
            else
                cout << "Wrong password ❌" << endl;
        }
    }
    cout << "Login Failed!" << endl;
    return false;
}

void addStudent()
{
    CLEAR_SCREEN();
    string name;
    string password;
    uint8_t *salt = new uint8_t[32];

    salt = randomString(32);
    int id = _getNewStudentId();

    EMPTY_BUFFER();

    cout << "Enter student's name: ";
    cin >> name;

    password = _getPaasword();

    Student s(name, getArgon2Hash(password, salt), salt, id, 0);
    gStudents.push_back(s);
    gStudentId++;
    cout << "Student added successfully ✅" << endl;
}

void addProfessor()
{
    CLEAR_SCREEN();
    string name;
    string password;
    uint8_t *salt = new uint8_t[32];

    salt = randomString(32);
    int id = _getNewProfessorId();

    cout << "Enter professor's name: ";
    EMPTY_BUFFER();

    getline(cin, name);

    password = _getPaasword();

    Professor prof(name, getArgon2Hash(password, salt), salt, id, 0);

    gProfessorId++;

    gProfessors.push_back(prof);

    cout << "Professor added successfully ✅" << endl;
}

void addCourse()
{
    CLEAR_SCREEN();
    string name;

    cout << "Enter course's name: ";
    cin >> name;

    int code = _getNewCourseCode();

    char *pSyllabus = new char[MAX_SYLLABUS_SIZE];

    cout << "Enter course's syllabus: ";
    char c = '=';
    int i = 0;
    EMPTY_BUFFER();

    c = getchar();
    while ((c != '\n') && (c != EOF) && (i < MAX_SYLLABUS_SIZE))
    {
        pSyllabus[i] = c;
        ++i;
        c = getchar();
    }
    pSyllabus[i] = '\0';

    Date *pStartDate = new Date();
    Date *pEndDate = new Date();
    Date *pMidTermDate = new Date();
    Date *pFinalExamDate = new Date();

    cout << "Enter course's start date: ";
    cin >> *pStartDate;

    cout << "Enter course's end date: ";
    cin >> *pEndDate;

    cout << "Enter course's mid term date: ";
    cin >> *pMidTermDate;

    cout << "Enter course's final exam date: ";
    cin >> *pFinalExamDate;

    vector<Exam> exams;
    int examNum = 0;

    // Professor *pProfessor = new Professor();
    cout << "This course is for which professor? (Enter professor's ID):" << endl;
    int id;
    cin >> id;

    cout << "This course is avaliable for which term? " << endl;
    int termCode;
    cin >> termCode;

    Course course(name, code, pSyllabus, pStartDate, pEndDate,
                  pMidTermDate, pFinalExamDate, exams, examNum, &gProfessors.at(id));
    gCourses.push_back(course);

    gProfessors.at(id).setCourse(course);
    gProfessors.at(id).setCourseNums(gProfessors.at(id).getCourseNums() + 1);
    gCourseCode++;
}

void setCourseToProfessor()
{
    CLEAR_SCREEN();
    printAllCourses();
    cout << "Which professor do you want to set course for? (Enter professor's ID):" << endl;
    int id;
    cin >> id;

    cout << "Which course do you want to set for this professor? (Enter course's code):" << endl;
    int code;
    cin >> code;

    gProfessors.at(id).setCourse(gCourses.at(code));
    cout << "Course set successfully ✅" << endl;
}

void printAllCourses()
{
    CLEAR_SCREEN();
    cout << "All courses: " << endl;
    for (int i = 0; i < gCourses.size(); i++)
    {
        cout << i << ". " << gCourses.at(i).getCourseName() << endl;
        cout << "Course Code: " << gCourses.at(i).getCourseCode() << endl;
        cout << "Course Name: " << gCourses.at(i).getCourseName() << endl;
        cout << "Course Professor: " << gCourses.at(i).getProfessor()->getName() << endl;
        cout << "Exam numbers: " << gCourses.at(i).getExamNums() << endl;
        for (int j = 0; j < gCourses.at(i).getExamNums(); j++)
        {
            cout << "Exam Name: " << gCourses.at(i).getExams().at(j).getExamName() << endl;
        }
        cout << "----------------------------------------" << endl;
    }
}

Term addTerm()
{
    CLEAR_SCREEN();
    string name;
    int code = _getNewTermCode();

    EMPTY_BUFFER();
    cout << "Enter term's name: ";
    getline(cin, name);

    Date *pStartDate = new Date();
    Date *pEndDate = new Date();
    Date *pGradesDeadLine = new Date();

    cout << "Enter term's start date: ";
    cin >> *pStartDate;

    cout << "Enter term's end date: ";
    cin >> *pEndDate;

    cout << "Enter term's grades deadline: ";
    cin >> *pGradesDeadLine;

    // cout << "How many courses do you want to add? ";
    // int courseNum;
    // cin >> courseNum;

    // Course *pCourses = new Course[courseNum];
    // for (int i = 0; i < courseNum; i++)
    // {
    //     pCourses[i] = *addCourse();
    // }

    // Term *term = new Term(name, code, pStartDate, pEndDate, pGradesDeadLine, pCourses, courseNum);
    Term term(name, code, pStartDate, pEndDate, pGradesDeadLine, 0);

    gTerms.push_back(term);

    gTermCode++;
    cout << "Term added successfully ✅" << endl;

    return term;
}

#endif