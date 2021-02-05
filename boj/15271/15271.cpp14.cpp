#include <bits/stdc++.h>

using namespace std;
int n,m,x,y,b[222],ans=1;
vector<int> adj[222];
bool check[222];
bool dfs(int here){
    check[here] = true;
    for(int next : adj[here]) if(!b[next] || !check[b[next]] && dfs(b[next])){
        b[next] = here;
        return true;
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1; i<=m; i++){
        cin>>x>>y;
        if((x&1) != (y&1)){
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
    }
    for(int i=1; i<=n; i++,memset(check,false,sizeof(check))) if(dfs(i)) ans++;
    cout<<(ans > n ? n : ans);
}