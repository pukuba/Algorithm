#include <bits/stdc++.h>

using namespace std;
int parent[505050],n,m,ans;
int find(int x){
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}
int merge(int x,int y){
    return parent[find(x)] = find(y);
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    for(int i=1; i<=505000; i++) parent[i] = i;
    cin>>n>>m;
    for(int i=1,x,y; i<=m; i++) {
        cin>>x>>y;
        if(find(x) == find(y) && !ans) ans = i;
        merge(x,y);
    }
    cout<<ans<<'\n';
}
