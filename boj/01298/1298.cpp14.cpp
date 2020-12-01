#include <bits/stdc++.h>

using namespace std;
int a[5033],b[5033],n,m,ans;
bool check[5033];
vector<int> adj[5033];
bool dfs(int here){
    check[here] = true;
    for(int next : adj[here]){
        if(b[next] == -1 || (!check[b[next]] && dfs(b[next]))){
            a[here]=next;
            b[next]=here;
            return true;
        }
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    memset(a,-1,sizeof(a));
    memset(b,-1,sizeof(b));
    cin>>n>>m;
    while(m--){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
    }
    for(int i=1; i<=n; i++){
        if(a[i] == -1){
            memset(check,false,sizeof(check));
            if(dfs(i)) ans++;
        }
    } cout<<ans;
}