#include <iostream>

using namespace std;
int main(){
	long long int a,b=0,ans=0;
	cin>>a;
	if(a==1){
		cout<<1<<'\n';
		return 0;
	}
	while(1){
		if(a>1){
			a-=b; 	
			ans++;
		}
		else if(a<=1){
			break;
		}
		b+=6;
	}
	cout<<ans<<'\n';
}