#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll n,m,ans;
using pi = pair<ll,ll>;
using pii = pair<pi,ll>;
vector<pi> adj[4444];
ll dist1[4444],dist2[4444][2];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1; i<=4333; i++) dist1[i] = dist2[i][1] = dist2[i][0] = 1e9;
    for(int i=1,x,y,z; i<=m; i++){
        cin>>x>>y>>z;
        adj[x].push_back({z*2,y});
        adj[y].push_back({z*2,x});
    }
    for(int i=1; i<=n; i++) sort(adj[i].begin(),adj[i].end());
    priority_queue<pi,vector<pi>,greater<pi>> pq;
    pq.push({0,1});
    dist1[1] = dist2[1][1] = 0;
    while(pq.size()){
        auto[cost,here] = pq.top();
        pq.pop();
        if(dist1[here] != cost) continue;
        for(pi next : adj[here]){
            if(dist1[next.second] > dist1[here] + next.first){
                dist1[next.second] = dist1[here] + next.first;
                pq.push({dist1[next.second],next.second});
            }
        }
    }
    priority_queue<pii,vector<pii>,greater<pii>> p;
    p.push({{0,1},1});
    while(p.size()){
        double cost = p.top().first.first;
        int here = p.top().first.second,cnt=p.top().second;
        p.pop();
        if(dist2[here][cnt%2] != cost) continue;
        for(pi next : adj[here]){
            double ncost = cnt%2 ? next.first / 2 : next.first*2;
            if(dist2[next.second][(cnt+1)%2] > dist2[here][cnt%2] + ncost){
                dist2[next.second][(cnt+1)%2] = dist2[here][cnt%2] + ncost;
                p.push({{dist2[next.second][(cnt+1)%2],next.second},cnt+1});
            }
        }
    }
    for(int i=2; i<=n; i++) if(min(dist2[i][0],dist2[i][1]) > dist1[i]) ans++;
    cout<<ans<<'\n';
}
