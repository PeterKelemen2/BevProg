#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <conio.h>
#include <ctime>
#include <fstream>

using namespace std;

// Declaration of variables:
bool play = true;
char p_area[10][10]; // 0-9 indexing
int i,j;
int ci=1,cj=1; // Previous position of ring
int ii=1, jj=1; // Initializing generated pos
int movint;
int mi=rand() % 8+1, mj=rand() % 8+1;
int score;
int pi=rand() % 8+1, pj=rand() % 8+1;
int prev_pi=pi, prev_pj=pj;
int highscore_int;
string mov;

// Declaration of functions:
void UI_settings();
void play_area();
void pr_play_area();
void moving();
void moving_rand();
void init();
void check_up();
void check_down();
void check_left();
void check_right();
void spawn();

void UI_settings(){
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

    MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 300, 520, TRUE);
    }

void init(){ // Whitespace everywhere
    for(int i=0; i<10; i++)
        for(int j=0; j<10; j++)
            p_area[i][j] = ' ';
}

void play_area(){   // Makes boundaries

    for(int i=0; i<10; i++)
        for(int j=0; j<10; j++){
            if(i == 0 ||
               j == 0 ||
               i == 9 ||
               j == 9 ) p_area[i][j] = '#';
        }
    // pr_play_area();
}

void pr_play_area(){ // Prints play area
    if(movint != 5){
        for(int i=0; i<10; i++){
            cout << endl << "  ";
        for(int j=0; j<10; j++)
            cout << p_area[i][j] <<" ";
    }
    cout << endl;

    p_area[mi][mj] = 'O';
    }
    else play = false;
}

void moving_rand(){ // Places ring randomly
    ii = rand() % 8+1, jj = rand() % 8+1;
        p_area[ci][cj] = ' ';

        while(p_area[ii][jj] !=' '){
            ii = rand() % 8+1;
            jj = rand() % 8+1;
        }
        p_area[ii][jj] = 'O';

        ci = ii;
        cj = jj;

        Sleep(150);
}

void moving(){
   system("CLS");
   pr_play_area();
    if(play == true){
    { // Data output
    cout << endl;
    cout << "X_pos: " << mi;
    cout << endl;
    cout << "Y_pos: " << mj;
    cout << endl;
    cout << "Point X_pos: " << pi;
    cout << endl;
    cout << "Point Y_pos: " << pj;
    cout << endl << endl;
    cout << "Score:" << score;
    cout << endl;
    }

   cout << endl << "WASD to move the ring";
   mov = getch(); // Presses enter for you apparently

   if(mov[0] == 'w' || mov[0] == 'W') movint = 1;
    else
   if(mov[0] == 'a' || mov[0] == 'A') movint = 2;
    else
   if(mov[0] == 's' || mov[0] == 'S') movint = 3;
    else
   if(mov[0] == 'd' || mov[0] == 'D') movint = 4;
    else
   if(mov[0] == 'q' || mov[0] == 'Q') movint = 5;

    switch(movint){
    case 1: // W
        p_area[mi][mj] = ' ';
            check_up(); // What actually moves the ring
        p_area[mi][mj] = 'O';
        mov=' ';
        break;

    case 2: // A
        p_area[mi][mj] = ' ';
            check_left();
        p_area[mi][mj] = 'O';
        mov=' ';
        break;

    case 3: // S
        p_area[mi][mj] = ' ';
            check_down();
        p_area[mi][mj] = 'O';
        mov=' ';
        break;

    case 4: // D
        p_area[mi][mj] = ' ';
            check_right();
        p_area[mi][mj] = 'O';
        mov=' ';
        break;
    case 5: // Exit
        play = false;
        break;
    }
    if(mi==pi && mj==pj){
        score++;
        PlaySound("pop.wav", NULL, SND_ASYNC);
        p_area[pi][pj]='O';
        spawn();
    }
    moving();
    }
}

void spawn(){
    prev_pi = pi;
    prev_pj = pj;

    pi = rand() % 8+1;
    pj = rand() % 8+1;

        while(pi==prev_pi || pj==prev_pj){ // To prevent the point spawning on the ring
            pi = rand() % 8+1;
            pj = rand() % 8+1;
        }
    p_area[pi][pj]='*';
    // if(pi==2 && pj==4) // 2 4 not showing for some reason
    //    p_area[pi][pj]='*';
}

void check_up(){
    ci = mi;
    ci--;
    if(p_area[ci][mj] != '#')
        mi--;
}

void check_down(){
    ci = mi;
    ci++;
    if(p_area[ci][mj] != '#')
        mi++;
}

void check_left(){
    cj = mj;
    cj--;
    if(p_area[mi][cj] != '#')
        mj--;
}

void check_right(){
    cj = mj;
    cj++;
    if(p_area[mi][cj] != '#')
        mj++;
}

int main()
{
    srand(time(NULL));

    ifstream highscore("highscore.txt");
    highscore >> highscore_int;
    highscore.close();

    UI_settings(); // Setting font and window size
    init(); // Setting up the play area
    p_area[mi][mj] = 'O'; // Printing the ring at the start of the game
    spawn(); // Generating point on the play area
    play_area();

    while(play == true){
        system("CLS");
        //pr_play_area();
        moving();
    }

        if(highscore_int < score){
            highscore_int = score;
            ofstream highscore_new("highscore.txt");
            highscore_new << highscore_int;
            highscore_new.close();
        }

            system("CLS");
        cout << " Thank you for playing! \n";
        cout << " Your score: " << score << endl;
        cout << " Highscore: " << highscore_int;
        getch();

    return 0;
}
