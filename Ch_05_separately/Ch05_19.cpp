#include "std_lib_facilities.h"


int main(){

    double n,m;

    try{
        //vector v(5); 
        //for (int i=0; i<=v.size(); ++i); 
        //cout << "Success!\n";
        
        vector<int> v(1); 
        for (int i = 0; i < v.size(); i++); 
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

