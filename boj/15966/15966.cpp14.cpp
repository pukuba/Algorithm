#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll n,m,d[1234231],ans;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(nullptr);
	cin>>n;
	for(int i=1,x; i<=n; i++){
		cin>>x;
		d[x] = 1;
		if(d[x-1]) d[x]=max(d[x-1]+1,d[x]);
	}
	for(int i=1; i<=1111111; i++) ans= max(ans,d[i]);
	cout<<ans<<' '; 
}