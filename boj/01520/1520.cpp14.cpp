#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int _map[555][555],n,m,d[555][555],dx[4]={0,1,0,-1},dy[4]={1,0,-1,0},check[555][555];
bool in(int a,int b){return 1<=a && a<=n && 1<=b && b<=m;}
int f(int y,int x){
    if(!in(y,x) ) return 0;
    if(y==n && x==m) return 1;
    if(d[y][x] != -1) return d[y][x];
    d[y][x] = 0;
    for(int i=0; i<4; i++){
        int next_y = dy[i] + y, next_x = dx[i] + x;
        if(!check[next_y][next_x] && _map[y][x] > _map[next_y][next_x]) {
            check[next_y][next_x] = 1;
            d[y][x] += f(next_y,next_x);
            check[next_y][next_x] = 0;
        }
    }
    return d[y][x];
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    memset(d,-1,sizeof(d));
    cin>>n>>m;
    for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) cin>>_map[i][j];
    check[1][1] = 1;
    cout<<f(1,1);
}