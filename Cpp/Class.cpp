#include <iostream>
using namespace std;

class A{
	private:
		int var=0;
	public:
		A(int x=0): var(x){};
		void setVar(int s){
			var=s;
			return;
		}
		int getVar(){
			return var;
		}
};

int main(){
	A a(1);
	a.setVar(2);
	cout<< "var : " <<a.getVar() <<endl;
}
