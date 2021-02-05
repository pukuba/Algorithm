#include <bits/stdc++.h>

using namespace std;
int n,m,parent[1010],x,ans;
struct pos{
    int here,go,cnt;
    bool operator < (const pos &a) const{
        return cnt < a.cnt;
    }
};
vector<pos> adj;
int find(int x){
    if(x == parent[x]) return parent[x];
    return parent[x] = find(parent[x]);
}
void merge(int a,int b){
    parent[find(a)] = find(b);
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    for(int i=1; i<=n; i++) parent[i] = i;
    for(int i=1,x,y,z; i<=m; i++){
        cin>>x>>y>>z;
        adj.push_back({x,y,z});
    }
    sort(adj.begin(),adj.end());
    for(pos i : adj){
        if(x == n - 1) break;
        if(find(i.here) == find(i.go)) continue;
        ans += i.cnt;
        merge(i.here,i.go);
        x++;
    }
    cout<<ans<<'\n';
}
