#include <bits/stdc++.h>

using namespace std;
int n,m,b[2222],x,y,ans;
vector<int> adj[2222];
pair<int,char> a[2222];
bool check[2222];
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
    for(int i=1; i<=n; i++) cin>>a[i].first>>a[i].second;
    for(int i=1; i<=m; i++){
        cin>>x>>y;
        if(a[x].second == 'c') adj[x].push_back(y);
        else adj[y].push_back(x);
    }
    for(int i=1; i<=n; i++,memset(check,false,sizeof(check))) if(dfs(i)) ans++;
    cout<<n-ans;
}