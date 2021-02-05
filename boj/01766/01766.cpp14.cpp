#include <bits/stdc++.h>

using namespace std;
vector<int> adj[32001];
priority_queue<int,vector<int>,greater<>> pq;
int n,m,indgree[32001];
int main(){
    cin>>n>>m;
    for(int i=1; i<=m; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        indgree[y]++;
    }
    for(int i=1; i<=n; i++) if(!indgree[i]) pq.push(i);
    while(!pq.empty()){
        int cur = pq.top();
        pq.pop();
        cout<<cur<<' ';
        for(auto v : adj[cur]) if(!--indgree[v]) pq.push(v);
    }
}
