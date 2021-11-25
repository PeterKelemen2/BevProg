#include "../std_lib_facilities.h"

void print_vector(ostream& os, vector<double> a){
    for(int i=0; i<a.size(); i++)
        cout << a[i] << " ";
    cout << endl;
}

void print_array(ostream& os, int* a, int n){
        for(int i=0; i<n; i++)
            cout << a[i] << " ";
        cout << endl;
}

void print_array10(ostream& os, int* a){
    for(int i=0; i<10; i++)
        cout << a[i] << " ";
    cout << endl;
}

void first_part(){

    int* a = new int[10];
    for(int i=0; i<10; i++)
        cout << a[i] << " ";
    cout << endl;

    print_array10(cout, a);
    delete a;

    int* ten = new int[10]{100,101,102,103,104,105,106,107,108,109};
    print_array(cout, ten, 10);
    delete ten;

    int* eleven = new int[11]{100,101,102,103,104,105,106,107,108,109,110};
    print_array(cout, eleven, 11);
    delete eleven;

    int* twenty = new int[20]{100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119};
    print_array(cout, twenty, 20);
    delete twenty;


        vector<double> ten_v;
    for(int i=0; i<10; i++)
        ten_v.push_back(100+i);
    print_vector(cout, ten_v);

        vector<double> eleven_v;
    for(int i=0; i<11; i++)
        eleven_v.push_back(100+i);
    print_vector(cout, eleven_v);

        vector<double> twenty_v;
    for(int i=0; i<20; i++)
        twenty_v.push_back(100+i);
    print_vector(cout, twenty_v);
}

void second_part(){
    int* x = new int;
    *x = 7;
    int* p1 = x;
    cout << " p1 erteke: "<< *p1 << endl
         << " p1 memoria helye: " << p1 << endl;

    int* a = new int[7]{1,2,4,8,16,32,64};
    int* p2 = a;

    cout << " p2 altal hordozott array: ";
    print_array(cout, p2,7);
    cout << " Maga az array: ";
    print_array(cout, a, 7);

    int* p3 = p2;
    *p1 = *p2;
    *p3 = *p2;
    cout << " p1 erteke: "<< *p1 << endl
         << " p1 memoria helye: " << p1 << endl;
    cout << " p2 erteke: "<< *p2 << endl
         << " p2 memoria helye: " << p2 << endl;

    delete a;

    int* b = new int[10]{1,2,4,8,16,32,64,128,256,512};
    p1 = b;
    int* c = new int[10];
    p2 = c;
        for(int i=0; i<10; i++)
            p2[i] = p1[i];
    cout << " p2 altal hordozott array: ";
    print_array(cout, p2, 10);

    delete b;
    delete c;

    vector<double> bb(10);
        bb[0] = 1;
        for(int i=1; i<10; i++)
            bb.push_back(2*bb[i-1]);
    vector<double> cc;

    //p1 = bb; Nem működik vektorral
    //p2 = cc;
}

int main()
{
    int x=1;
    cout << "Which part of the drill would you like to see?\n"
    << "For First Part press 1\n"
    << "For Second Part press 2\n"
    << "Type your choice: ";
    cin >> x;
    system("CLS");
    if(x<1 || x>2){
        cout << "!!! Invalid input !!!";
        return 2;
    }

    switch(x){
    case 1:
        first_part();
        break;
    case 2:
        second_part();
        break;
        }
    return 0;
}
