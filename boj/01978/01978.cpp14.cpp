#include <iostream>

using namespace std;
int prime(int n){
	if(n<2){
		return 0;
	}
	for(int i=2; i*i<=n; i++){
		if(n%i==0){
			return 0;
		}
	}
	return 1;
}
int main(){
	int a,num=0,t;
	cin>>t;
	while(t--){
	cin>>a;
	if(prime(a)){
		num++;
		}
	}
	cout<<num;
}