#include <bits/stdc++.h>

using namespace std;
int n,m,k,b[1003],p[1003],q[1003],ans1,ans2,cnt;
bool check[1003];
vector<int> adj[1003];
bool dfs(int here){
    check[here] = true;
    for(int next : adj[here]){
        if(b[next] == -1 || !check[b[next]] && dfs(b[next])){
            p[here] = next;
            b[next] = here;
            return true;
        }
    }
    return false;
}
bool dfs1(int here){
    check[here] = true;
    for(int next : adj[here]){
        if(b[next] == -1 || !check[b[next]] && dfs(b[next])){
            q[here] = next;
            b[next] = here;
            return true;
        }
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    memset(p,-1,sizeof(p));
    memset(q,-1,sizeof(q));
    memset(b,-1,sizeof(b));
    cin>>n>>m>>k;
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
        if(p[i] == -1){
            memset(check,false,sizeof(check));
            if(dfs(i)) ans1++;
        }
    }
    for(int i=1; i<=n; i++){
        if(cnt == k) break;
        if(q[i] == -1){
            memset(check,false,sizeof(check));
            if(dfs1(i)) ans2++,cnt++;
        }
    }
    cout<<ans1+ans2<<'\n';
}