#include <bits/stdc++.h>

using namespace std;
int n,m,ans;
vector<int> adj[555];
vector<int> v[555];
bool check[555];
int dfs(int here,vector<int> w[555]){
    check[here] = 1;
    int ret = 1;
    for(int next : w[here]) if(!check[next]) ret += dfs(next,w);
    return ret;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    for(int i=1,x,y; i<=m; i++){
        cin>>x>>y;
        adj[x].push_back(y);
        v[y].push_back(x);
    }
    for(int i=1; i<=n; i++){
        memset(check, 0, sizeof check);
        int a = dfs(i,adj);
        memset(check, 0, sizeof check);
        int b = dfs(i,v);
        if(a+b - 1 == n) ans++;
    }
    cout<<ans<<'\n';
}