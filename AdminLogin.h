#ifndef __ADMINLOGIN_H_
#define __ADMINLOGIN_H_

void mainMenu()
{
    cout << "=========== 🏢  Welcome to the University 🏢  ===========" << endl;
    string choices[5] = {"1. Login as a student 🧑‍🎓",
                         "2. Login as a professor 🧑‍🏫",
                         "3. Login as an admin 🧑‍💻",
                         "4. Exit 🚪"};
    string choice;
    while (true)
    {
        CLEAR_SCREEN();
        cout << "What would you like to do?" << endl;
        for (string choice : choices)
            cout << choice << endl;
        cin >> choice;

        if (choice == "1")
        {
            cout << "You chose to login as a student" << endl;
            break;
        }
        else if (choice == "2")
        {
            cout << "You chose to login as a professor" << endl;
            break;
        }
        else if (choice == "3")
        {
            adminMenu();
        }
        else if (choice == "4")
        {
            cout << "You chose to exit" << endl;
            exit(0);
        }
        else
        {
            cout << "Invalid choice" << endl;
        }
    }
}

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
    string choices[6] = {"1. Add a student 🧑‍🎓",
                         "2. Add a professor 🧑‍🏫",
                         "3. Add a course 📚",
                         "4. Add a term 📅",
                         "5. Back to Last Page 🔙",
                         "6. Exit 🚪"};
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
            gPStudents[gStudentId - 1].print();
            BACK_TO_LAST_PAGE();
        }
        else if (choice == "2")
        {
            addProfessor();
            gPProfessors[gProfessorId - 1].print();
            BACK_TO_LAST_PAGE();
        }
        else if (choice == "3")
        {
            addCourse();
            gPCourses[gCourseCode - 1].print();
            BACK_TO_LAST_PAGE();
        }
        else if (choice == "4")
        {
            addTerm();
            gPTerms[gTermCode - 1].print();
            BACK_TO_LAST_PAGE();
        }

        else if (choice == "5")
        {
            break;
        }
        else if (choice == "6")
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
        if (gPAdmins[i].getId() == id)
        {
            if (verifyArgon2Hash(password, gPAdmins[i].getPassword(), gPAdmins[i].getSalt()))
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

    cout << "Enter student's name: ";
    cin >> name;

    _getPaasword();

    Student *s = new Student(name, getArgon2Hash(password, salt), salt, id, nullptr, 0);
    gPStudents[gStudentId - 1] = s;
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
    cin >> name;

    _getPaasword();

    Professor *prof = new Professor(name, getArgon2Hash(password, salt), salt, id, nullptr, 0);
    gPProfessors[gProfessorId - 1] = prof;
    cout << "Professor added successfully ✅" << endl;
}

Course *addCourse()
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

    Exam *pExams = new Exam[MAX_EXAM_NUM];
    int examNum = 0;

    Professor *pProfessors = new Professor;

    Course *course = new Course(name, code, pSyllabus, pStartDate, pEndDate,
                                pMidTermDate, pFinalExamDate, pExams, examNum, pProfessors);

    gPCourses[gCourseCode - 1] = course;
    cout << "Course added successfully ✅" << endl;

    return course;
}

Term *addTerm()
{
    CLEAR_SCREEN();
    string name;
    int code = _getNewTermCode();

    cout << "Enter term's name: ";
    cin >> name;

    Date *pStartDate = new Date();
    Date *pEndDate = new Date();
    Date *pGradesDeadLine = new Date();

    cout << "Enter term's start date: ";
    cin >> *pStartDate;

    cout << "Enter term's end date: ";
    cin >> *pEndDate;

    cout << "Enter term's grades deadline: ";
    cin >> *pGradesDeadLine;

    cout << "How many courses do you want to add? ";
    int courseNum;
    cin >> courseNum;

    Course *pCourses = new Course[courseNum];
    for (int i = 0; i < courseNum; i++)
    {
        pCourses[i] = *addCourse();
    }

    Term *term = new Term(name, code, pStartDate, pEndDate, pGradesDeadLine, pCourses, courseNum);

    gPTerms[gTermCode - 1] = term;
    cout << "Term added successfully ✅" << endl;

    return term;
}

#endif