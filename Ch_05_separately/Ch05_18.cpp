#include "std_lib_facilities.h"


int main(){

    double n,m;

    try{
        //string s = "Success!\n"; 
        //for (int i=0; i<10; ++i) 
        //    cout << s[i];

        string s = "Success!"; 
        for (int i=0; i<10; ++i) 
            cout << s[i];
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

