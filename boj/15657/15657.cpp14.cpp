#include <bits/stdc++.h>

using namespace std;
vector<int> v;
int n,m,arr[101];
void dfs(int here,int use){
	if(use == m){
		for(int i : v) cout<<i<<' ';
		cout<<'\n';
		return;
	}
	for(int i=here; i<=n; i++){
		v.push_back(arr[i]);
		dfs(i,use+1);
		v.pop_back();
	}
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1; i<=n; i++) cin>>arr[i];
	sort(arr+1,arr+n+1);
	dfs(1,0);
}