#include <bits/stdc++.h>

using namespace std;
bool check[30011];
int n,depth[30011],d[30011][21],m,from,to,dist[30111],ans;
vector<int> v[30011];
void dfs(int here,int dep,int weight){
    check[here] = true;
    depth[here] = dep;
    dist[here] = weight;
    for(int i : v[here]){
        if(check[i]) continue;
        d[i][0] = here;
        dfs(i,dep+1,weight+1);
    }
}
int lca(int x,int y){
    if(depth[x] > depth[y]) swap(x,y);
    for(int i=20; i>=0; i--) if(depth[y] - depth[x] >= (1 << i)) y = d[y][i];
    if(x == y) return x;
    for(int i=20; i>=0; i--) if(d[y][i] != d[x][i]){
        y = d[y][i];
        x = d[x][i];
    } return d[x][0];
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>n;
    for(int i=1; i<n; i++){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    } dfs(1,0,0);
    for(int i=1; i<=20; i++) for(int j=1; j<=n; j++) d[j][i] = d[d[j][i-1]][i-1];
    cin>>m>>from;
    for(int i=1; i<m; i++){
        cin>>to;
        int _lca = lca(from,to);
        ans += dist[from] - dist[_lca] + dist[to] - dist[_lca];
        from = to;
    }
    cout<<ans<<'\n';
}
