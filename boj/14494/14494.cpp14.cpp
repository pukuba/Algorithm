#include <bits/stdc++.h>

using namespace std;
long long d[1001][1001];
int n,m;
const int mod = 1e9+7;
long long dfs(int y,int x){
    if(y==n && x == m) return 1;
    if(y > n || x > m) return 0;
    long long &ret = d[y][x];
    if(ret != -1) return ret;
    ret = dfs(y+1,x)+dfs(y+1,x+1)+dfs(y,x+1);
    ret %=mod;
    return ret;
}
int main(){
    memset(d,-1,sizeof(d));
    cin>>n>>m;
    cout<<dfs(1,1)%mod<<'\n';
}
