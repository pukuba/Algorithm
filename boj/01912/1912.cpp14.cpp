#include <bits/stdc++.h>

using namespace std;
int n,a[111111],d[111111],ans=-1e9;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>a[i];
		d[i] = max(a[i],d[i-1] + a[i]);
		ans = max(d[i],ans);
	}
	cout<<ans<<'\n';
}