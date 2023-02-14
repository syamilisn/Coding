#include <iostream>
using namespace std;

void display(int x=0, string prompt="\n"){ //Default function parameters
	cout << prompt << x;
}
int dynamic(){
	cout << "Enter value: ";
	int a;
	cin >> a;
	return a;
}
int main(){

	int value = dynamic();
	cout<< "value :" << value << endl;
	display(value, "display value: ");
	return 0;
}
