#include "std_lib_facilities.h"

int main(){

	string first_name, friend_name;
	char friend_sex = ' ';
	int age=0;
	
	/*cout << "Please enter your first name: ";
	cin >> frist_name;	
	cout << endl;*/
	
	cout << "Enter the name of the person you want to write to: ";
	cin >> first_name;
	cout << endl;	
	
	//Letter:
	cout << "   Dear " << first_name << ", " << endl << endl; 
	cout <<     "   How are you? I am fine. I miss you." << endl; 
	cout <<     "I just started wondering what have you " << endl;
	cout <<    "been up to lately. I have started my" << endl;
	cout <<     "studies at the University of Debrecen " << endl;  
 	cout <<     "and so far I'm really liking it."<< endl; 
	
	cout << endl;
	cout << "Enter the name of another friend of yours: ";
	cin >> friend_name;
	
	cout << "Enter the gender of your friend (m/f): ";
	cin >> friend_sex;
	cout << endl;
	
	cout <<     "   Have you seen " << friend_name << " lately? ";
	cout <<     "If you see "<< endl << friend_name << " please ask ";
	     	
	     	if(friend_sex == 'm') cout << "him to call me." << endl << endl;
	     		else cout << "her to call me." << endl << endl;
	
	cout << "Enter the age of the recipient: ";
	cin >> age;
	cout << "I hear you just had a birthday and you are " << age << endl;
	cout <<	"years old. ";
		
		if(age <= 0 || age >= 110) simple_error("You're kidding! ");
		else if (age<12) cout << "Next year you will be " << age+1 << "." << endl << endl;
		else if (age == 17) cout << "Next year you will be abel to vote" << endl << endl;
		else if (age >= 70) cout << "I hope you are enjoying retirement" << endl << endl;
		cout << "    Yours sincerely, ";
		cin >> first_name;
		
	cout << endl;		 	     
	
return 0;
}
