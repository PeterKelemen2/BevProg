#include "std_lib_facilities.h"

using namespace std;

namespace X{
    int var;
    void print(){
        cout << var << endl;
    }
}

namespace Y{
    int var;
    void print(){
        cout << var << endl;
    }
}

namespace Z{
    int var;
    void print(){
        cout << var << endl;
    }
}

int main(){

    X::var = 7;
    X::print();

    using namespace Y;
    var = 9;
    print();
    {
        using Z::var;
        using Z::print;
        var = 11;
        print();
    }

    char cc;
    cout << "Enter a character to exit" << endl;
    cin >> cc;

    return 0;
};
