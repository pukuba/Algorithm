#include <bits/stdc++.h>

using namespace std;
int n,m,sum[32001];
vector<int> adj[32001];
bool check[32001];
queue<int> q;
int main(){
    cin>>n>>m;
    while(m--){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        sum[y]++;
    }
    for(int i=1; i<=n; i++){
        if(sum[i]==0) q.push(i);
    }
    while(!q.empty()){
        int cur_node = q.front();
        check[cur_node]=true;
        cout<<cur_node<<' ';
        q.pop();
        for(int there : adj[cur_node]){
            if(--sum[there]==0) q.push(there);
        }
    }
    for(int i=1; i<=n; i++){
        if(check[i]==false) cout<<i<<' ';
    }
}
