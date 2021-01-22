#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll mod = 1e9+9,n,m,ans;
char _map[3003][3003];
ll d[3003][3003];
ll f(int y,int x){
    if(y == n && x == m) return 1;
    if(y > n || x > m || y < 1 || x < 1) return 0;
    if(d[y][x] != - 1) return d[y][x];
    if(_map[y][x] == 'E') return d[y][x] = f(y,x+1) % mod;
    if(_map[y][x] == 'S') return d[y][x] = f(y+1,x) % mod;
    return d[y][x] = (f(y,x+1)) + (f(y+1,x)) % mod;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    memset(d,-1,sizeof(d));
    cin>>n>>m;
    for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) cin>>_map[i][j];
    for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) ans+=f(i,j)%mod;
    cout<<ans%mod;
}