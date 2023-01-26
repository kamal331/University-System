/***********************************************************************
 * @file ProfessorLogin.h                                              *
 * @author Mohammad Kamal                                              *
 * @brief This file contains functions to login as a professor,        *
 *        add a new exam, and view the professor's courses and exams.  *
 * @version 0.9                                                        *
 * @date 2023-01-25                                                    *
 * @copyright Copyright (c) 2023                                       *
 *                                                                     *
 ***********************************************************************/

#ifndef __PROFESSORLOGIN_H_
#define __PROFESSORLOGIN_H_
extern int gProfessorId;
extern vector<Professor> gProfessors;
extern vector<Course> gCourses;
// ================= Professor Menu =================
void professorMenu()
{
    int id;
    string password;

    while (true)
    {
        CLEAR_SCREEN();
        cout << BLUE "Enter your ID: " RESET;
        cin >> id;
        cout << BLUE;
        password = getpass("Enter your password: ");
        cout << RESET;
        if (professorLogin(id, password))
            break;
        cout << RED "Try again? (y/n)" RESET << endl;
        string choice;
        cin >> choice;
        if (choice == "n")
            return;
    }

    cout << "=========== 🧑‍🏫  Welcome to the Professor Menu 🧑‍🏫  ===========" << endl;
    string choices[4] = {GREEN "1. View your courses and exams 📚 📝" RESET,
                         BLUE "2. Add a new exam \U0000002b" RESET,
                         YELLOW "3. Back to last page 🔙" RESET,
                         RED "4. Exit 🚪" RESET};
    string choice;
    while (true)
    {
        CLEAR_SCREEN();
        cout << MAGENTA "What would you like to do?" RESET << endl;
        for (string choice : choices)
            cout << choice << endl;
        cin >> choice;

        if (choice == "1")
        {
            gProfessors.at(id).print();
            BACK_TO_LAST_PAGE();
        }
        else if (choice == "2")
        {
            addNewExam(gProfessors.at(id));
            BACK_TO_LAST_PAGE();
        }
        else if (choice == "3")
            break;
        else if (choice == "4")
        {
            cout << "You chose to exit" << endl;
            exit(0);
        }
        else
        {
            cout << RED "Invalid choice" RESET << endl;
        }
    }
}

