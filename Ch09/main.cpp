#include "../std_lib_facilities.h"

using namespace std;

struct Date {

    int year;
    int month;
    int day;

    void add_year(int n);
    void add_month(int n);
    void add_day(int n);

        Date(int y, int m, int d);
};

Date::Date(int y, int m, int d)
{
	if (y > 0) year = y;
        else error("Invalid year!");

    if (m > 0 && m <= 12) month = m;
        else error("Invalid month!");

	if (d > 0 && d <= 31) day = d;
        else error("Invalid day!");
}

void Date::add_year(int n){
    year += n;
};

void Date::add_month(int n){
    month = month + n;
    if (month > 12){
        year++;
        month -=12;
    }
}

void Date::add_day(int n){
    day += n;
    if (day > 31){
        month++;
        day -= 31;
        if (month > 12){
            year++;
            month -= 12;
        }
    }
}


int main()
{
    try{

        Date today{1978, 6, 12};
        cout << "Date: " << today.year << ". " << today.month << ". " << today.day << endl;

        //Tomorrow:
        today.add_day(1);
        cout << "Tomorrow's date: " << today.year << ". " << today.month << ". " << today.day << endl;

        char cc;
        cout << endl << "Enter a char to close this window: ";
        cin >> cc;

        return 0;
    } catch(exception& e){
            cout << e.what() << endl;
            return 1;
        }
}
