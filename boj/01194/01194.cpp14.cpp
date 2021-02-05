#include <bits/stdc++.h>

using namespace std;
bool check[51][51][1<<7];
int n,m,sx,sy,dx[4]={0,-1,0,1},dy[4]={1,0,-1,0};
char _map[51][51];
queue<tuple<int,int,int,int>> q;
bool in(int a,int b){return 1<=a && a<=n && 1<=b && b<=m;}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1; i<=n; i++) for(int j=1; j<=m; j++){
        cin>>_map[i][j];
        if(_map[i][j] == '0'){
            sy=i;
            sx=j;
            _map[i][j]='.';
        }
    }
    q.push({sy,sx,0,0});
    check[sy][sx][0]=true;
    while(!q.empty()){
        auto[here_y,here_x,here_key,cnt] = q.front();
        q.pop();
        if(_map[here_y][here_x] == '1'){
            cout<<cnt<<'\n';
            return 0;
        }
        for(int i=0; i<4; i++){
            int next_x = dx[i]+here_x;
            int next_y = dy[i]+here_y;
            if(!in(next_y,next_x)) continue;
            if('f'>= _map[next_y][next_x] && _map[next_y][next_x] >= 'a'){
                if(check[next_y][next_x][here_key] == true) continue;
                check[next_y][next_x][here_key] = 1;
                check[next_y][next_x][here_key | (1<<(_map[next_y][next_x]-'a'))] = 1;
                q.push({next_y,next_x,here_key | (1<<(_map[next_y][next_x]-'a')),cnt+1});
            }
            if('A'<=_map[next_y][next_x] && _map[next_y][next_x] <='F'){
                if(here_key & (1<<(_map[next_y][next_x]-'A'))){
                    if(check[next_y][next_x][here_key] == true) continue;
                    check[next_y][next_x][here_key] = 1;
                    q.push({next_y,next_x,here_key,cnt+1});
                }
            }
            if(_map[next_y][next_x] == '#') continue;
            if(_map[next_y][next_x] == '.' || _map[next_y][next_x] == '1'){
                if(check[next_y][next_x][here_key] == 1) continue;
                check[next_y][next_x][here_key] = 1;
                q.push({next_y,next_x,here_key,cnt+1});
            }
        }
    }
    cout<<-1;
}
