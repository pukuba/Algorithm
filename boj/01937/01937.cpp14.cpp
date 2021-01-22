#include <bits/stdc++.h>

using namespace std;
int n,d[504][504],_map[504][504],dx[4]={-1,0,1,0},dy[4]={0,-1,0,1},_max;
bool in(int a,int b){ return 1<=a && a<=n && 1<=b && b<=n; }
int dfs(int y,int x){
    if(d[y][x]!=-1) return d[y][x];
    int &ret = d[y][x];
    ret=0;
    for(int i=0; i<4; i++){
        int next_x=x+dx[i];
        int next_y=y+dy[i];
        if(_map[next_y][next_x]>_map[y][x] && in(next_y,next_x)) ret=max(ret,dfs(next_y,next_x)+1);
    }
    return ret;
}
int main(){
    cin>>n;
    memset(d,-1,sizeof(d));
    for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) cin>>_map[i][j];
    for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) _max=max(_max,dfs(i,j));
    cout<<_max+1<<'\n';
}
