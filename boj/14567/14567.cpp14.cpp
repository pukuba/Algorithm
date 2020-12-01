#include <bits/stdc++.h>

using namespace std;
int n,m,sum[1010],ans[1010];
vector<int> adj[1010];
bool check[1010];
queue<pair<int,int> > q;
int main(){
    cin>>n>>m;
    while(m--){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        sum[y]++;
    }
    for(int i=1; i<=n; i++){
        if(sum[i]==0) q.push({i,1});
    }
    while(!q.empty()){
        auto[ cur_node,cnt] = q.front();
        check[cur_node]=true;
        ans[cur_node] = cnt;
        q.pop();
        for(int there : adj[cur_node]){
            if(--sum[there]==0) q.push({there,cnt+1});
        }
    }
    for(int i=1; i<=n; i++) cout<<ans[i]<<' ';
}