#include <bits/stdc++.h>

using namespace std;
bool check[6][6];
char _map[6][6];
int n,m,r,dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};
bool in(int a,int b){return 1<=a && a<=n && 1<=b && b<=m;}
int dfs(int y,int x,int k){
    if(y == 1 && x == m && k == r) return 1;
    if(y == 1 && x == m) return 0; 
    int ret = 0;
    check[y][x] = true;
    for(int i=0; i<4; i++){
        int next_x = x + dx[i];
        int next_y = y + dy[i];
        if(!in(next_y,next_x) || check[next_y][next_x] || _map[next_y][next_x] == 'T' || k >= r) continue;
        ret += dfs(next_y,next_x,k+1);
    }
    check[y][x] = false;
    return ret;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>n>>m>>r;
    for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) cin>>_map[i][j];
    cout<<dfs(n,1,1);
}