#include <bits/stdc++.h>

using namespace std;
int n,t,depth[50111],d[50111][21],dist[50111],m;
bool check[50111];
vector<pair<int,int> > v[50111];
void dfs(int here,int dep,int w){
    check[here] = true;
    depth[here] = dep;
    for(auto i : v[here]){
        if(check[i.first]) continue;
        d[i.first][0] = here;
        dist[i.first] = w+i.second;
        dfs(i.first,dep+1,w+i.second);
    }
}
int lca(int x,int y){
    if(depth[x] > depth[y]) swap(x,y);
    for(int i=20; i>=0; i--) if(depth[y] - depth[x] >= (1 << i)) y = d[y][i];
    if(x == y) return x;
    for(int i=20; i>=0; i--) if(d[x][i] != d[y][i]){
        x = d[x][i];
        y = d[y][i];
    }
    return d[y][0];
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>n;
    for(int i=1; i<n; i++){
        int a,b,c;
        cin>>a>>b>>c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    } dfs(1,0,0);
    for(int j=1; j<=20; j++) for(int i=1; i<=n; i++) d[i][j] = d[d[i][j-1]][j-1];
    cin>>m;
    while(m--){
        int from,to;
        cin>>from>>to;
        int ff = lca(from,to);
        cout<<dist[from] - dist[ff] + dist[to] - dist[ff]<<'\n';
    }
}
