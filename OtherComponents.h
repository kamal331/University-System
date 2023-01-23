#ifndef __OTHERCOMPONENTS_H_
#define __OTHERCOMPONENTS_H_

// ================= Macros =================
#define CLEAR_SCREEN() cout << "\033[1;1H\033[2J"
#define MAX_STUDENT_NUM 10
#define MAX_PROFESSOR_NUM 10
#define MAX_ADMIN_NUM 10

// ================== Other Functions ==================
void _backToLastPage()
{
    cout << "Press any key to go back to the last page..." << endl;
    string temp;
    cin >> temp;
}

string _getPaasword()
{
    string password;
    string temp;

    while (true)
    {
        CLEAR_SCREEN();
        cout << "Enter the password: ";
        cin >> password;
        if (_isPassStrong(password))
            return password;
        else
        {
            cout << "Press any key to try again..." << endl;
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