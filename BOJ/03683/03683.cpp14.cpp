#include <bits/stdc++.h>

using namespace std;
int t,b[555],n,m,k,ans;
vector<int> adj[555];
pair<string,string> p[555];
bool check[555];
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
    cin>>t;
    while(t--){
        cin>>n>>m>>k;
        ans = 0;
        memset(b,-1,sizeof(b));
        for(int i=0; i<=544; i++) adj[i].clear();
        for(int i=1; i<=k; i++) cin>>p[i].first>>p[i].second;
        for(int i=1; i<=k; i++) for(int j=i+1; j<=k; j++){
            if(p[i].first == p[j].second || p[i].second == p[j].first){
                if(p[i].first[0] == 'C') adj[i].push_back(j);
                else adj[j].push_back(i);
            }
        }
        for(int i=1; i<=k; i++){
            memset(check,false,sizeof(check));
            if(dfs(i)) ans++;
        } cout<<k-ans<<'\n';
    }
}