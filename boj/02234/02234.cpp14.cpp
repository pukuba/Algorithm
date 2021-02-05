#include <bits/stdc++.h>

using namespace std;

int n,m,_map[51][51],dy[4]={0,-1,0,1},dx[4]={-1,0,1,0},cnt = 1,ans1,ans2,comSize[2501];
int check[51][51];
bool in(int a,int b){
    return (1<=a && a<=n && 1<=b && b<=m);
}
int dfs(int y,int x){
    if(check[y][x]) return 0;
    check[y][x] = cnt;
    int ret = 1;
    for(int i=0; i<4; i++){
        if(_map[y][x] & (1<<i)) continue;
        int next_x=x+dx[i];
        int next_y=y+dy[i];
        if(!in(next_y,next_x)) continue;
        ret += dfs(next_y,next_x);
    }
    return ret;
}
int main(){
    cin>>m>>n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin>>_map[i][j];
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(!check[i][j]){
                int comp = dfs(i, j);
                comSize[cnt] = comp;
                ans1 = max(comp, ans1);
                cnt++;
            }
        }
    }
    int ans3=0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<m; j++) if(check[i][j]!=check[i][j+1]) ans3=max(ans3,comSize[check[i][j]]+comSize[check[i][j+1]]);
    }
    for(int i=1; i<n; i++){
        for(int j=1; j<=m; j++){
            if(check[i-1][j]!=check[i][j]) ans3=max(ans3,comSize[check[i-1][j]]+comSize[check[i][j]]);
        }
    }
    cout<<cnt-1<<'\n';
    cout<<ans1<<'\n';
    cout<<ans3<<'\n';
    
}
