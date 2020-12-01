#include <bits/stdc++.h>

using namespace std;
vector<pair<int,int> > v;
int n,go=-1,ans;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=1,x,y; i<=n; i++){
		cin>>x>>y;
		v.push_back({y,x});
	}
	sort(v.begin(),v.end());
	for(int i=0; i<v.size(); i++) if(go <= v[i].second) ans++,go=v[i].first;
	cout<<ans<<'\n';
}