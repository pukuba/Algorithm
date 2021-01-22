#include <bits/stdc++.h>

using namespace std;
int a1[1001],a2[1001],b[1001],ans,n,m;
bool check[1001];
vector<int> adj[1003];
bool dfs1(int here){
    check[here] = true;
    for(int next : adj[here]){
        if(b[next] == -1 || !check[b[next]] && dfs1(b[next])){
            a1[here] = next;
            b[next] = here;
            return true;
        }
    }
    return false;
}
bool dfs2(int here){
    check[here] = true;
    for(int next : adj[here]){
        if(b[next] == -1 || !check[b[next]] && dfs2(b[next])){
            a2[here] = next;
            b[next] = here;
            return true;
        }
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>n>>m;
    memset(a1,-1,sizeof(a1));
    memset(a2,-1,sizeof(a2));
    memset(b,-1,sizeof(b));
    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        while(x--){
            int y;
            cin>>y;
            adj[i].push_back(y);
        }
    }
    for(int i=1; i<=n; i++){
        if(a1[i] == -1){
            memset(check,false,sizeof(check));
            if(dfs1(i)) ans++;
        }
        if(a2[i] == -1){
            memset(check,false,sizeof(check));
            if(dfs2(i)) ans++;
        }
    } cout<<ans;
}