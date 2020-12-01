#include <bits/stdc++.h>

using namespace std;
int n,m,ans;
vector<int> adj[1010];
bool check[1010];
void dfs(int here){
	check[here] = 1;
	for(int next : adj[here]) if(!check[next]) dfs(next);
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1,x,y; i<=m; i++){
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}	
	for(int i=1; i<=n; i++){
		if(!check[i]){
			dfs(i);
			ans++;
		}
	}
	cout<<ans<<'\n';
}