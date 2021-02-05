#include <bits/stdc++.h>

using namespace std;
int n,m,k,t,_count[301],d[301][301];
vector<pair<int,int> > v;
int dfs(int idx,int peo,int prev){
    if(idx == v.size()) return 0;
    int &ret = d[idx][peo];
    if(ret != -1) return ret;
    ret = 0;
    int cost = max(0,t - v[idx].second);
    int real_cost = (prev >= cost) ? 0 : cost;
    if(peo  - real_cost >= 0) return ret = max(dfs(idx+1,peo - real_cost,cost)+v[idx].first , dfs(idx+1,peo,0));
    return ret = dfs(idx+1,peo,0);
}
int main(){
    cin>>n>>m>>k>>t;
    memset(d,-1,sizeof(d));
    for(int i=1; i<=m; i++){
        int x,y;
        cin>>x>>y;
        for(int i=x+1; i<=y; i++) if(_count[i] < t) _count[i]++;
    }
    int temp = _count[1],_size=0;
    for(int i=2; i<=n+1; i++){
        if(temp!=_count[i]){
                v.push_back({_size,temp});
                _size = 0;
                temp = _count[i];
        }
        _size++;
    }
    v.push_back({_size,temp});
    cout<<dfs(0,k,0);
}
