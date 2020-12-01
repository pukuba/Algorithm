#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll n,d[2020][2020],a[2020],ans;
ll f(int l,int r,int turn){
	if(turn == n-1) return 0;
	if(d[l][r] != -1) return d[l][r];
	int next_l,next_r;
	if(l - 1 == 0) next_l = n;
	else next_l = l-1;
	if(r + 1 == n + 1) next_r = 1;
	else next_r = r+1;
	if(~turn & 1){
		if(a[next_l] >= a[next_r]) return d[l][r] = f(next_l,r,turn+1);	
		return d[l][r] = f(l,next_r,turn+1);
	}
	return d[l][r] = max(f(next_l,r,turn+1) + a[next_l],f(l,next_r,turn+1) + a[next_r]);
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(nullptr);
	memset(d,-1,sizeof(d));
	cin>>n;
	for(int i=1; i<=n; i++) cin>>a[i];
	for(int i=1; i<=n; i++) ans = max(ans,f(i,i,0) + a[i]);
	cout<<ans<<'\n';
}