#include <bits/stdc++.h>

using namespace std;
int n,a[111111],temp,ans;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=1; i<=n; i++) cin>>a[i];
	reverse(a+1,a+n+1);
	for(int i=1; i<=n; i++) if(temp < a[i]) ans++,temp = a[i];	
	cout<<ans<<'\n';
}