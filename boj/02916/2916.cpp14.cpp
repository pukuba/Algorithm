#include <bits/stdc++.h>

using namespace std;
int n,k,have[11],d[11][400];
void dp(int idx,int sum){
	if(idx < 0 || idx > n) return;
	if(sum > 360) sum-=360;
	if(sum < 0) sum+=360;
	if(d[idx][sum] != -1) return;
	d[idx][sum] = 1;
	dp(idx+1,sum);
	dp(idx,sum+have[idx]);
	dp(idx,sum-have[idx]);
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(nullptr);
	cin>>n>>k;
	memset(d,-1,sizeof(d));
	for(int i=1; i<=n; i++) cin>>have[i];
	dp(0,0);
	while(k--){
		int r;
		cin>>r;
		bool check=false;
		for(int i=1; i<=10; i++) if(d[i][r] == 1) check=true;
		if(check) cout<<"YES\n";
		else cout<<"NO\n";
	}
}