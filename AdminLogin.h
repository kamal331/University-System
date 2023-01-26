/************************************************************
 * @file AdminLogin.h                                       *
 * @brief This file contains functions to login as an admin *
 *       and add a new student, professor, course, or term. *
 *************************************************************/

#ifndef __ADMINLOGIN_H_
#define __ADMINLOGIN_H_

// ================== Admin Menu ==================

void adminMenu()
{
    while (!adminLogin())
    {
        cout << RED "Try again? (y/n)" RESET << endl;
        string choice;
        cin >> choice;
        if (choice == "n")
            return;
    }
    cout << MAGENTA "===========" RESET "🧑‍💻" MAGENTA "  Welcome to the Admin Menu" RESET " 🧑‍💻" MAGENTA "===========" RESET << endl;
    string choices[7] = {GREEN "1. Add a student 🧑‍🎓" RESET,
                         YELLOW "2. Add a professor 🧑‍🏫" RESET,
                         BLUE "3. Add a course 📚" RESET,
                         WHITE "4. Add a term 📅" RESET,
                         CYAN "5. Set a course to a professor 📝" RESET,
                         GREEN "6. Back to Last Page 🔙" RESET,
                         RED "7. Exit 🚪" RESET};
    string choice;

    while (true)
    {
        CLEAR_SCREEN();
        cout << MAGENTA "What would you like to do?" RESET << endl;
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

    cout << GREEN "Enter your ID: " RESET;
    cin >> id;
    cout << BLUE;
    password = getpass("Enter your password: ");
    cout << RESET;

    for (int i = 0; i < gAdminId; i++)
    {
        if (gAdmins.at(i).getId() == id)
        {
            if (verifyArgon2Hash(password, gAdmins.at(i).getPassword(), gAdmins.at(i).getSalt()))
            {
                cout << GREEN "Login successful ✅" RESET << endl;
                return true;
            }
            else
                cout << RED "Wrong password ❌" RESET << endl;
        }
    }
    cout << RED "Login Failed!" RESET << endl;
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

    cout << BLUE "Enter student's name: " RESET;
    cin >> name;

    password = _getPaasword();

    Student s(name, getArgon2Hash(password, salt), salt, id, 0);
    gStudents.push_back(s);
    cout << GREEN "Student added successfully ✅" RESET << endl;
}

void addProfessor()
{
    CLEAR_SCREEN();
    string name;
    string password;
    uint8_t *salt = new uint8_t[32];

    salt = randomString(32);
    int id = _getNewProfessorId();

    cout << BLUE "Enter professor's name: " RESET;
    EMPTY_BUFFER();

    getline(cin, name);

    password = _getPaasword();

    Professor prof(name, getArgon2Hash(password, salt), salt, id, 0);

    gProfessors.push_back(prof);

    cout << GREEN "Professor added successfully ✅" RESET << endl;
}

void addCourse()
{
    CLEAR_SCREEN();
    string name;

    cout << BLUE "Enter course's name: " RESET;
    cin >> name;

    int code = _getNewCourseCode();

    char *pSyllabus = new char[MAX_SYLLABUS_SIZE];

    cout << GREEN "Enter course's syllabus: " RESET;
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

    cout << YELLOW "Enter course's start date: " RESET;
    cin >> *pStartDate;

    cout << YELLOW "Enter course's end date: " RESET;
    cin >> *pEndDate;

    cout << YELLOW "Enter course's mid term date: " RESET;
    cin >> *pMidTermDate;

    cout << YELLOW "Enter course's final exam date: " RESET;
    cin >> *pFinalExamDate;

    vector<Exam> exams;
    int examNum = 0;

    // Professor *pProfessor = new Professor();
    cout << BLUE "This course is for which professor? (Enter professor's ID):" RESET << endl;
    int id;
    cin >> id;

    cout << BLUE "This course is avaliable for which term? " RESET << endl;
    int termCode;
    cin >> termCode;

    Course course(name, code, pSyllabus, pStartDate, pEndDate,
                  pMidTermDate, pFinalExamDate, exams, examNum, &gProfessors.at(id));
    gCourses.push_back(course);

    gProfessors.at(id).setCourse(course);
    gProfessors.at(id).setCourseNums(gProfessors.at(id).getCourseNums() + 1);
}

void setCourseToProfessor()
{
    CLEAR_SCREEN();
    printAllCourses();
    cout << BLUE "Which professor do you want to set course for? (Enter professor's ID):" RESET << endl;
    int id;
    cin >> id;

    cout << BLUE "Which course do you want to set for this professor? (Enter course's code):" RESET << endl;
    int code;
    cin >> code;

    gProfessors.at(id).setCourse(gCourses.at(code));
    cout << GREEN "Course set successfully ✅" RESET << endl;
}

void printAllCourses()
{
    CLEAR_SCREEN();
    cout << MAGENTA "All courses: " RESET << endl;
    for (int i = 0; i < gCourses.size(); i++)
    {
        cout << i << ". " << gCourses.at(i).getCourseName() << endl;
        cout << BLUE "Course Code: " RESET << gCourses.at(i).getCourseCode() << endl;
        cout << BLUE "Course Name: " RESET << gCourses.at(i).getCourseName() << endl;
        cout << BLUE "Course Professor: " RESET << gCourses.at(i).getProfessor()->getName() << endl;
        cout << BLUE "Exam numbers: " RESET << gCourses.at(i).getExamNums() << endl;
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
    cout << BLUE "Enter term's name: " RESET;
    getline(cin, name);

    Date *pStartDate = new Date();
    Date *pEndDate = new Date();
    Date *pGradesDeadLine = new Date();

    cout << BLUE "Enter term's start date: " RESET;
    cin >> *pStartDate;

    cout << BLUE "Enter term's end date: " RESET;
    cin >> *pEndDate;

    cout << BLUE "Enter term's grades deadline: " RESET;
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

    cout << GREEN "Term added successfully ✅" RESET << endl;

    return term;
}

#endif