#include <iostream>
#include <cmath>

using namespace std;
int main(){
	long long n,m,a=0,skip=0,hap=0,min=999999999,ans=0;
	cin>>n>>m;
	while(1){
		a++;
		skip=pow(a,2);
		if(n<=skip&&m>=skip){
			ans+=skip;
			if(min>skip){
				min=skip;
			}
		}
		if(skip>m){
			break;
		}
	}
	if(ans==0){
		cout<<"-1";
	}
	else cout<<ans<<'\n'<<min;
}