#include <bits/stdc++.h>

using namespace std;
int n,m,ans=1e9,cnt,dx[9]={-1,0,1,-1,0,1,-1,0,1},dy[9]={-1,-1,-1,0,0,0,1,1,1};
char _map[11][11],temp[11][11];
bool in(int a,int b){return 1<=a && a<=n && 1<=b && b<=m;}
bool check(){for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) if(temp[i][j]=='.') return 0;return 1;}
void turn(int y,int x){
    ++cnt;
    for(int i=0; i<9; i++) if(in(y+dy[i],x+dx[i])) temp[y+dy[i]][x+dx[i]] = temp[y+dy[i]][x+dx[i]] == '*' ? '.' : '*';
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) cin>>_map[i][j];
    for(int u=0; u<=(1<<m)-1; u++){
        for(int l=0; l<=(1<<n)-1; l++,cnt=0){
            for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) temp[i][j] = _map[i][j];
            for(int i=0; i<n; i++) if(l&(1<<i)) turn(i+1,1);
            for(int i=0; i<m; i++) if(u&(1<<i)) turn(1,i+1);
            for(int i=2; i<=n; i++) for(int j=2; j<=m; j++) if(temp[i-1][j-1] == '.') turn(i,j);
            if(check()) ans = min(ans,cnt);
        }
    }
    cout<<(ans==1e9 ? -1 : ans);
}