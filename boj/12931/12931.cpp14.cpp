#include <bits/stdc++.h>

using namespace std;
int n,arr[51],ans;
int main(){
	ios_base::sync_with_stdio(0),cin.tie(nullptr);
	cin>>n;
	for(int i=1; i<=n; i++) cin>>arr[i];
	while(1){
		bool check = true,div=true;
		for(int i=1; i<=n; i++) if(arr[i]) check=false;
		if(check) break;
		for(int i=1; i<=n; i++) if(arr[i]%2) div=false;
		if(div) for(int i=1; i<=n; i++) arr[i]/=2;
		else for(int i=1; i<=n; i++) if(arr[i]%2){
			arr[i]--;
			break;
		}
		ans++;
	} 
	cout<<ans;
}