#include <bits/stdc++.h>

using namespace std;
char _map[51][51];
int n,m,ans;
bool in(int a,int b){
    return (1<=a && a<=n && 1<=b && b<=m);
}
int dfs(int y,int x,int cnt){
    int ret=0;
    if(!in(y+cnt,x+cnt)) return 0;
    if(_map[y][x]==_map[y+cnt][x] && _map[y][x]==_map[y][x+cnt] && _map[y+cnt][x+cnt]==_map[y][x]){
        return (cnt+1)*(cnt+1);
    }
    return 0;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) cin>>_map[i][j];
    for(int i=0; i<n; i++){
        for(int j=1; j<=n; j++){
            for(int k=1; k<=m; k++){
                ans=max(dfs(j,k,i),ans);
            }
        }
    }
    cout<<ans<<'\n';
}
