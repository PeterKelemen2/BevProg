#include "../std_lib_facilities.h"

template<typename t>
    class s {
    private:
        t val;

    public:
        s(t x) {val = x;};
        t get () const;
        t& get();

        void print(){
            cout << val << endl;
                    }
        void operator=(const t& stemp){
            val = stemp;
                        }
        };

void print_vector(ostream& os, vector<int> v){
	cout << "Vector content: ";
	for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i];
		if(i < v.size()-1) cout << ", ";
	}
	cout << endl;
}

template<typename t>
    t s<t>::get()const {return val;};

template<typename t>
    t& s<t>::get(){return val;};

template<typename t>
    ostream& operator<<(ostream& os, s<t>& stemp){return os<<stemp.get();};

template<typename t>
    istream& operator>>(istream& is, s<t>& stemp){return is>>stemp.get();};

int main()
{

	s<int>sint(66);
		sint.print();
	s<char>schar('c');
		schar.print();
	s<double>sdouble(6.6);
		sdouble.print();
	s<vector<int>>svector({1,2,4,8,16});
        print_vector(cout, svector.get());
	cout << endl;

	cout << sint.get() << endl;
	cout << schar.get() << endl;
	cout << sdouble.get() << endl;
	print_vector(cout, svector.get());
	cout << endl;

	cout << "Type an input for: " << endl;
	cout << "Int: "; cin >> sint;
	cout << "Char: "; cin >> schar;
	cout << "Double: "; cin >> sdouble;
	cout << "=======================" << endl;
	cout << sint << endl;
	cout << schar << endl;
	cout << sdouble << endl;

	return 0;
}
