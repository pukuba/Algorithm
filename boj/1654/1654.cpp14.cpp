#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll n,m,a[10101],ans,s=1,e;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		cin>>a[i];
		e = max(e,a[i]);
	}
	while(s <= e){
		ll mid = s + e >> 1, sum = 0;
		for(int i=1; i<=n; i++) sum += a[i] / mid;
		if(m <= sum){
			ans = mid;
			s = mid + 1;
		} else e = mid - 1;
	}
	cout<<ans<<'\n';
}