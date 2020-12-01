#include <iostream>
#include <algorithm>
	
using namespace std;
int main(){
	int a,b,c;
	cin>>a>>b>>c;
	if(a==b&&a==c){
		cout<<10000+a*1000;
	}
	else if(a==b||b==c||c==a){
		if(a==b){
			cout<<1000+a*100;
		}
		else if(b==c){
			cout<<1000+b*100;
		}
		else if(c==a){
			cout<<1000+c*100;
		}
	} 
	else if(a!=b&&b!=c&&c!=a){
	a *=100,b *=100,c *=100;
	int f=max(a,b);
	int d=max(f,c);
	cout<<d;
}
}