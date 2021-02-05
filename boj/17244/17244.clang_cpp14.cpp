#include <bits/stdc++.h>

using namespace std;
int n,m,cnt,sy,sx,dy[4]={0,-1,0,1},dx[4]={1,0,-1,0},ans=1e9;
pair<int,int> p[6],temp[6];
char _map[55][55];
bool check[55][55][6];
vector<int> adj;
struct pos{int y,x,dist,level;};
bool in(int a,int b){return 1<=a && a<=n && 1<=b && b<=m;}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>m>>n;
    for(int i=1; i<=n; i++) for(int j=1; j<=m; j++){
        cin>>_map[i][j];
        if(_map[i][j] == 'X') p[++cnt]={i,j},adj.push_back(cnt);
        if(_map[i][j] == 'S') sy=i,sx=j;
    }
    do{
        memset(check,false,sizeof(check));
        for(int i=1; i<=cnt; i++) _map[p[i].first][p[i].second] = 'X';
        queue<pos> q;
        q.push({sy,sx,0,1});
        check[sy][sx][1] = 1;
        for(int i=0; i<adj.size(); i++) temp[i+1] = p[adj[i]];
        while(q.size()){
            auto[here_y,here_x,cnts,lv] = q.front();
            q.pop();
            for(int i=0; i<4; i++){
                int next_y = here_y + dy[i],next_x = here_x + dx[i];
                if(!in(next_y,next_x) || check[next_y][next_x][lv] || _map[next_y][next_x]=='#') continue;
                if(temp[lv].first == next_y && temp[lv].second == next_x){
                    check[next_y][next_x][lv] = check[next_y][next_x][lv+1] = 1;
                    _map[next_y][next_x] = '.';
                    q.push({next_y,next_x,cnts+1,lv+1});
                }
                else if(_map[next_y][next_x]=='E' && lv == cnt+1){
                    ans = min(ans,cnts+1);
                    check[next_y][next_x][lv] = 1;
                }
                else if(_map[next_y][next_x]=='.' || _map[next_y][next_x]=='S'){
                    check[next_y][next_x][lv] = 1;
                    q.push({next_y,next_x,cnts+1,lv});
                }
            }
        }
    }while(next_permutation(adj.begin(), adj.end()));
    cout<<ans<<'\n';
}