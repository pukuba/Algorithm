#include <iostream>

using namespace std;
int main(){
	int front,back,n,temp,count=0;
	cin>>n;
	
	temp=n;
	if(n<0 || n>99){
		return -1;
	}
	while(1){
		front=n/10;
		back=n%10;
		n= back*10+((front+back) %10);
		count++;
		if(n==temp){
			cout<<count<<'\n';
			break;
		}
		}
}
