#include <iostream>
//#include <string>
using namespace std;
int main(){
	string greeting = "Moshi Moshi";
	cout<< endl<< "Greeting: "<<greeting;
	
	string firstname = "Syamili ";
	string lastname = "Sake Nag ";
	string fullname = firstname+lastname;
	cout<< endl<< "Fullname: "<<fullname;
	
	string fullname2 = lastname.append(firstname);
	cout<< endl<< "Fullname2: "<<fullname2;
	
	//	STRING LENGTH
	string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	cout<< endl<< "Alphabet: "<< alphabet.length();
	cout<< endl<< "length(Alphabet): "<< alphabet.length();
	cout<< endl<< "size(Alphabet): "<< alphabet.size();

	//	FOR EACH
	cout<< endl<< "Letter in Alphabet: "<< endl;
	for(char c : alphabet)
	{
		cout<< c<< ": "<< (int)c<< " ";
	}
	//	FOR EACH using AUTO
	cout<< endl<< "Letter in Fullname"<< endl;
	for(auto c : fullname)
	{
		cout<< c;
	}
	
	//	GETLINE/ CIN - input entire line
	cout<< endl<< "Enter name: "<< endl;
	string name;
	getline(cin, name);
	cout<< endl<< "Name: "<< name;
	return 0;
}
