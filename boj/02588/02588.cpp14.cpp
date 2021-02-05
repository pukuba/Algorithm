#include <iostream>
#include <cstring>

using namespace std;
int main(){
	int a;
	cin>>a;
	string b;
	cin>>b;
	cout<<a*stoi(b.substr(2,1)) <<endl;
	cout<<a*stoi(b.substr(1,1))<<endl;
	cout<<a*stoi(b.substr(0,1))<<endl;
	cout<<a*stoi(b);
} 