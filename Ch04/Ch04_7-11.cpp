#include <iostream>
#include <string.h>
#include <vector>
#include <float.h>
#include <algorithm>

using namespace std;

int main()
{

//1 m == 100 cm
//1 in == 2.54 cm
//1 ft == 12 in

    double min1=DBL_MAX, max1=DBL_MIN;
    vector<double> v;
    int unit, db=0, work=1;
    double x;
    string u="e";

    while ((cin >> x >> u) && (work==1)){
            ;
        if (u == "q") work = 0;
    //cout << x << " " << u << endl;

        if(u == "in") unit = 1; else
        if(u == "ft") unit = 2; else
        if(u == "cm") unit = 3; else
        if(u == "m" ) unit = 4; else
            unit = -1;

        switch (unit){ // atalakitasok
            case 1:
                x = (x*2.54)/100;
                break;
            case 2:
                x = ((x*12)*2.54)/100;
                break;
            case 3:
                x = x/100;
                break;
            case 4:
                x = x;
                break;
            case -1:
                x=0;
                break;
                    }
      if (x!=0) db++;
      if (x < min1 && x!=0) min1 = x;
      if (x > max1) max1 = x;

    if (x!=0){ cout << x << " m - Conversion succesful!" << endl << endl;
              v.push_back(x);
              }
        else cout << "Illegal unit or wrong value" << endl << endl;
    }

       sort(v.begin(), v.end());

    cout << "Min = " << min1 << "; Max = " << max1 << "; Nr. = " << db;
    cout << endl << endl;

    for(int i=0; i < v.size(); i++)
        cout << v[i] << " ";

cout << endl;
    return 0;
}
