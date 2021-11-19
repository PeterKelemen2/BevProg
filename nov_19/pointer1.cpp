#include "../std_lib_facilities.h"

int main(){

	int var = 17;
	int *prt = &var;
	cout << "var: " << var << endl;
	cout << "*prt: "<< *prt << endl;

	int x = 17;
	int* pi = &x;
	cout << "x: "<< x << endl;
	cout << "*pi: "<< *pi << endl;
	 
	double e = 2.71828;
	double* pd = &e;
	cout << "e: " << e << endl;
	cout << "*pd: " << *pd << endl;
	
	*pi = 28;
	*pd = 3.14;	
	cout << "*pi: " << *pi << endl;
	cout << "*pd: " << *pd << endl;
	
	*pd = *pi;
	cout << "*pi: " << *pi << endl;
	cout << "*pd: " << *pd << endl;
	
	
	
	return 0;
}
