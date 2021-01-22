#include <bits/stdc++.h>

using namespace std;
int a,b,n,m,x,y;
vector<int> adj[1111];
bool check[1111];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>a>>b>>n>>m;
    for(int i=1; i<=m; i++){
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    queue<pair<int,int> > q;
    q.push({a,0});
    check[a] = true;
    while(q.size()){
        auto[here,cnt] = q.front();
        if(here == b){
            cout<<cnt<<'\n';
            return 0;
        }
        q.pop();
        for(int next : adj[here]){
            if(check[next]) continue;
            q.push({next,cnt+1});
            check[next] = true;
        }
    }
    cout<<-1;
}