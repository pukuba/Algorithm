#include <bits/stdc++.h>

using namespace std;
int t,n,m,x,y,a[1003],b[1003],ans;
vector<int> adj[1003];
bool check[1003];
bool dfs(int here){
    check[here] = true;
    for(int next : adj[here]){
        if(b[next] == -1 || !check[b[next]] && dfs(b[next])){
            a[here] = next;
            b[next] = here;
            return true;
        }
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>t;
    while(t--){
        ans = 0;
        memset(a,-1,sizeof(a));
        memset(b,-1,sizeof(b));
        cin>>n>>m;
        for(int i=0; i<1003; i++) adj[i].clear();
        for(int i=1; i<=m; i++){
            cin>>x>>y;
            adj[x].push_back(y);
        }
        for(int i=0; i<n; i++){
            memset(check,false,sizeof(check));
            if(dfs(i)) ans++;
        }
        cout<<ans<<'\n';
    }
}