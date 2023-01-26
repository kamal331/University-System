#include <iostream>
#include <unistd.h>
using namespace std;

#define CLEAR_SCREEN()          \
    cout << "\033[2J\033[1;1H"; \
    cout.flush();

#define LOADING_BAR()                         \
    for (int i = 0; i <= 100; ++i)            \
    {                                         \
        CLEAR_SCREEN();                       \
        cout << "Loading: [";                 \
        for (int j = 0; j < i / 10; ++j)      \
            cout << "██";                     \
        for (int j = 0; j < 10 - i / 10; ++j) \
            cout << "  ";                     \
        cout << "] " << i << "%" << endl;     \
        usleep(30000);                        \
    }                                         \
    CLEAR_SCREEN();

int main()
{
    LOADING_BAR();
    return 0;
}

/*


*/