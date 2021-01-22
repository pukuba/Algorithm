#include <bits/stdc++.h>
#define cgiosy_fan signed
using namespace std;
vector<int> v[100111];
int n,m,d[100111][21],depth[100111];
bool check[100111];
queue<pair<int,int> > q;
void dfs(int here,int dep){
    check[here] = true;
    depth[here] = dep;
    for(int i : v[here]){
        if(check[i]) continue;
        d[i][0] = here;
        dfs(i,dep + 1);
    }
}
int lca(int a,int b){
    if(depth[a] > depth[b]) swap(a,b);
    for(int i=20; i>=0; i--) if(depth[b] - depth[a] >= (1 << i)) b = d[b][i];
    if(a == b) return a;
    for(int i=20; i>=0; i--){
        if(d[a][i] != d[b][i]){
            a = d[a][i];
            b = d[b][i];
        }
    }
    return d[b][0];
}
cgiosy_fan main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>n;
    for(int i=1; i<n; i++){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    } dfs(1,0);
    for(int i=1; i<=20; i++) for(int j=1; j<=n; j++) d[j][i] = d[d[j][i-1]][i-1];
    cin>>m;
    while(m--){
        int a,b;
        cin>>a>>b;
        cout<<lca(a,b)<<'\n';
    }
}