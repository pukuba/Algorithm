#include <bits/stdc++.h>

using namespace std;
using ll = unsigned long long;
ll n,m,a[101010],ans,s=1,e;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		cin>>a[i];
		e = max(e,a[i]);
	} e *=m;
	while(s<=e){
		ll mid = (s+e)/2, sum = 0; 
		for(int i=1; i<=n; i++) sum += mid/a[i];
		if(sum >= m){
			ans = mid;
			e = mid - 1;
		} 
		else s = mid + 1;
	}
	cout<<ans<<'\n';
}