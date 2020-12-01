#include <bits/stdc++.h>

using namespace std;
int n,m,_map[105][105],dx[4]={-1,0,1,0},dy[4]={0,1,0,-1},max_height,ans;
bool in(int a,int b){return 0<=a && a<=n+1 && 0<=b && b<=m+1;}
void bfs(int height){
    queue<pair<int,int> > q;
    q.push({0,0});
    while(q.size()){
        auto[here_y,here_x] = q.front();
        q.pop();
        for(int i=0; i<4; i++){
            int next_y = here_y + dy[i];
            int next_x = here_x + dx[i];
            if(!in(next_y,next_x)) continue;
            if(_map[next_y][next_x] < height){
                _map[next_y][next_x] = height;
                q.push({next_y,next_x});
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1; i<=n; i++) for(int j=1; j<=m; j++){
        cin>>_map[i][j];
        max_height = max(max_height,_map[i][j]);
    }
    for(int k=1; k<=max_height; k++){
        bfs(k);
        for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) if(_map[i][j] < k) _map[i][j]++,ans++;
    }cout<<ans;
}