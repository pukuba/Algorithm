#include <bits/stdc++.h>

using namespace std;
int dx[3]={1,0,1},dy[3]={0,1,1},n,d[18][18][4];
bool _map[17][17];
bool in(int a,int b){return 1<=a && a<=n && 1<=b && b<=n;}
int f(int y,int x,int type){
    if(y == n && x == n) return 1;
    if(d[y][x][type] != -1) return d[y][x][type];
    d[y][x][type] = 0;
    for(int i=0; i<3; i++){
        if((type == 1 && i == 1) || (type == 2 && i == 0)) continue;
        int next_x = x + dx[i];
        int next_y = y + dy[i];
        if(!in(next_y,next_x)) continue;
        if(_map[next_y][next_x]) continue;
        if(i == 2) if(_map[y][next_x] || _map[next_y][x]) continue;
        d[y][x][type] += f(next_y,next_x,i+1);
    }
    return d[y][x][type];
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    memset(d,-1,sizeof(d));
    cin>>n;
    for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) cin>>_map[i][j];
    cout<<f(1,2,1);
}