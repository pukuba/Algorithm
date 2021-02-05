#include <bits/stdc++.h>

using namespace std;
int n,m,x,y,dist[222],ans;
vector<pair<int,int> > adj[122],adj1[122];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1; i<=m; i++){
        cin>>x>>y;
        adj[x].push_back({y,1});
        adj1[y].push_back({x,1});
    }
    for(int i=1; i<=n; i++){
        priority_queue<pair<int,int>,vector<pair<int,int> >,greater<>> pq;
        pq.push({0,i});
        ans = 0;
        memset(dist,0x3f,sizeof(dist));
        dist[i] = 0;
        while(pq.size()){
            auto[w,here] = pq.top();
            pq.pop();
            if(dist[here] != w) continue;
            for(pair<int,int> i: adj[here]){
                int next = i.first;
                if(dist[next] > dist[here] + i.second){
                    dist[next] = dist[here] + i.second;
                    pq.push({dist[next],next});
                }
            }
        }
        pq.push({0,i});
        while(pq.size()){
            auto[w,here] = pq.top();
            pq.pop();
            if(dist[here] != w) continue;
            for(pair<int,int> i: adj1[here]){
                int next = i.first;
                if(dist[next] > dist[here] + i.second){
                    dist[next] = dist[here] + i.second;
                    pq.push({dist[next],next});
                }
            }
        }
        for(int i=1; i<=n; i++) if(dist[i] > 1e9) ans++;
        cout<<ans<<'\n';
    }
}