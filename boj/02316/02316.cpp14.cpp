#include <bits/stdc++.h>

using namespace std;
int n,start,end,capa[850][850],flow[850][850],prv[850],m,source=401,sink=2,inf=1e9,ans;
vector<int> adj[850];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1; i<=400; i++){
        capa[i][i+400]++;
        adj[i].push_back(i+400);
        adj[i+400].push_back(i);
    }
    while(m--){
        int x,y;
        cin>>x>>y;
        capa[x+400][y]++;
        capa[y+400][x]++;
        adj[x+400].push_back(y);
        adj[y].push_back(x+400);
        adj[y+400].push_back(x);
        adj[x].push_back(y+400);
    }
    while(1){
        queue<int> q;
        memset(prv,-1,sizeof(prv));
        q.push(source);
        while(q.size()){
            int here = q.front();
            q.pop();
            for(int next : adj[here]){
                if(prv[next] != -1) continue;
                if(capa[here][next] - flow[here][next] > 0){
                    q.push(next);
                    prv[next] = here;
                    if(next == 2) break;
                }
            }
        }
        if(prv[2] == -1) break;
        int pos = inf;
        for(int i=2; i!=401; i=prv[i]) pos = min(pos,capa[prv[i]][i] - flow[prv[i]][i]);
        for(int i=2; i!=401; i=prv[i]){
            flow[prv[i]][i] += pos;
            flow[i][prv[i]] -= pos;
        }
        ans++;
    }
    cout<<ans;
}