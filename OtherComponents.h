#ifndef __OTHERCOMPONENTS_H_
#define __OTHERCOMPONENTS_H_

// ================= Macros =================
#define CLEAR_SCREEN() cout << "\033[1;1H\033[2J"
#define BACK_TO_LAST_PAGE()                                                \
    cout << MAGENTA "Press any key to back to last page..." RESET << endl; \
    string temp;                                                           \
    cin >> temp;

#define EMPTY_BUFFER() std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n')

#define MAX_STUDENT_NUM 10
#define MAX_PROFESSOR_NUM 10
#define MAX_ADMIN_NUM 10
#define MAX_COURSE_NUM 10
#define MAX_TERM_NUM 8

#define MAX_EXAM_NUM 10
#define MAX_ANSWER_SIZE 50

// ================== Other Functions ==================

void dailyMessage()
{
    CLEAR_SCREEN();
    cout << MAGENTA "\t\t==================== 📝  Daily Message 📝  ====================" RESET << endl;
    cout << CYAN "Human beings are members of a whole, in creation of one essence and soul." << endl;
    cout << "If one member is afflicted with pain, other members uneasy will remain." << endl;
    cout << "If you've no sympathy for human pain, the name of human you cannot retain." RESET << endl
         << endl;

    BACK_TO_LAST_PAGE();
}

void licensePage()
{
    CLEAR_SCREEN();
    cout << MAGENTA "================= 📝  License 📝  =================" << RESET << endl;
    cout << CYAN "This program is licensed under:" << endl;
    cout << "▶ CC0 1.0 Universal(CC0 1.0) Public Domain Dedication ◀" << endl;
    cout << "You may find a copy of the license at:" << endl;
    cout << "https://creativecommons.org/publicdomain/zero/1.0/" RESET << endl
         << endl;

    BACK_TO_LAST_PAGE();
}

void privacyPolicy()
{
    CLEAR_SCREEN();
    cout << MAGENTA "\t\t\t======== 🧌  Privacy Policy 🧌  ========" RESET << endl;
    cout << GREEN "▶ For Professor:" << endl;
    cout << "We keep your Name, ID, Hashed Password, Courses, Exams, and Problems." RESET << endl
         << endl;
    cout << YELLOW "▶ For Student:" << endl;
    cout << "We keep your Name, ID, Hashed Password, Courses, and Exams." RESET << endl
         << endl;
    cout << BLUE "▶ For Admin:" << endl;
    cout << "We keep your Name, ID and Hashed Password" RESET << endl
         << endl;
    cout << GREEN "▶ No other information is kept." RESET << endl
         << endl;

    cout << CYAN "▶ Hashed Password is a way to store password securely." << endl;
    cout << "We use Argon2 hashing algorithm which is"
            "the winner of the"
         << endl
         << "Password Hashing Competition. (PHC 2015) ✅" RESET
         << endl
         << endl;
    BACK_TO_LAST_PAGE();
}

void aboutUs()
{
    string universityName = "University of Science and Technology of Tehran";
    string email = "Example@uni.ac.ir";
    string phoneNumber = "076-12345678";

    CLEAR_SCREEN();
    cout << MAGENTA "\t\t\t=========== 📝  About Us 📝  ===========" RESET << endl;
    cout << GREEN "This is " << universityName << "." RESET << endl;
    cout << YELLOW "Email: " RESET << email << endl;
    cout << BLUE "Phone Number: " RESET << phoneNumber << endl;

    cout << GREEN "You can contact us for any help." RESET " 🙂" << endl
         << endl;

    BACK_TO_LAST_PAGE();
}

string _getPaasword()
{
    CLEAR_SCREEN();
    string password;
    string temp;

    while (true)
    {
        cout << "🫣🫣🫣" << endl;
        cout << MAGENTA;
        password = getpass("Enter the password: ");
        cout << RESET;
        if (_isPassStrong(password))
            return password;
        else
        {
            cout << "❌  ";

            cout << RED;
            cout << "Press any key to try again..." << endl;
            cout << RESET;
            cin >> temp;
        }
    }
}

bool _isPassStrong(string password)
{
    if (password.length() < 12)
    {
        cout << "❌  ";
        cout << RED;
        cout << "Password must be at least 12 characters long" RESET << endl;
        return false;
    }
    else if (password.find_first_of("0123456789") == string::npos)
    {
        cout << "❌  ";
        cout << RED;
        cout << "Password must contain at least one number" RESET << endl;
        return false;
    }
    else if (password.find_first_of("ABCDEFGHIJKLMNOPQRSTUVWXYZ") == string::npos)
    {
        cout << "❌  ";
        cout << RED;
        cout << "Password must contain at least one uppercase letter" RESET << endl;
        return false;
    }
    else if (password.find_first_of("abcdefghijklmnopqrstuvwxyz") == string::npos)
    {
        cout << "❌  ";
        cout << RED;
        cout << "Password must contain at least one lowercase letter" RESET << endl;
        return false;
    }
    else if (password.find_first_of("!@#$%^&*()_+-=") == string::npos)
    {
        cout << "❌  ";
        cout << RED;
        cout << "Password must contain at least one special character" RESET << endl;
        return false;
    }
    else
        return true;
}

#endif