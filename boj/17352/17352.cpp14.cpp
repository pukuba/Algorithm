#include <bits/stdc++.h>

using namespace std;
int n,x,y,ans,save,ans2;
vector<int> adj[311111];
bool check[311111];
void dfs(int here){
    check[here] = true;
    for(int next : adj[here]){
        if(!check[next]){
            dfs(next);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>n;
    for(int i=1; i<=n-2; i++){
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1);
    for(int i=1; i<=n; i++){
        if(check[i]) ans++;
        if(!check[i]) save=i;
    }
    cout<<1<<' '<<save<<'\n';
}