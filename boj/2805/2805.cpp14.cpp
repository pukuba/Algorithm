#include <bits/stdc++.h>

using ll = long long;
using namespace std;
ll n,m,a[1111111],s,e,ans;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		cin>>a[i];
		e = max(e,a[i]);
	}
	while(s <= e){
		ll mid = s+e>>1,temp = 0;
		for(int i=1; i<=n; i++){
			if(mid < a[i]) temp += a[i] - mid;
		}
		if(temp >= m){
			ans = mid;
			s = mid + 1;
		}
		else e = mid - 1;
	}
	cout<<ans<<'\n';
}