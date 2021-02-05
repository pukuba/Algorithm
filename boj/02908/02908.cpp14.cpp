#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int main(){
	string a,b;
	int a1,b1;
	cin>>a>>b;
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	a1=stoi(a);
	b1=stoi(b);
	if(a1>b1)
	{
		cout<<a1;
	}
	else{
		cout<<b1;
	}
}