#include "std_lib_facilities.h"


int main(){

    double n,m;

    try{
          // string res = 7; 
          // vector<int> v(10); 
          // v[5] = res; 
          // cout << "Success!\n";

          string res = "7"; 
          vector<string> v(10); 
          v[5] = res; 
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