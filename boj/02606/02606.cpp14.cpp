#include <bits/stdc++.h>

using namespace std;
int n,m,ans,dx[8]={0,-1,0,1,-1,-1,1,1},dy[8]={-1,0,1,0,1,-1,-1,1};
vector<int> adj[102];
bool check[102];
int dfs(int here){
	int ret = 1;
	check[here] = 1;
	for(int next : adj[here]) if(!check[next]) ret += dfs(next);
	return ret;
}
bool in(int a,int b){return 1<=a && a<=n && 1<=b && b<=m;}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1,x,y; i<=m; i++){
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	cout<<dfs(1)-1;
}