#include <bits/stdc++.h>

using namespace std;
int n;
string s[111111];
vector<pair<int,int> > v;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=1,x; i<=n; i++){
		cin>>x>>s[i];
		v.push_back({x,i});
	}
	sort(v.begin(),v.end());
	for(int i=0; i<v.size(); i++) cout<<v[i].first<<' '<<s[v[i].second]<<'\n';
	
}