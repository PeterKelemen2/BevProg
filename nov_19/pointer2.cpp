#include "../std_lib_facilities.h"

int main(){

	double* a = new double;
	double* b = new double(4);

	cout << "a: " << *a << endl;
	cout << "b: " << *b << endl;
	
	double* c = new double[4];
	for (int i=0; i<4; i++)
		cout << c[i] << " ";
	cout << endl;
	
	int* d = new int(4);
	cout << d[2] << endl;
	cout << d[10] << endl;
	
	double* e = new double[4] {1.1, 2.2, 3.3, 4.0};
	for (int i=0; i<4; i++)
		cout << e[i] << " ";
	cout << endl;
	
	double* p0 = nullptr;
	if(p0 == nullptr) cout << "p0 is nullptr." << endl;
		else cout << "Impossible!" << endl;
	
	delete a;
	delete b;
	delete[] c;
	delete[] d;
	delete[] e;
	
	return 0;
}
