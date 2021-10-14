#include "std_lib_facilities.h"


int main(){

    double n,m;

    try{
        //int x = 2000; 
        //char c = x; 
        //if (c==2000) 
        //    cout << "Success!\n";

        int x = 2000; 
        string c;
            c = x;
            cout << c;    
        //if (c == 2000) 
         //   cout << "Success!\n";
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

