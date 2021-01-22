#include <bits/stdc++.h>

using namespace std;
int n,m,y,x,b[503],ans;
bool check[503];
vector<int> adj[503];
bool dfs(int here){
    check[here] = true;
    for(int next : adj[here]){
        if(b[next] == -1 || !check[b[next]] && dfs(b[next])){
            b[next] = here;
            return true;
        }
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    memset(b,-1,sizeof(b));
    cin>>n>>m;
    while(m--){
        cin>>y>>x;
        adj[y].push_back(x);
    }
    for(int i=1; i<=n; i++,memset(check,false,sizeof(check))) if(dfs(i)) ans++;
    cout<<ans;
}