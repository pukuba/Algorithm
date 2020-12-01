#include <bits/stdc++.h>

using namespace std;
bool check[52][52],_prev[52][52];
int n,m,_map[52][52],ans,temp,dx[4]={-1,0,1,0},dy[4]={0,-1,0,1},_max;
bool in(int a,int b){return 1<=a && a<=n && 1<=b && b<=m;}
void dfs(int y,int x,int height){
    if(check[y][x] || _prev[y][x] || y == 1 || y == n || x == 1 || x == m) temp-=1e6;
    if(temp < 0) return;
    _prev[y][x]=1;
    temp += height - _map[y][x];
    if(temp < 0 ) temp -= 1e6;
    for(int i=0; i<4; i++){
        int next_x = dx[i]+x;
        int next_y = dy[i]+y;
        if(!in(next_y,next_x)) continue;
        if(_map[next_y][next_x] < height && !_prev[next_y][next_x]) dfs(next_y,next_x,height);
    }
}
void prev_go(){
    for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) check[i][j] |= _prev[i][j];
}
int main(){
    cin>>n>>m;
    for(int i=1; i<=n; i++) for(int j=1; j<=m; j++){
        scanf("%1d",&_map[i][j]);
        _max = max(_max,_map[i][j]);
    }
    for(int i=2; i<=n-1; i++) for(int j=2; j<=m-1; j++){
        if(!check[i][j]){
            for(int k=9; k>=0; k--){
                if(_map[i][j]!=k){
                    memset(_prev,false,sizeof(_prev));
                    temp = 0;
                    dfs(i,j,k);
                    if(temp > 0){
                        ans += temp;
                        prev_go();
                        break;
                    }
                }
            }
        }
    }
    cout<<ans<<'\n';
}
