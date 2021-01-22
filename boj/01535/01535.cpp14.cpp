#include <bits/stdc++.h>

using namespace std;
int d[101];
int main(){
	int n;
	cin>>n;
	int minus_hp[n+1];
	int plus_happy[n+1];
	for(int i=1; i<=n; i++){
		cin>>minus_hp[i];
	}
	for(int i=1; i<=n; i++){
		cin>>plus_happy[i];
	}
	for(int i=1; i<=n; i++){
		for(int j=100; j>=minus_hp[i]; j--){
			if(j-minus_hp[i]>=1){
				d[j]=max(d[j-minus_hp[i]]+plus_happy[i],d[j]);	
			}
		}
	}
	int ans=0;
	for(int i=1; i<=100; i++){
		ans=max(ans,d[i]);
	}
	cout<<ans<<'\n';
}