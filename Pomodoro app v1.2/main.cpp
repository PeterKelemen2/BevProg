#include <iostream>
#include <windows.h>
#include <MMSystem.h>
#include <cwchar>

using namespace std;

// Declaration of variables
int aux;
int workmin, worksec;
int breakmin, breaksec;
int workmin_o, worksec_o=0;
int breakmin_o, breaksec_o=0;
char* s_w = new char(20);
char* s_b = new char(20);

// Declaration of functions
void work_timer(int workmin_o, int worksec_o);
void break_timer(int breakmin_o, int breaksec_o);
void check();
void check_w();
void check_b();
void i_s_w();
void i_s_w();

// Function for the timer that calls the break timer when finished
void work_timer(int workmin_o, int worksec_o){

            HWND console = GetConsoleWindow();
    RECT ConsoleRect;
    GetWindowRect(console, &ConsoleRect);

    MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 430, 210, TRUE);

    workmin = workmin_o;
    worksec = worksec_o;
    while(workmin > 0 || worksec > 0){
           system("cls");

        cout << "|==================================|"<< endl;
        cout << "|        === Study timer ===       |"<< endl;
        cout << "|==================================|"<<endl;

        if(worksec > 0) worksec--;
            else if (worksec == 0){
                        workmin--;
                        worksec = 59;
                    }

        if (workmin <= 9) cout << "|    " << workmin << " minute(s) ";
            else cout << "|   " << workmin << " minute(s) ";
        if (worksec <= 9) cout << "|  " << worksec << " second(s)    |" << endl;
            else cout << "| "<< worksec << " second(s)    |" << endl;
        cout << "|==================================|" << endl;

        Sleep(1000);
    }
    cout << "             Finished!";
    PlaySound(TEXT("SystemStart"), NULL, SND_ALIAS);
    break_timer(breakmin_o,breaksec_o);

}

// Function of the break timer that calls the work timer when finished
void break_timer(int breakmin_o, int breaksec_o){

        HWND console = GetConsoleWindow();
    RECT ConsoleRect;
    GetWindowRect(console, &ConsoleRect);

    MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 430, 210, TRUE);

    breakmin = breakmin_o;
    breaksec = breaksec_o;
    while(breakmin > 0 || breaksec > 0){
            system("cls");
        cout << "|==================================|"<< endl;
        cout << "|        === Break timer ===       |"<< endl;
        cout << "|==================================|"<<endl;
        if(breaksec > 0) breaksec--;
            else if (breaksec == 0){
                        breakmin--;
                        breaksec = 59;
                    }
        if (breakmin <= 9) cout << "|    " << breakmin << " minute(s) ";
            else cout << "|   " << breakmin << " minute(s) ";
        if (breaksec <= 9) cout << "|  " << breaksec << " second(s)    |" << endl;
            else cout << "| "<< breaksec << " second(s)    |" << endl;
        cout << "|==================================|" << endl;
        Sleep(1000);
    }
    cout << "             Finished!";
    PlaySound(TEXT("SystemStart"), NULL, SND_ALIAS);
    work_timer(workmin_o,worksec_o);

}

void intro1(){
    cout << "|==========================================================|" << endl;
    cout << "|                  == Pomodoro app v1.0 ==                 |" << endl;
    cout << "|==========================================================|" << endl << endl;
}

void i_s_w(){
    for(int i=0; i<strlen(s_w); i++)
        s_w[i]=' ';

    cout << " > For how long would you like the study session to last? " << endl;
    cout << " > Minutes: "; cin >> s_w;
}

void i_s_b(){
    for(int i=0; i<strlen(s_b); i++)
        s_b[i]=' ';

    cout << " > How long would you prefer the break? " << endl;
    cout << " > Minutes: "; cin >> s_b;
}

void check(){
    check_w();
    check_b();
}

void check_w(){
    workmin_o=0;
    system("cls");
        for(int i=0; i<strlen(s_w); i++){
                aux = s_w[i] -48;
            if(aux >=0 && aux <=9)
                workmin_o = workmin_o*10 + aux;
            else {
                system("cls");
                cout << "Invalid parameters given!" << endl;
                i_s_w();
                check_w();

                }
            }
        if(workmin_o > 180 || workmin_o < 5){
            system("cls");
            cout << "Try to be more reasonable..." << endl;
            i_s_w();
            check_w();
        }
}

void check_b(){
    breakmin_o=0;
        for(int i=0; i<strlen(s_b); i++){
            aux = s_b[i] -48;
            if(aux >=0 && aux <=9)
                breakmin_o = breakmin_o*10 + aux;
            else {
                system("cls");
                cout << "Invalid parameters given!" << endl;
                i_s_b();
                check_b();
        }
    }
    if(breakmin_o > 60 || breakmin_o < 1){
        system("cls");
        cout << "Try to be more reasonable..." << endl;
        i_s_b();
        check_b();
    }
}

int main()
{

    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;
    cfi.dwFontSize.X = 0;                   // Width of each character in the font
    cfi.dwFontSize.Y = 24;                  // Height
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_NORMAL;
    std::wcscpy(cfi.FaceName, L"Consolas"); // Choose your font
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);


    HWND console = GetConsoleWindow();
    RECT ConsoleRect;
    GetWindowRect(console, &ConsoleRect);

    MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 697, 350, TRUE);

    //PlaySound(TEXT("SystemStart"), NULL, SND_ALIAS);
    intro1();
    cout << " > For how long would you like the study session to last? " << endl;
    cout << " > Minutes: "; cin >> s_w;
    //cout << " > Seconds: "; cin >> worksec_o;
    cout << endl;
    cout << " > How long would you prefer the break? " << endl;
    cout << " > Minutes: "; cin >> s_b;
    //cout << " > Seconds: "; cin >> breaksec_o;

    check();

    /*system("cls");
    cout << "Study minutes: " << workmin_o << endl;
    cout << "Break minutes: " << breakmin_o << endl;
    */
    work_timer(workmin_o,worksec_o);

    return 0;
}
