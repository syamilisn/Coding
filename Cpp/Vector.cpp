
#include <iostream>
#include <vector>
using namespace std;
int main(){
	vector<string> sentence{ "This", "is", "foreach", "example", "using", "vector."};
	for( auto word : sentence)
		cout<< word<< " ";
	return 0;
}
