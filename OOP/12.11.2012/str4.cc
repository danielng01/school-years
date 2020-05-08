#include <iostream>
#include <string>
#include <sstream>
using namespace std;
int main(){
	string str=" Ala Bala";
	double d=0.0;
	istringstream istr(str);
	istr>>d;
	if(!istr){
		cout<<"can't read";
	}
	cout<<"d="<<d<<endl;
}
