#ifndef __OTHERCOMPONENTS_H_
#define __OTHERCOMPONENTS_H_

// ================= Macros =================
#define CLEAR_SCREEN() cout << "\033[1;1H\033[2J"
#define BACK_TO_LAST_PAGE()                                  \
    cout << "Press any key to back to last page..." << endl; \
    string temp;                                             \
    cin >> temp;

#define EMPTY_BUFFER() std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n')

#define MAX_STUDENT_NUM 10
#define MAX_PROFESSOR_NUM 10
#define MAX_ADMIN_NUM 10
#define MAX_COURSE_NUM 10
#define MAX_TERM_NUM 8

#define MAX_EXAM_NUM 10

// ================== Other Functions ==================

void dailyMessage()
{
    CLEAR_SCREEN();
    cout << "\t\t==================== 📝  Daily Message 📝  ====================" << endl;
    cout << "Human beings are members of a whole, in creation of one essence and soul." << endl;
    cout << "If one member is afflicted with pain, other members uneasy will remain." << endl;
    cout << "If you've no sympathy for human pain, the name of human you cannot retain." << endl
         << endl;

    BACK_TO_LAST_PAGE();
}

void privacyPolicy()
{
    CLEAR_SCREEN();
    cout << "\t\t\t======== 🧌  Privacy Policy 🧌  ========" << endl;
    cout << "▶ For Professor:" << endl;
    cout << "We keep your Name, ID, Hashed Password, Courses, Exams, and Problems." << endl
         << endl;
    cout << "▶ For Student:" << endl;
    cout << "We keep your Name, ID, Hashed Password, Courses, and Exams." << endl
         << endl;
    cout << "▶ For Admin:" << endl;
    cout << "We keep your Name, ID and Hashed Password" << endl;
    cout << "▶ No other information is kept." << endl
         << endl;

    cout << "▶ Hashed Password is a way to store password securely." << endl;
    cout << "I use Argon2 hashing algorithm which is"
            "the winner of the Password Hashing Competition. ✅"
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
    cout << "\t\t\t=========== 📝  About Us 📝  ===========" << endl;
    cout << "This is " << universityName << "." << endl;
    cout << "Email: " << email << endl;
    cout << "Phone Number: " << phoneNumber << endl;

    cout << "You can contact us for any help. 🙂" << endl
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
        password = getpass("Enter the password: ");
        if (_isPassStrong(password))
            return password;
        else
        {
            cout << "❌  Press any key to try again..." << endl;
            cin >> temp;
        }
    }
}

bool _isPassStrong(string password)
{
    if (password.length() < 12)
    {
        cout << "❌  Password must be at least 12 characters long" << endl;
        return false;
    }
    else if (password.find_first_of("0123456789") == string::npos)
    {
        cout << "❌  Password must contain at least one number" << endl;
        return false;
    }
    else if (password.find_first_of("ABCDEFGHIJKLMNOPQRSTUVWXYZ") == string::npos)
    {
        cout << "❌  Password must contain at least one uppercase letter" << endl;
        return false;
    }
    else if (password.find_first_of("abcdefghijklmnopqrstuvwxyz") == string::npos)
    {
        cout << "❌  Password must contain at least one lowercase letter" << endl;
        return false;
    }
    else if (password.find_first_of("!@#$%^&*()_+-=") == string::npos)
    {
        cout << "❌  Password must contain at least one special character" << endl;
        return false;
    }
    else
        return true;
}

#endif