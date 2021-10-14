#include "std_lib_facilities.h"


int main(){

    double n,m;

    try{
          // cout << "Success!\n; 
          cout << "Success!\n";    
        return 0;
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