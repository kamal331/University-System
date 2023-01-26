#ifndef __STUDENTLOGIN_H_
#define __STUDENTLOGIN_H_

void studentMenu()
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
        if (studentLogin(id, password))
            break;
        cout << RED "Try again? (y/n)" RESET << endl;
        string choice;
        cin >> choice;
        if (choice == "n")
            return;
    }

    cout << MAGENTA "=========== 🧑‍🎓  Welcome to the Student Menu 🧑‍🎓  ===========" RESET << endl;
    string choices[4] = {GREEN "1. View Courses and exams 📚" RESET,
                         BLUE "2. signup for a course 📝" RESET,
                         YELLOW "3. Do a Exam 📄" RESET,
                         RED "4. Logout 🚪" RESET};
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
            gStudents.at(id).print();
            BACK_TO_LAST_PAGE();
        }
        else if (choice == "2")
        {
            signUpForACourse(gStudents.at(id));
            BACK_TO_LAST_PAGE();
        }
        else if (choice == "3")
        {
            attendExam(gStudents.at(id));
        }
        else if (choice == "4")
        {
            break;
        }
        else
        {
            cout << RED "Invalid choice" RESET << endl;
        }
    }
}

bool studentLogin(int &id, string &password)
{
    CLEAR_SCREEN();

    for (int i = 0; i < gStudentId; i++)
    {
        if (gStudents.at(i).getId() == id)
        {
            if (verifyArgon2Hash(password, gStudents.at(i).getPassword(), gStudents.at(i).getSalt()))
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

void signUpForACourse(Student &s1)
{
    CLEAR_SCREEN();
    printAllCourses();
    cout << endl
         << MAGENTA "Which course do you want to signup for?" RESET << endl;
    cout << WHITE "=========== 📝  Signup for a course 📝  ===========" RESET << endl;
    cout << BLUE "Enter the course code: " RESET;
    int courseCode;
    cin >> courseCode;
    s1.setCourses(gCourses.at(courseCode));

    cout << GREEN "Signed up the course successfully ✅" RESET << endl;
}

void attendExam(Student &s1)
{
    CLEAR_SCREEN();
    s1.print();

    cout << MAGENTA "=========== 📄  Attend an Exam 📄  ===========" RESET << endl;
    cout << BLUE "Which Course do you want to attend? (Enter the code) " RESET << endl;
    int courseCode;
    cin >> courseCode;

    cout << BLUE "Which exam do you want to attend? (Enter the code) " RESET << endl;
    int examCode;
    cin >> examCode;

    double score = 100.0 / s1.getCourses().at(courseCode).getExams().at(examCode).getProblemNums();
    double totalScore = 0;

    bool isFirstTime = true;

    for (int i = 0; i < s1.getCourses().at(courseCode).getExams().at(examCode).getProblemNums(); i++)
    {
        s1.getCourses().at(courseCode).getExams().at(examCode).getProblems().at(i).printProblem();
        cout << BLUE "Enter your answer: " RESET;
        char *answer = new char[MAX_ANSWER_SIZE];
        if (isFirstTime)
        {
            EMPTY_BUFFER();
            isFirstTime = false;
        }

        cin.getline(answer, MAX_ANSWER_SIZE);
        if (s1.getCourses().at(courseCode).getExams().at(examCode).getProblems().at(i).getProblemAnswer() == answer)
        {
            totalScore += score;
            cout << GREEN "Correct answer ✅" RESET << endl
                 << endl;
        }
        else
        {
            cout << RED "Wrong answer ❌" RESET << endl
                 << endl;
        }
    }
    if (totalScore == 100)
    {
        cout << GREEN "You got 100% ✅" RESET << endl;
        system("vlc goodJob.ogg --run-time 17 --stop-time=17 vlc://quit");
    }
    else
        cout << RED "You got " << totalScore << "% ❌" RESET << endl;

    CLEAR_SCREEN();
    BACK_TO_LAST_PAGE();
}

#endif