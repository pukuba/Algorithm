#include <bits/stdc++.h>

using namespace std;
int n,m,s;
vector<int> adj[1010];
bool check[1010];
void dfs(int here){
	check[here] = 1;
	cout<<here<<' ';
	for(int next : adj[here]) if(!check[next]) dfs(next);
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(nullptr);
	queue<int> q;
	cin>>n>>m>>s;
	for(int i=1,x,y; i<=m; i++){
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}	
	for(int i=1; i<=1000; i++) sort(adj[i].begin(),adj[i].end());
	dfs(s);
	memset(check,0,sizeof check);
	q.push(s);
	check[s]=1;
	cout<<'\n';
	while(q.size()){
		int here = q.front();
		cout<<here<<' ';
		q.pop();
		for(int next : adj[here]) if(!check[next]){
			check[next] = 1;
			q.push(next);
		}
	}
}