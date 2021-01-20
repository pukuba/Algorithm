#include <iostream>
#include <string>

using namespace std;
int main(){
	ios_base::sync_with_stdio(false),cin.tie(NULL);
	int T=3;
	long long int x=0;
	string a;
	while(T--){
		cin>>a;
		if(T==2){
		if(a=="black") x+=0;
		if(a=="brown") x+=10;
		if(a=="red") x+=20;
		if(a=="orange") x+=30;
		if(a=="yellow") x+=40;
		if(a=="green") x+=50;
		if(a=="blue") x+=60;
		if(a=="violet") x+=70;
		if(a=="grey") x+=80;
		if(a=="white") x+=90;
	}if(T==1){
		if(a=="black") x+=0;
		if(a=="brown") x+=1;
		if(a=="red") x+=2;
		if(a=="orange") x+=3;
		if(a=="yellow") x+=4;
		if(a=="green") x+=5;
		if(a=="blue") x+=6;
		if(a=="violet") x+=7;
		if(a=="grey") x+=8;
		if(a=="white") x+=9;
	}
	if(T==0){
		if(a=="black") x*=1;
		if(a=="brown") x*=10;
		if(a=="red") x*=100;
		if(a=="orange") x*=1000;
		if(a=="yellow") x*=10000;
		if(a=="green") x*=100000;
		if(a=="blue") x*=1000000;
		if(a=="violet") x*=10000000;
		if(a=="grey") x*=100000000;
		if(a=="white") x*=1000000000;
	}
	
	}
	cout<<x;
}