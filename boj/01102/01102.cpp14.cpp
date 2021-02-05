#include <bits/stdc++.h>

using namespace std;
int n,inf=1e9,a[17][17],d[1<<17],k,start,ans=inf;
string s;
int dfs(int check){
    int cnt = __builtin_popcount(check);
    if(cnt >= k) return 0;
    int &ret = d[check];
    if(ret != -1) return ret;
    ret = inf;
    for(int i=0; i<n; i++){
        if(check&(1<<i)){
            for(int j=1; j<=n; j++){
                if(check & (1<<(j-1))) continue;
                ret = min(ret,dfs(check | (1<<(j-1)))+a[i+1][j]);
            }
        }
    }
    return ret;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    memset(d,-1,sizeof(d));
    cin>>n;
    for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) cin>>a[i][j];
    cin>>s>>k;
    for(int i=0; i<s.size(); i++) if(s[i]=='Y') start |= (1<<i);
    ans = dfs(start);
    if(ans == inf) cout<<-1;
    else cout<<ans;
}
