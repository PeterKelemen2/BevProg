#include "std_lib_facilities.h"

int main(){

	int x,y;

	while (cin >> x && cin >> y){
	if(x == '|' || y == '|') return 0;
		else if (x < y){
						cout << "The smaller value is: " << x << endl;
						cout << "The larger value is: " << y << endl; 
						}
					else if (x > y){
						 cout << "The smaller value is: " << y << endl;
						 cout << "The smaller value is: " << x << endl;
						} else if (x==y) cout << "The numbers are equal." << endl;

}

	return 0;
}

