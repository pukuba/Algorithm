#include <bits/stdc++.h>

using namespace std;
int n,x,y,a[111111],dp[111111],rdp[111111],ans;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(nullptr);
	cin>>n;
	dp[1] = 1;
	for(int i=1; i<=n; i++) cin>>a[i];
	for(int i=2; i<=n; i++){
		dp[i] = 1;
		if(a[i] != a[i-1]) dp[i] = dp[i-1]+1;
		else dp[i] = 1;
	}
	rdp[n] = 1;
	for(int i=n-1; i>=1; i--){
		rdp[i] = 1;
		if(a[i+1] != a[i]) rdp[i] = rdp[i+1]+1;
		else rdp[i] = 1;
	}
	for(int i=1; i<=n; i++){
		ans = max(ans,dp[i-dp[i]] + dp[i] + rdp[i+1]);
	}
	cout<<ans<<'\n';
} 
