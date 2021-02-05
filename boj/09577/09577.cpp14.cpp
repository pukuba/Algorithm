#include <bits/stdc++.h>

using namespace std;
int t,n,m,b[111],ans;
vector<int> adj[111];
bool check[111];
bool dfs(int here){
    check[here] = true;
    for(int next : adj[here]){
        if(b[next] == -1 || !check[b[next]] && dfs(b[next])){
            b[next] = next;
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
        cin>>n>>m;
        memset(b,-1,sizeof(b));
        for(int i=0; i<=102; i++) adj[i].clear();
        for(int i=1; i<=m; i++){
            int f,s,k;
            cin>>f>>s>>k;
            while(k--){
                int x;
                cin>>x;
                for(int j=f+1; j<=s; j++) adj[j].push_back(x);
            }
        }
        for(int i=0; i<=101; i++){
            memset(check,false,sizeof(check));
            if(dfs(i)) ans++;
            if(ans == n){
                cout<<i<<'\n';
                break;
            }
            if(i == 101){
                cout<<-1<<'\n';
                break;
            }
        }
    }
}