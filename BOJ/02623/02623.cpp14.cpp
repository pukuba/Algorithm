#include <bits/stdc++.h>

using namespace std;
int n,m,indegree[1001];
vector<int> adj[1001],ans;
queue<int> q;
int main(){
    cin>>n>>m;
    while(m--){
        int x;
        cin>>x;
        int start;
        cin>>start;
        for(int i=1; i<x; i++){
            int vv;
            cin>>vv;
            adj[start].push_back(vv);
            indegree[vv]++;
            start = vv;
        }
    }
    for(int i=1; i<=n; i++) if(!indegree[i]) q.push(i);
    while(!q.empty()){
        int here_v = q.front();
        ans.push_back(here_v);
        q.pop();
        for(auto v : adj[here_v]) if(!--indegree[v]) q.push(v);
    }
    if(ans.size()==n) for(int i=0; i<n; i++) cout<<ans[i]<<'\n';
    else cout<<"0\n";
}