bool professorLogin(int &id, string &password)
{
    CLEAR_SCREEN();

    for (int i = 0; i < gProfessorId; i++)
    {
        if (gProfessors.at(i).getId() == id)
        {
            if (verifyArgon2Hash(password, gProfessors.at(i).getPassword(), gProfessors.at(i).getSalt()))
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

void addNewExam(Professor &professor)
{
    CLEAR_SCREEN();
    cout << MAGENTA "=========== 📝  Add a new exam 📝  ===========" RESET << endl;
    cout << BLUE "Enter the course code: " RESET;
    int courseCode;
    cin >> courseCode;

    bool isDone = false;

    for (int i = 0; i < professor.getCourseNums(); i++)
    {
        cout << "=========" << endl;
        if (professor.getCourses().at(i).getCourseCode() == courseCode)
        {
            cout << GREEN "Course found ✅" RESET << endl;

            cout << BLUE "Enter the exam name: " RESET;
            string examName;
            cin >> examName;

            cout << BLUE "How many problems do you want to add? " RESET;
            int problemNums;
            cin >> problemNums;

            // Problem *problems = new Problem[problemNums];
            vector<Problem> problems;
            for (int j = 0; j < problemNums; j++)
            {
                cout << YELLOW "======== Problem " << j + 1 << " ========" RESET << endl;
                problems.push_back(getAProblem());
            }

            // Exam *exams = new Exam[professor.getCourses()[i].getExamNums() + 1];
            // for (int j = 0; j < professor.getCourses()[i].getExamNums(); j++)
            // {
            //     exams[j] = professor.getCourses()[i].getExams()[j];
            // }
            // exams[professor.getCourses()[i].getExamNums()] = Exam(examName, _getNewExamCode());
            // professor.getCourses()[i].setExams(exams);

            Exam exam(examName, problems, problemNums);
            professor.getCourses().at(i).setExams(exam);
            gCourses.at(courseCode).setExams(exam);
            gCourses.at(courseCode).setExamNums(gCourses.at(courseCode).getExamNums() + 1);
            professor.getCourses().at(i).setExamNums(professor.getCourses().at(i).getExamNums() + 1);

            isDone = true;
            cout << GREEN "Exam added successfully ✅" RESET << endl;
            return;
        }
    }
    if (!isDone)
        cout << RED "Course not found ❌" RESET << endl;
}

Problem &getAProblem()
{
    string choice;

    while (true)
    {
        CLEAR_SCREEN();
        cout << MAGENTA "Choose a problem type:" RESET << endl;
        cout << GREEN "1. Multiple Choice 1️⃣ 2️⃣ 3️⃣ 4️⃣" RESET << endl;
        cout << BLUE "2. True or False ✅ ❌" RESET << endl;
        cout << YELLOW "3. Fill in the blank ✏" RESET << endl;
        cout << CYAN "4. Long Answer 📄" RESET << endl;
        cin >> choice;
        if (choice == "1")
            return _getMultipleChoice();

        else if (choice == "2")
            return _getTrueFalse();

        else if (choice == "3")
            return _getFillInTheBlank();

        else if (choice == "4")
            return _getLongAnswer();

        else
        {
            cout << RED "Invalid choice" RESET << endl;
        }
    }
}
Problem &_getMultipleChoice()
{
    string question;
    string problemType;
    // string choices[4];
    vector<string> choices;
    string correctChoice;
    string str;

    EMPTY_BUFFER();
    cout << BLUE "Enter the question: " RESET;
    getline(cin, question);

    cout << BLUE "Enter the problem type: " RESET;
    getline(cin, problemType);

    cout << BLUE "Enter the choices: " RESET << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << i + 1 << ". ";
        getline(cin, str);
        choices.push_back(str);
    }

    cout << BLUE "Enter the correct choice: " RESET;
    cin >> correctChoice;
    Problem *p1 = new Problem(problemType, question, correctChoice, choices, true);
    return *p1;
}

Problem &_getTrueFalse()
{
    string question;
    string problemType;
    string correctChoice;
    vector<string> choices;

    EMPTY_BUFFER();
    cout << BLUE "Enter the question: " RESET;
    getline(cin, question);

    cout << BLUE "Enter the problem type: " RESET;
    getline(cin, problemType);

    cout << BLUE "Enter the correct choice: " RESET;
    cin >> correctChoice;
    Problem *p1 = new Problem(problemType, question, correctChoice, choices, false);
    return *p1;
}

Problem &_getFillInTheBlank()
{
    string question;
    string problemType;
    string correctChoice;
    vector<string> choices;

    EMPTY_BUFFER();
    cout << BLUE "Enter the question: " RESET;
    getline(cin, question);

    cout << BLUE "Enter the problem type: " RESET;
    getline(cin, problemType);

    cout << BLUE "Enter the correct choice: " RESET;
    cin >> correctChoice;
    Problem *p1 = new Problem(problemType, question, correctChoice, choices, false);
    return *p1;
}

Problem &_getLongAnswer()
{
    string question;
    string problemType;
    string correctChoice;
    vector<string> choices;

    EMPTY_BUFFER();
    cout << BLUE "Enter the question: " RESET;
    getline(cin, question);

    cout << BLUE "Enter the problem type: " RESET;
    getline(cin, problemType);

    cout << BLUE "Enter the correct choice: " RESET;
    getline(cin, correctChoice);

    Problem *p1 = new Problem(problemType, question, correctChoice, choices, false);
    return *p1;
}

#endif