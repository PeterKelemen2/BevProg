#include "std_lib_facilities.h"


int main(){

    double n,m;

    try{
        // string s = "ape"; 
        // boo c = "fool"<s; 
        // if (c) cout << "Success!\n";

        string s = "ape"; 
        bool c = ("fool" > s); 
        if (c) cout << "Success!\n";

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

