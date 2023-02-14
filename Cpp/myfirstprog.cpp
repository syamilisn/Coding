#include <iostream>
using namespace std;

int main(){
	/* multi-line comment */
	cout << "Hello world!\n";
	cout << "Line 2 text"<<endl;
	cout << "Line 3 text";
	
	int a=10;
	double b=18.33;
	char c='a';
	string word = "yam";
	string line = "my name is yam";
	bool game = true;
	cout << endl << a << endl << b <<endl <<c << endl;
	cout <<word <<endl <<line <<endl <<game<<endl;

	int x, y, z;
	x=y=z = 100;
	cout << x+y+z;
	const float pi = 3.14;

	return 0;
}
