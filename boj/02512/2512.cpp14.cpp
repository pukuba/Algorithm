#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll n,m,a[10101],s=0,e,ans;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>a[i];
		e = max(e,a[i]);
	}
	cin>>m;
	while(s <= e){
		ll mid = s+e>>1, sum=0;
		for(int i=1; i<=n; i++) sum += min(mid,a[i]);
		if(sum <= m){
			ans = mid;
			s = mid + 1;
		}
		else e = mid - 1;
	}
	cout<<ans<<'\n';
}