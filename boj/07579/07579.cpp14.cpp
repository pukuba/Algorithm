#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll n,m,a[111],b[111],d[122][22222],ans;
ll f(ll x,ll y){
    if(y < 0) return -1e12;
    if(x > n) return 0;
    if(d[x][y] != -1) return d[x][y];
    return d[x][y] = max(f(x+1,y-b[x])+a[x],f(x+1,y));
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1; i<=n; i++) cin>>a[i];
    for(int i=1; i<=n; i++) cin>>b[i];
    memset(d,-1,sizeof d);
    while(1){
        if(f(1,ans) >= m){
            cout<<ans<<'\n';
            return 0;
        }
        ans++;
    }
}