#include "std_lib_facilities.h"


int main(){

    double n,m;

    try{
        //int x = 4; 
        //double d = 5/(x-2); 
        //if (d=2*x+0.5) 
        //    cout << "Success!\n";

        int x = 4; 
        double d = 5/(x-2); 
        if (d != 2*x+0.5) 
            cout << "Success!\n";
        }
        catch (exception& e){
            cerr << "Error:" << e.what() << '\n';
            return 1;
        }
        catch(...){
            cerr << "Oops: unknown exception\n";
            return 2;
        }
    return 0;
}

