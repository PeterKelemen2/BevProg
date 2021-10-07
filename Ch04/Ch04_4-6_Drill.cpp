#include "std_lib_facilities.h"
#include <float.h>

int main(){

	double x;
 	double l=DBL_MIN,s=DBL_MAX;

 	//cout << l << " " << s << endl;

	while (cin >> x){
		if(x > l) {
			l = x;
			cout << "The largest number so far: " << l << endl;	
		}
			else if(x < s) {
				s = x;
				cout << "The smallest number so far: " << s << endl;
			}
}

	return 0;
}

