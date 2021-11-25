#include "../std_lib_facilities.h"
#include <iomanip>

//Test_output.cpp
void code();
void some_code();
int a, b, c, d;

void email(){

    int db;
    char first[50], last[50], phnb[50], email[50];
    cout << "How many entries do you want to record? ";
    cin >> db;
    system("CLS");
    vector <string> last_v;
    vector <string> first_v;
    vector <string> phnb_v;
    vector <string> email_v;

        for(int i=1; i<=db; i++){
            cout << "First and last name: ";
            cin >> first >> last;
            first_v.push_back(first);
            last_v.push_back(last);

            cout << "Phone number: ";
            cin >> phnb;
            phnb_v.push_back(phnb);

            cout << "Email address: ";
            cin >> email;
            email_v.push_back(email);
        }

        system("CLS");
        cout << setw(20) <<  "First name"
             << setw(20) << "Last name"
             << setw(20) << "Phone number"
             << setw(35) << "Email address\n"
        <<"----------------------------------------------------------------------------------------------------\n";
            for(int i=0; i<db; i++){
            cout << setw(20) << first_v[i]
                 << setw(20) << last_v[i]
                 << setw(20) << phnb_v[i]
                 << setw(35) << email_v[i] << "\n";

            }

}

void mainprog()
{
    int birth_year = 2001;
    cout << "Conversions:\n";
    cout << dec << birth_year << "\t(decimal)\n";
    cout << hex << birth_year << "\t(hexadecimal)\n";
    cout << oct << birth_year << "\t(octal)\n\n";

    cout << "Now with showing the bases:" << endl;
    cout << showbase << dec << birth_year << "\t(decimal)\n";
    cout << showbase << hex << birth_year << "\t(hexadecimal)\n";
    cout << showbase << oct << birth_year << "\t(octal)\n\n";
    cout << "My birth year (stuck on last conversion):" << '\t' << birth_year << "\n"
    << "My birth year (now back to decimal):" << '\t' << '\t' << dec << birth_year << "\n";

        cout << "\nInput `1234` 4 times and see how it converts :\n";
        code();
        cout << "1234567.89 shown in different forms:\n";
        some_code();
        // fixed form is the most accurate for the user
}
void code(){
    cin >> a >> oct >> b >> hex >> c >> d;
    cout << a << '\t'<< b << '\t'<< c << '\t'<< d << "\n\n" ;
}

void some_code(){
    float x = 1234567.89;
    cout << defaultfloat << x << '\t'
         << fixed << x << '\t'
         << scientific << x << "\t\n\n";
}

int main()
{
    int x;
    cout << "Which part of the drill would you like to see?\n"
         << "For `Conversion part` press 1\n"
         << "For `Table part` press 2\n"
         << "Type your choice: ";
    cin >> x;
    system("CLS");
    if (x<1 || x>2) cerr << "\n!!! Invalid input !!!\n";
    switch(x){
        case 1:
            mainprog();
        break;
        case 2:
            email();
        break;
    }

    return 0;
}
