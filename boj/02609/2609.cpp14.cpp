#include <iostream>

using namespace std;
int c,k,l;
int lcm(int x,int y){
	if(x==y){
		c=x;
		return x;
	}
	else if(x>y){
		return lcm(x,y+=l);
	}
	else if(y>x){
		x+=k;
		return lcm(x,y);
	}
	
}
int gcd(int x,int y){
	if(y==0){
		c=x;
		return x;
	}
	else{
		return gcd(y,x%y);
	}
}
int main(){
	int q,d;
	cin>>q>>d;
	k=q,l=d;
	gcd(q,d);
	cout<<c;
	lcm(q,d);
	cout<<'\n'<<c;
}