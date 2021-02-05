#include <bits/stdc++.h>

using namespace std;
int t,n,m,a[1003],b[1003],ans;
bool check[1003];
vector<int> adj[1003];
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
        cin>>n>>m;
        memset(a,-1,sizeof(a));
        memset(b,-1,sizeof(b));
        ans = 0;
        for(int i=0; i<1003; i++) adj[i].clear();
        for(int i=1; i<=m; i++){
            int from,to;
            cin>>from>>to;
            for(;from<=to;from++) adj[i].push_back(from);
        }
        for(int i=1; i<=m; i++){
            if(a[i] == -1){
                memset(check,false,sizeof(check));
                if(dfs(i)) ans++;
            }
        }
        cout<<ans<<'\n';
    }
}