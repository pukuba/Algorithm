#include <bits/stdc++.h>

using namespace std;
int n,ans;
vector<pair<int,int> > v;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=1,x,y; i<=n; i++){
		cin>>x>>y;
		v.push_back({x,y});
	}
	sort(v.begin(),v.end());
	for(int i=0; i<v.size(); i++){
		if(ans <= v[i].first) ans = v[i].first + v[i].second;
		else if(ans > v[i].first) ans += v[i].second;
	}
	cout<<ans<<'\n';
}