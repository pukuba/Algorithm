#include <bits/stdc++.h>

using namespace std;
int flow[503][503],capa[503][503],n,m,prv[503],weight[503][503],dist[503],source=1,sink=2,ans,inf=1e9;
vector<int> adj[503];
queue<int> q;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>n>>m;
    while(m--){
        int x,y;
        cin>>x>>y;
        capa[x][y]++;
        weight[x][y]++;
        weight[y][x]--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    while(1){
        while(q.size()) q.pop();
        memset(prv,-1,sizeof(prv));
        fill(dist,dist + 503,inf);
        dist[source] = 0;
        q.push(source);
        while(q.size()){
            int here = q.front();
            q.pop();
            for(int next : adj[here]){
                if(prv[next] == -1 && capa[here][next] - flow[here][next] > 0 && dist[next] > dist[here] + weight[here][next]){
                    dist[next] = dist[here] + weight[here][next];
                    prv[next] = here;
                    q.push(next);
                    if(next == sink) break;
                }
            }
        }
        int pos = inf;
        if(prv[sink] == -1) break;
        for(int i=sink; i!=source; i=prv[i]) pos = min(pos,capa[prv[i]][i] - flow[prv[i]][i]);
        for(int i=sink; i!=source; i=prv[i]){
            flow[prv[i]][i] += pos;
            flow[i][prv[i]] -= pos;
        }
        ans++;
    }
    cout<<ans;
}