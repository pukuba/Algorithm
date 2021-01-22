#include <bits/stdc++.h>

using namespace std;
int n,a[101010],ans,tmp; 
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=1,x; i<=n*2; i++){
		cin>>x;
		if(!a[x]) tmp++,a[x]++;
		else a[x]--,tmp--;
		ans = max(tmp,ans);
	}
	cout<<ans<<'\n';
}