#include <bits/stdc++.h>

using namespace std;
char _map[15][15];
int n,m,ans[15][15],dx[4]={-1,1,0,0},dy[4]={0,0,-1,1},l=99,r,u=99,d;
int search(char c,int y,int x){
    if(c=='.') return 0;
    int cnt=0;
    for(int i=0; i<4; i++) if(_map[y+dy[i]][x+dx[i]]=='.') cnt++;
    return 3<=cnt?0:1;
}
int main(){
    cin>>n>>m;
    for(int i=0; i<15; i++) for(int j=0; j<15; j++) _map[i][j]='.';
    for(int i=2; i<2+n; i++) for(int j=2; j<2+m; j++) cin>>_map[i][j];
    for(int i=2; i<2+n; i++) for(int j=2; j<2+m; j++) ans[i][j]=search(_map[i][j],i,j);
    for(int i=2; i<2+n; i++) for(int j=2; j<2+m; j++) if(ans[i][j]) l=min(l,j),r=max(r,j),u=min(u,i),d=max(d,i);
    for(int i=u; i<=d; i++){
        for(int j=l; j<=r; j++) printf("%c",ans[i][j]?'X':'.');
        printf("\n");
    }
}
