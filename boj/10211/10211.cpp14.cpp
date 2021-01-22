#include <bits/stdc++.h>

using namespace std;
int n,t,ans,d[1010],a[1010];
int main(){
	ios_base::sync_with_stdio(0);cin.tie(nullptr);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1; i<=n; i++) cin>>a[i];
		fill(d,d+1006,-1e9);
		ans = -1e9;
		for(int i=1; i<=n; i++){
			d[i] = d[i-1] + a[i];
			ans = max(d[i],ans);
			if(d[i] < a[i]) d[i] = a[i];
			ans = max(d[i],ans);
		}
		cout<<ans<<'\n';
	}
}