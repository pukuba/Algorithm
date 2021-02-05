#include <iostream>

using namespace std;
int main(){
	int a,b,c,d,ans=0,t=3;
	while(t>0)
	{
	cin>>a>>b>>c>>d;
	ans=a+b+c+d;
	if(ans==4){
		cout<<"E"<<'\n';
	}
	if(ans==3){
		cout<<"A"<<'\n';
	}
	if(ans==2){
		cout<<"B"<<'\n';
	}
	if(ans==1){
		cout<<"C"<<'\n';
	}
	if(ans==0){
		cout<<"D"<<'\n';
	}
	ans=0;
	t--;
}
}