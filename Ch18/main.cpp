#include "../std_lib_facilities.h"

    //Declared data needed for drill
    int ga[10]={1,2,4,8,16,32,64,128,512,1024};
    vector<int> gv{1,2,4,8,16,32,64,128,512,1024};

// Declared Drill parts
void f_a(int a[],int i);
void f_v(vector<int> x);

// Declared functions:
void drill_array();
void drill_vector();
void wait_input();
void option_list();
void switch_repeat();
void end_text();


// Variable for switch
int drill;

void end_text(){ // Text after Drill part for info
    cout << "\n=========================================\n\n";

    cout << "Drill part executed succesfully!\n\n";

    cout << "Type (1) to load Array part\n";
    cout << "Type (2) to load Vector part\n";
    cout << "Type (3) to return to Main window\n";
    cout << "Type (q) to Quit\n";
    cout << "Type your option: ";

}

void option_list(){ // The greeting text and list of options
    cout << "Content of Drill: \n";
    cout << "(1) Array part\n";
    cout << "(2) Vector part\n";
    cout << "(q) Quit program\n";
    cout << "Which part of the drill would you like to see?\n";
    cout << "Type option: ";
}

void switch_repeat(){ // Recursive if needed switch
        switch(drill){
    case 1:
        drill_array();
        break;
    case 2:
        drill_vector();
        break;
    case 3:
        system("CLS");
        option_list();
        cin >> drill;
        switch_repeat();
        break;
    }
}

void drill_array(){ // Aray part of the Drill
    system("CLS");
    cout << "Array part loaded!\n";
    cout << "\n=========================================\n\n";

    f_a(ga,10);

    int aa[10]={1, 1*2, 1*2*3, 1*2*3*4, 1*2*3*4*5
        , 1*2*3*4*5*6, 1*2*3*4*5*6*7, 1*2*3*4*5*6*7*8
        , 1*2*3*4*5*6*7*8*9, 1*2*3*4*5*6*7*8*9*10};

    f_a(aa,10);

    end_text();
    cin >> drill;
    switch_repeat();
}

void drill_vector(){ // Vector part of the Drill
    system("CLS");
    cout << "Vector part loaded!\n";
    cout << "\n=========================================\n\n";

    f_v(gv);

    vector<int> vv{1, 1*2, 1*2*3, 1*2*3*4, 1*2*3*4*5
        , 1*2*3*4*5*6, 1*2*3*4*5*6*7, 1*2*3*4*5*6*7*8
        , 1*2*3*4*5*6*7*8*9, 1*2*3*4*5*6*7*8*9*10
        };


    f_v(vv);

    end_text();
    cin >> drill;
    switch_repeat();
}

void f_a(int a[], int i){

    int la[10];

    for(int j=0; j<i; j++)
        la[j]=ga[j];

    for(int j=0; j<i; j++)
        cout << la[j] << " ";
    cout << endl;

    int* pa = new int [i];

    for(int j=0; j<i; j++)
        pa[j]=la[j];
    for(int j=0; j<i; j++)
        cout << pa[j] << " ";
    cout << endl;

    delete pa;

}

void f_v(vector<int> x){
    vector<int> lv(10);

    for(int i=0; i<gv.size(); i++)
        lv[i] = gv[i];
    for(int i=0; i<lv.size(); i++)
        cout << lv[i] << " ";
    cout << endl;

    vector<int> lv2 = x;

    for(int i=0; i<lv2.size(); i++)
        cout << lv2[i] << " ";
    cout << endl;
}

int main()
{


    option_list();
    cin >> drill;

    while(drill < 0 || drill > 2){ // Recursive input check
            system("CLS");
        cout << "Wrong option!! \n\n";
        option_list();
        cin >> drill;
    }

    switch(drill){ // First to run switch
    case 1:
        drill_array();
        break;
    case 2:
        drill_vector();
        break;
    case 3:
        system("CLS");
        option_list();
        cin >> drill;
        switch_repeat();
        break;
    }

    return 0;
}
