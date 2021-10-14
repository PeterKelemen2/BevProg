#include "std_lib_facilities.h"


int main(){

    double n,m;

    try{
        //int i=0; 
        //int j = 9; 
        //    while (i<10) j++; 
        //    if (j<i) cout << "Success!\n";

        int i = 0; 
        int j = 9; 
            while (j<10) j++; 
            if (i < j) cout << "Success!\n";
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

