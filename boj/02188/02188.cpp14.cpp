#include <bits/stdc++.h>

using namespace std;
int n,m,a[205],b[205],ans;
bool check[205];
vector<int> adj[205];
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
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        for(int j=1; j<=x; j++){
            int y;
            cin>>y;
            adj[i].push_back(y);
        }
    }
    memset(a,-1,sizeof(a));
    memset(b,-1,sizeof(b));
    for(int i=1; i<=n; i++){
        if(a[i] == -1){
            memset(check,false,sizeof(check));
            if(dfs(i)) ans++;
        }
    } cout<<ans;
}