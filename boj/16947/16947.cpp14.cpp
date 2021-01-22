#include <bits/stdc++.h>

using namespace std;
int n;
bool check[3030],cycle[3030];
vector<int> adj[3030];
void dfs(int here, int par, int cnt){
    if(here == par && cnt >= 3){
        cycle[here] = 1;
        return;
    }
    check[here] = 1;
    for(int next : adj[here]){
        if(!check[next]) dfs(next,par,cnt + 1);
        else if(par == next && cnt >= 3) dfs(next,par,cnt);
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i=1,x,y; i<=n; i++){
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(int i=1; i<=n; i++){
        memset(check, 0, sizeof check);
        dfs(i,i,1);
    }
    for(int i=1; i<=n; i++){
        if(cycle[i]) cout<<0<<' ';
        else{
            memset(check, 0, sizeof check);
            queue<pair<int,int> > q;
            q.push({i,0});
            check[i] = 1;
            while(q.size()){
                auto [here,cnt] = q.front();
                q.pop();
                if(cycle[here]){
                    cout<<cnt<<' ';
                    break;
                }
                for(int next : adj[here]) if(!check[next]) check[next] = 1,q.push({next,cnt+1});
            }
        }
    }
}