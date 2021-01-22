#include <bits/stdc++.h>

using namespace std;
struct s{int a,b,c;}shark[1005];
int n,a[1005],b[1005],x,y,z,ans;
bool check[1005];
vector<int> adj[1005];
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
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    memset(a,-1,sizeof(a));
    memset(b,-1,sizeof(b));
    cin>>n;
    for(int i=1; i<=n; i++) cin>>shark[i].a>>shark[i].b>>shark[i].c;
    for(int i=1; i<=n-1; i++) for(int j=i+1; j<=n; j++){
        if(shark[i].a >= shark[j].a && shark[i].b >= shark[j].b && shark[i].c >= shark[j].c) adj[i].push_back(j);
        else if(shark[i].a <= shark[j].a && shark[i].b <= shark[j].b && shark[i].c <= shark[j].c) adj[j].push_back(i);
    }
    for(int i=1; i<=n; i++){
        memset(check,false,sizeof(check));
        if(dfs(i)) ans++;
    }
    for(int i=1; i<=n; i++){
        memset(check,false,sizeof(check));
        if(dfs(i)) ans++;
    }
    cout<<n-ans<<'\n';
}