#include <iostream>
#include <string>
#include <sstream>
using namespace std;
int main(){
	string str=" 42 3.14";
	int a;
	double p=0.0;
	istringstream istr(str);
	istr >> a;
	istr >> p;
	cout << "a=" <<a<<endl;
	cout<< "p="<<p<<endl;
	ostringstream ostr;
	ostr << "a=" <<a<<"p="<<p<<endl;
	string str2 = ostr.str();
	cout<<str2<<endl;
}
