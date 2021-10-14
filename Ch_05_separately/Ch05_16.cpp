#include "std_lib_facilities.h"


int main(){

    double n,m;

    try{
        if (true) cout << "Success!\n"; 
            else cout << "Fail!\n";
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

