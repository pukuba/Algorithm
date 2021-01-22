#include <bits/stdc++.h>

using namespace std;
int d[1001][1001][3],dx[3]={1,-1,0},dy[3]={0,0,1},n,m;
short _map[1001][1001];
bool check[1001][1001];
bool in(int a,int b){return 1<=a && a<=n && 1<=b && b<=m;}
int f(int y,int x,int type){
    if(y==n && x==m) return _map[y][x];
    if(d[y][x][type] != -1) return d[y][x][type];
    d[y][x][type] = -1e9;
    for(int i=0; i<3; i++){
        int next_x = dx[i] + x;
        int next_y = dy[i] + y;
        if(!in(next_y,next_x) || check[next_y][next_x]) continue;
        check[next_y][next_x] = 1;
        d[y][x][type] = max(d[y][x][type],f(next_y,next_x,i)+_map[y][x]);
        check[next_y][next_x] = 0;
    }
    return d[y][x][type];
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    check[1][1] = true;
    memset(d,-1,sizeof(d));
    cin>>n>>m;
    for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) cin>>_map[i][j];
    cout<<f(1,1,0);
}