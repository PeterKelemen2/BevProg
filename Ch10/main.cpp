#include "../std_lib_facilities.h"

vector<double> original_points;

vector<double> x;
vector<double> y;


int main()
{
    double aux1, aux2, x1, y1;
    cout << " How many points do you want to record? ";
    cin >> aux1;
    if (aux1 < 1){
        cout << endl << " !! Error: Invalid number of points !!" << endl;
        return 0;
    }
    aux2 = aux1;

    while (aux1 > 0){  // reading point values
        cout << aux2-aux1+1 << ". items:" << endl;
        cout << " ";
        cin >> x1;
        cout << " ";
        cin >> y1;

        original_points.push_back(x1);
        original_points.push_back(y1);

        aux1 --;
        cout << endl;
    }

    ofstream f("mydata.txt");
        int temp=0, op_count=0;
        double value;

    for(int i=0; i<original_points.size(); i +=2){
        f << original_points[i] << " ";
            op_count++;
        f << original_points[i+1] << endl;
            op_count++;
            temp++;
        }
    cout << " " << temp << " pair of items transfered." << endl;
    f.close();

// Debug -----------------------------------
    double aux3;
    cout << endl << " Content of 'mydata.txt:' ";
    ifstream debug("mydata.txt");
    while(debug >> aux3)
        cout << aux3 << " ";
    cout << endl;
    debug.close();
//-------------------------------------------

    vector<double> processed_points;

    ifstream g("mydata.txt");
        while (g >> value){
            processed_points.push_back(value);
            g >> value;
            processed_points.push_back(value);
        }
// Check ------------------------------------
        if (processed_points.size() != original_points.size()){
            cout << " !! Error: Number of items don't match !!" << endl;
            return 0;
        }

    for (int i=0; i < original_points.size(); i++)
        if(original_points[i] != processed_points[i]){
            cout << " !! Error: Vectors content don't match !!" << endl;
            return 0;
        }

        cout << endl << " Original points:" << endl << " ";
    for (int i=0; i < original_points.size(); i++)
        cout << original_points[i] << " ";

        cout << endl << endl << " Processed points:" << endl << " ";
    for (int i=0; i < processed_points.size(); i++)
        cout << processed_points[i] << " ";

    cout << endl << endl << " Everything is in order! " << endl;
    g.close();

    char cc;
    cout << "Enter a char to exit this window" << endl;
    cin >> cc;
    return 0;
}
