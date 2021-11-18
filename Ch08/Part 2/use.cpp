#include "std_lib_facilities.h"

using namespace std;

int a,b;

void swap_v(int,int)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void swap_r(int&,int&)
{
    int temp;
    temp = a, a = b;
    b = temp;
}

void swap_cr(const int&, const int&)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

int main(){

    int x = 7;
    int y = 9;

    // none have been swapped :(

    swap_v(x,y); // output : 7 9
    cout << x << " " << y << endl;

    swap_r(x,y); // output : 7 9
    cout << x << " " << y << endl;

    swap_cr(x,y); // output : 7 9
    cout << x << " " << y << endl;



    // none have been swaped either :(

    swap_v(7,9); // output : 7 9
    cout << x << " " << y << endl;

    //swap_r(7,9); // error: cannot bind non-const lvalue reference of type 'int&' to an rvalue of type 'int'
    //cout << x << " " << y << endl;

    swap_cr(7,9); // output : 7 9
    cout << x << " " << y << endl;

//-------------------------------------

    const int cx = 7;
    const int cy = 9;

    swap_v(cx,cy); // output : 7 9
    cout << cx << " " << cy << endl;

    //swap_r(cx,cy); // error: binding reference of type 'int&' to 'const int' discards qualifiers|
    //cout << cx << " " << cy << endl;

    swap_cr(cx,cy); // output : 7 9
    cout << cx << " " << cy << endl;

    swap_v(7,9); // output : 7 9
    cout << cx << " " << cy << endl;

    //swap_r(7,9); // error
    cout << cx << " " << cy << endl;

    swap_cr(7,9); // output : 7 9
    cout << cx << " " << cy << endl;

//-------------------------------------

    double dx = 7.7;
    double dy = 9.9;

    swap_v(dx,dx); // output: 7.7 9.9
    cout << dx << " " << dy << endl;

    //swap_r(dx,dx); //error: cannot bind non-const lvalue reference of type 'int&' to an rvalue of type 'int'
    //cout << dx << " " << dy << endl;

    swap_cr(dx,dx); // output 7.7 9.9
    cout << dx << " " << dy << endl;

    swap_v(7.7,9.9); // output 7.7 9.9
    cout << dx << " " << dy << endl;

    //swap_r(7.7,9.9); // error
    //cout << dx << " " << dy << endl;

    swap_cr(7.7,9.9); // output 7.7 9.9
    cout << dx << " " << dy << endl;

    return 0;
};
