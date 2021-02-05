#include <bits/stdc++.h>

using namespace std;
long long gcd(long long a,long long b){return b?gcd(b,a%b) : a;}
long long t,n,a[111],ans;
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		ans = 0;
		for(long long i=1; i<=n; i++) cin>>a[i];
		for(long long i=1; i<=n; i++){
			for(long long j=i+1; j<=n; j++) ans += gcd(a[i],a[j]);
		}
		cout<<ans<<'\n';
	}
}