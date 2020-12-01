#include <iostream>

using namespace std;
int main(){
	int a,b,T=4,sum=0,max=0;
	while(T--){
		cin>>a>>b;
		sum-=a;
		sum+=b;
		if(max<sum){
			max=sum;
		}
	}
	cout<<max<<'\n';
}