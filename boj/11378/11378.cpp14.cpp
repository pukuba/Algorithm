#include <bits/stdc++.h>

using namespace std;
int n,m,k,a[1004],b[1004],x,y,ans;
vector<int> adj[1004];
bool check[1004];
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
    memset(a,-1,sizeof(a));
    memset(b,-1,sizeof(b));
    cin>>n>>m>>k;
    for(int i=1; i<=n; i++){
        cin>>x;
        while(x--){
            cin>>y;
            adj[i].push_back(y);
        }
    }
    for(int i=1; i<=n; i++){
        memset(check,false,sizeof(check));
        if(dfs(i)) ans++;
    }
    for(int i=1; i<=n && k;){
        memset(check,false,sizeof(check));
        if(dfs(i)) ans++,k--;
        else i++;
    } cout<<ans;
}