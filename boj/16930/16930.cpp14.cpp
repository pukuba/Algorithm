#include <bits/stdc++.h>

using namespace std;
int n,m,k,sx,sy,ex,ey,dist[1006][1006],dx[4]={0,-1,0,1},dy[4]={1,0,-1,0};
char _map[1006][1006];
queue<pair<int,int> > q;
bool in(int a,int b){return 1<=a && a<=n && 1<=b && b<=m;}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>n>>m>>k;
    for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) cin>>_map[i][j];
    cin>>sy>>sx>>ey>>ex;
    dist[sy][sx] = 1;
    q.push({sy,sx});
    while(q.size()){
        auto[here_y,here_x] = q.front();
        q.pop();
        if(here_y == ey && here_x == ex){
            cout<<dist[here_y][here_x] - 1;
            return 0;
        }
        for(int i=0; i<4; i++){
            for(int j=1; j<=k; j++){
                int next_y = dy[i] * j + here_y;
                int next_x = dx[i] * j + here_x;
                if(!in(next_y,next_x) || _map[next_y][next_x] == '#' || (dist[next_y][next_x] && dist[here_y][here_x] >= dist[next_y][next_x])) break;
                if(!dist[next_y][next_x]){
                    q.push({next_y,next_x});
                    dist[next_y][next_x] = dist[here_y][here_x] + 1;
                }
            }
        }
    }
    cout<<-1;
}