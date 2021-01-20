#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	int n,k,cnt=0;
	scanf("%d %d",&n ,&k);
	for(int i=1; i<=n; i++){
		if(n%i==0){
			cnt++;
			if(cnt==k){
				cout<<i<<'\n';
				return 0;
			}
		}
	}
	cout<<"0"<<'\n'; 
}