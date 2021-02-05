#include <iostream>

using namespace std;
int main(){
	int n;
	cin>>n;
	long long ans=0;
	for(int i=1,len=1; i<=n; len++,i*=10){
		int end=i*10-1;
		if(end>n){
			end=n;
		}
		ans+=(long long)(end-i+1)*len;
	}
	cout<<ans<<'\n';
}