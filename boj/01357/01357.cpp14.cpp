#include <iostream>
#include <algorithm>

using namespace std;
int main(){
	string a{NULL,},b{NULL,};
	int i=0;
	cin>>a>>b;
	reverse(a.begin(),a.end()),reverse(b.begin(),b.end());
	i=stoi(a)+stoi(b);
	a=to_string(i);
	reverse(a.begin(),a.end());
	i=stoi(a);
	cout<<i<<'\n';
}