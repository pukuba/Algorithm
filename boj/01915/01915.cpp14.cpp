#include <bits/stdc++.h>

using namespace std;
int d[1003][1003],n,m,ans;
char c;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1; i<=n; i++) for(int j=1; j<=m; j++){
        cin>>c;
        if(c=='1') d[i][j] = 1;
    }
    for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) if(d[i][j] == 1) d[i][j] = min({d[i-1][j],d[i][j-1],d[i-1][j-1]})+1;
    for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) ans = max(ans,d[i][j]);
    cout<<ans*ans;
}