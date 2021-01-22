#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll n,m,cost[2555];
bool check[2555][2555];
struct pos{
    ll here,dist,cost;
    pos(ll a,ll b,ll c) : here(a), dist(b),cost(c){}
    bool operator < (pos a) const {return cost > a.cost;}
};
vector<pair<ll,ll> > v[2555];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1; i<=n; i++) cin>>cost[i];
        for(int i=1,x,y,z; i<=m; i++){
        cin>>x>>y>>z;
        v[x].push_back({z,y});
        v[y].push_back({z,x});
    }
    for(int i=1; i<=n; i++) sort(v[i].begin(),v[i].end());
    priority_queue<pos,vector<pos>> pq;
    pq.push({1,cost[1],0});
    while(pq.size()){
        auto[here,d,c] = pq.top();
        pq.pop();
        if(check[here][d]) continue;
        if(here == n){
            cout<<c<<'\n';
            return 0;
        }
        check[here][d] = 1;
        for(pair<ll,ll> i : v[here]) pq.push({i.second,min(d,cost[i.second]),i.first * d + c});
    }
}