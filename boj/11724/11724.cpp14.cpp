#include <iostream>
#include <vector>

using namespace std;
vector<int> a[1001];
bool check[1001];
void dfs(int node){
	check[node]=1;
	for(int i=0; i<a[node].size(); i++){
		int next = a[node][i];
		if(check[next]==0){
			dfs(next);
		}
	}
}
int main(){
	int n,m,ans=0; 
	cin>>n>>m;
	for(int i=1; i<=m; i++){
		int u,v;
		cin>>u>>v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	for(int i=1; i<=n; i++){
		if(check[i]==false){
			dfs(i);
			ans++;
		}
	}
	cout<<ans<<'\n';
}