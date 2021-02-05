#include <bits/stdc++.h>

using namespace std;
int n,m,k1,k2,x,y,b[555],c[555],ans1,ans2;
bool check[555];
vector<int> adj[555],adj2[555];
bool dfs1(int here){
    check[here] = true;
    for(int next : adj[here]){
        if(b[next] == -1 || !check[b[next]] && dfs1(b[next])){
            b[next] = here;
            return true;
        }
    }
    return false;
}
bool dfs2(int here){
    check[here] = true;
    for(int next : adj2[here]){
        if(c[next] == -1 || !check[c[next]] && dfs2(c[next])){
            c[next] = here;
            return true;
        }
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    memset(b,-1,sizeof(b));
    memset(c,-1,sizeof(c));
    cin>>n>>m>>k1>>k2;
    for(int i=1; i<=k1; i++){
        cin>>x>>y;
        adj[x].push_back(y);
    }
    for(int i=1; i<=k2; i++){
        cin>>x>>y;
        adj2[x].push_back(y);
    }
    for(int i=1; i<=n; i++){
        memset(check,false,sizeof(check));
        if(dfs1(i)) ans1++;
        memset(check,false,sizeof(check));
        if(dfs2(i)) ans2++;
    }
    if(ans1 < ans2) cout<<"네 다음 힐딱이";
    else cout<<"그만 알아보자";
}