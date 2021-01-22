#include <bits/stdc++.h>

using namespace std;
char _map[21][21];
bool check[26];
int dx[4]={1,0,-1,0},dy[4]={0,-1,0,1},n,m;
bool in(int a,int b){ return 1<=a && a<=n && 1<=b && b<=m; }
int dfs(int y,int x){
    if(!in(y,x)) return 0;
    if(check[(_map[y][x]-'A')]) return 0;
    check[(_map[y][x]-'A')]=true;
    int ans=0;
    for(int i=0; i<4; i++){
        int next_x=x+dx[i];
        int next_y=y+dy[i];
        ans=max(ans,dfs(next_y,next_x)+1);
    }
    check[(_map[y][x]-'A')]=false;
    return ans;
}
int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) cin>>_map[i][j];
    cout<<dfs(1,1)<<'\n';
}
