#include <bits/stdc++.h>

using namespace std;
int n,a[1111],ans,temp;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=1; i<=n; i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1; i<=n; i++){
		ans += a[i];
		ans += temp;
		temp += a[i];
	}
	cout<<ans<<'\n';
}