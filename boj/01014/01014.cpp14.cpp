#include <bits/stdc++.h>

using namespace std;
int t,n,m,dp[11][1<<10],ans;
char _map[11][11];
int f(int here_y,int here_check,int prev_check){
    int ret = 0;
    for(int i=1; i<=m; i++){
        if(!(here_check & ((1<<(i - 1))))) continue;
        if(_map[here_y][i] == 'x') return 0;
        if(i>=2) if((here_check & (1<<(i-2))) || (prev_check & (1<<(i-2)))) return 0;
        if((here_check & (1<<i)) || (prev_check & (1<<i))) return 0;
        ret++;
    }
    return ret;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>t;
    while(t--){
        ans=0;
        memset(_map,false,sizeof(_map));
        memset(dp,false,sizeof(dp));
        cin>>n>>m;
        for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) cin>>_map[i][j];
        for(int i=1; i<=n; i++) for(int j=0; j<(1<<m); j++) for(int k=0; k<(1<<m); k++) ans=max(dp[i][j] = max(dp[i][j],dp[i-1][k]+f(i,j,k)),ans);
        cout<<ans<<'\n';
    }
}