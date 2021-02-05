#include <bits/stdc++.h>

using namespace std;
int d[100111][21],_min[100111][21],_max[100111][21],n,m,depth[100111];
bool check[100111];
vector<pair<int,int> > v[100111];
void dfs(int here,int dep){
    check[here] = true;
    depth[here]  = dep;
    for(pair<int,int> i : v[here]){
        int next = i.first,weight = i.second;
        if(check[next]) continue;
        d[next][0] = here;
        _min[next][0] = weight;
        _max[next][0] = weight;
        dfs(next,dep+1);
    }
}
pair<int,int> lca(int a,int b){
    int ret_min = 1e9, ret_max = -1e9;
    if(depth[a] > depth[b]) swap(a,b);
    for(int i=20; i>=0; i--) if(depth[b] - depth[a] >= (1 << i)){
        ret_min = min(ret_min,_min[b][i]);
        ret_max = max(ret_max,_max[b][i]);
        b = d[b][i];
    }
    if(a == b) return {ret_min,ret_max};
    for(int i=20; i>=0; i--) if(d[a][i] != d[b][i]){
        ret_min = min({ret_min,_min[a][i],_min[b][i]});
        ret_max = max({ret_max,_max[a][i],_max[b][i]});
        a = d[a][i];
        b = d[b][i];
    }
    ret_min = min({ret_min,_min[a][0],_min[b][0]});
    ret_max = max({ret_max,_max[a][0],_max[b][0]});
    return {ret_min,ret_max};
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>n;
    for(int i=1; i<n; i++){
        int a,b,c;
        cin>>a>>b>>c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    } dfs(1,0);
    for(int i=1; i<=20; i++) for(int j=1; j<=n; j++){
        d[j][i] = d[d[j][i-1]][i-1];
        _min[j][i] = min(_min[j][i-1],_min[d[j][i-1]][i-1]);
        _max[j][i] = max(_max[j][i-1],_max[d[j][i-1]][i-1]);
    } cin>>m;
    while(m--){
        int from,to;
        cin>>from>>to;
        pair<int,int> ans = lca(from,to);
        cout<<ans.first<<' '<<ans.second<<'\n';
    }
}
