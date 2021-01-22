#include <iostream>

using namespace std;
int main(){
	unsigned long long a,b,c,d=0;
	cin>>a>>b;
	if(a==b){
		cout<<0;
		return 0;
	}
	if(b>a){
		d=a;
		a=b;
		b=d;
	}
	c=a-b;
	if(c==1){
		cout<<'0';
		return 0;
	}
	cout<<a-b-1<<'\n';
	while(1){
		b++;
		cout<<b<<' ';
		if(b>=a-1){
			break;	
		}
	}
}