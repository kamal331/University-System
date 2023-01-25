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
        cout << "Enter your ID: ";
        cin >> id;
        password = getpass("Enter your password: ");
        if (professorLogin(id, password))
            break;
        cout << "Try again? (y/n)" << endl;
        string choice;
        cin >> choice;
        if (choice == "n")
            return;
    }

    cout << "=========== 🧑‍🏫  Welcome to the Professor Menu 🧑‍🏫  ===========" << endl;
    string choices[4] = {"1. View your courses and exams 📚 📝",
                         "2. Add a new exam \U0000002b",
                         "3. Back to last page 🔙",
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
            cout << "Invalid choice" << endl;
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

void addNewExam(Professor &professor)
{
    CLEAR_SCREEN();
    cout << "=========== 📝  Add a new exam 📝  ===========" << endl;
    cout << "Enter the course code: ";
    int courseCode;
    cin >> courseCode;

    bool isDone = false;

    for (int i = 0; i < professor.getCourseNums(); i++)
    {
        cout << "=========" << endl;
        if (professor.getCourses().at(i).getCourseCode() == courseCode)
        {
            cout << "Course found ✅" << endl;

            cout << "Enter the exam name: ";
            string examName;
            cin >> examName;

            cout << "How many problems do you want to add? ";
            int problemNums;
            cin >> problemNums;

            // Problem *problems = new Problem[problemNums];
            vector<Problem> problems;
            for (int j = 0; j < problemNums; j++)
            {
                cout << "======== Problem " << j + 1 << " ========" << endl;
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

            isDone = true;
            cout << "Exam added successfully ✅" << endl;
            return;
        }
    }
    if (!isDone)
        cout << "Course not found ❌" << endl;
}

Problem getAProblem()
{
    string choice;

    while (true)
    {
        CLEAR_SCREEN();
        cout << "Choose a problem type:" << endl;
        cout << "1. Multiple Choice 1️⃣ 2️⃣ 3️⃣ 4️⃣" << endl;
        cout << "2. True or False ✅ ❌" << endl;
        cout << "3. Fill in the blank ✏" << endl;
        cout << "4. Long Answer 📄" << endl;
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
            cout << "Invalid choice" << endl;
        }
    }
}
Problem _getMultipleChoice()
{
    string question;
    string problemType;
    string choices[4];
    string correctChoice;

    EMPTY_BUFFER();
    cout << "Enter the question: ";
    getline(cin, question);

    cout << "Enter the problem type: ";
    getline(cin, problemType);

    cout << "Enter the choices: " << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << i + 1 << ". ";
        getline(cin, choices[i]);
    }

    cout << "Enter the correct choice: ";
    cin >> correctChoice;
    return Problem(problemType, question, correctChoice, choices, true);
}

Problem _getTrueFalse()
{
    string question;
    string problemType;
    string correctChoice;

    EMPTY_BUFFER();
    cout << "Enter the question: ";
    getline(cin, question);

    cout << "Enter the problem type: ";
    getline(cin, problemType);

    cout << "Enter the correct choice: ";
    cin >> correctChoice;
    return Problem(problemType, question, correctChoice, nullptr, false);
}

Problem _getFillInTheBlank()
{
    string question;
    string problemType;
    string correctChoice;

    EMPTY_BUFFER();
    cout << "Enter the question: ";
    getline(cin, question);

    cout << "Enter the problem type: ";
    getline(cin, problemType);

    cout << "Enter the correct choice: ";
    cin >> correctChoice;
    return Problem(problemType, question, correctChoice, nullptr, false);
}

Problem _getLongAnswer()
{
    string question;
    string problemType;
    string correctChoice;

    EMPTY_BUFFER();
    cout << "Enter the question: ";
    getline(cin, question);

    cout << "Enter the problem type: ";
    getline(cin, problemType);

    cout << "Enter the correct choice: ";
    getline(cin, correctChoice);

    return Problem(problemType, question, correctChoice, nullptr, false);
}

#endif