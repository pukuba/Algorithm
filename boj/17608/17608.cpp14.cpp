#include <bits/stdc++.h>

using namespace std;
int n,arr[100001],ans,height;
main(){
	cin>>n;
	for(int i=1; i<=n; i++) cin>>arr[i];
	for(int i=n; i>=1; i--){
		if(arr[i]>height){
			ans++;
			height=arr[i];
		}
	}
	cout<<ans<<'\n';
}