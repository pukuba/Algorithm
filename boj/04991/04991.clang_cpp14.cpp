#include <bits/stdc++.h>

using namespace std;
struct pos{int y,x,cnt,status;};
int n,m,sy,sx,ids[22][22],id,dx[4]={0,-1,0,1},dy[4]={-1,0,1,0};
char _map[22][22];
bool check[22][22][1<<10];
bool in(int a,int b){return 1<=a && a<=n && 1<=b && b<=m;}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    while(1){
        bool ans = false;
        cin>>m>>n;
        id = -1;
        if(m==n && n==0) return 0;
        memset(_map,0,sizeof(_map));
        memset(ids,0,sizeof(ids));
        memset(check,0,sizeof(check));
        for(int i=1; i<=n; i++) for(int j=1; j<=m; j++){
            cin>>_map[i][j];
            if(_map[i][j] == 'o'){
                sy = i; sx = j;
                _map[i][j] = '.';
            }
            if(_map[i][j] == '*') ids[i][j] = ++id;
        }
        id++;
        queue<pos> q;
        q.push({sy,sx,0,0});
        check[sy][sx][0] = 1;
        while(q.size()){
            auto[here_y,here_x,dist,stat] = q.front();
            if(stat == (1<<(id))-1){
                ans = true;
                cout<<dist<<'\n';
                break;
            }
            q.pop();
            for(int i=0; i<4; i++){
                int next_y = here_y + dy[i], next_x = here_x + dx[i];
                if(!in(next_y,next_x) || check[next_y][next_x][stat] || _map[next_y][next_x]=='x') continue;
                if(_map[next_y][next_x] == '.'){
                    q.push({next_y,next_x,dist+1,stat});
                    check[next_y][next_x][stat] = 1;
                }
                if(_map[next_y][next_x] == '*'){
                    check[next_y][next_x][stat] = check[next_y][next_x][stat | (1<<ids[next_y][next_x])] = 1;
                    q.push({next_y,next_x,dist+1,stat|(1<<ids[next_y][next_x])});
                }
            }
        }
        if(!ans) cout<<-1<<'\n';
    }
}