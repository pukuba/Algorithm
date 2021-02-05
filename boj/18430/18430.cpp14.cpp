#include <bits/stdc++.h>

using namespace std;
int _map[22][22],n,m,ans,temp,dx[4]={1,-1,1,-1},dy[4]={1,1,-1,-1};
bool check[22][22];
bool in(int y,int x){
    if(check[y][x]) return false;
    return 1<=y && y<=n && 1<=x&& x<=m;
}
void f(int y,int x,int s){
    if(x == m+1){
        f(y+1,1,s);
        return;
    }
    if(y == n+1){
        ans = max(ans,s);
        return ;
    }
    for(int i=0; i<4; i++){
        if(in(y,x) && in(y+dy[i],x) && in(y,x+dx[i])){
            check[y][x] = check[y+dy[i]][x] = check[y][x+dx[i]] = 1;
            s += _map[y][x] * 2 + _map[y+dy[i]][x] + _map[y][x+dx[i]];
            f(y,x+1,s);
            s -= _map[y][x] * 2 + _map[y+dy[i]][x] + _map[y][x+dx[i]];
            check[y][x] = check[y+dy[i]][x] = check[y][x+dx[i]] = 0;
        }
    }
    f(y,x+1,s);
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) cin>>_map[i][j];
    f(1,1,0);
    cout<<ans<<'\n';
}