#include <bits/stdc++.h>

using namespace std;
char _map[11][11][1111];
struct info{int y,x,r;};
bool check[10][10][1111];
int dx[9]={0,1,0,-1,-1,-1,1,1,0},dy[9]={-1,0,1,0,1,-1,-1,1,0};
queue<info> q;
void dfs(int x){
    if(x > 9) return;
    for(int i=1; i<=8; i++){
        for(int j=1; j<=8; j++){
            if(_map[i][j][x] == '#') _map[i+1][j][x+1] = '#';
        }
    }
    dfs(x+1);
}
bool in(int a,int b){return 1<=a && a<=8 && 1<=b && b<=8;}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    for(int i=1; i<=8; i++) for(int j=1; j<=8; j++) cin>>_map[i][j][0];
    dfs(0);
    q.push({8,1,0});
    check[1][1][0] = true;
    if(_map[1][1][0] == '#' && _map[1][1][1] == '#'){
        cout<<0;
        return 0;
    }
    while(q.size()){
        auto[here_y,here_x,round] = q.front();
        if(round > 777){
            cout<<1<<'\n';
            return 0;
        }
        if(here_y == 1 && here_x == 8){
            cout<<1<<'\n';
            return 0;
        }
        q.pop();
        for(int i=0; i<9; i++){
            int next_x = here_x + dx[i];
            int next_y = here_y + dy[i];
            if(!in(next_y,next_x)) continue;
            if(!check[next_y][next_x][round+1] && _map[next_y][next_x][round] != '#' && _map[next_y][next_x][round+1] != '#'){
                check[next_y][next_x][round+1] = true;
                q.push({next_y,next_x,round+1});
            }
        }
    }
    cout<<0;
}