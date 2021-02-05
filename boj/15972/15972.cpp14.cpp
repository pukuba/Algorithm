#include <bits/stdc++.h>

using namespace std;
int n,m,h,height[1006][1006],_map[1005][1005][4],dx[4]={0,1,0,-1},dy[4]={-1,0,1,0};
typedef tuple<int,int,int> ppp;
priority_queue<ppp,vector<ppp>,greater<ppp>> pq;
bool in(int a,int b){return 1<=a && a<=n && 1<=b && b<=m;}
void enqueue(int y, int x, int h){
    if(height[y][x] > h){   
        height[y][x] = h;
        pq.push({h,y,x});
    }
    return;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>n>>m>>h;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            height[i][j] = h;
        }
    }
    for(int i=1; i<=n+1; i++){
        for(int j=1; j<=m; j++){
            int x;
            cin>>x;
            _map[i][j][0]=x;
            _map[i-1][j][2]=x;
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m+1; j++){
            int x;
            cin>>x;
            _map[i][j-1][1]=x;
            _map[i][j][3]=x;
        }
    }
    // 가장자리에 있는 hole을 통해 최소값을 잡는다.
    for(int i = 0; i <= n + 1; i++){
        //가장 왼쪽, 오른쪽 확인
        if(_map[i][0][1] != -1) enqueue(i, 1, _map[i][0][1]);
        if(_map[i][m + 1][3] != -1) enqueue(i, m, _map[i][m + 1][3]);
    }

    for(int i = 0; i <= m + 1; i++){
        //가장 위쪽, 아래쪽 확인
        if(_map[0][i][2] != -1) enqueue(1, i, _map[0][i][2]);
        if(_map[n + 1][i][0] != -1) enqueue(n, i, _map[n + 1][i][0]);
    }
    while(pq.size()){
        auto[here_dist,here_y,here_x] = pq.top();
        pq.pop();
        if(here_dist != height[here_y][here_x]) continue;
        for(int i=0; i<4; i++){
            if(_map[here_y][here_x][i] == -1) continue;
            int next_x = here_x + dx[i];
            int next_y = here_y + dy[i];
            if(!in(next_y,next_x)) continue;
            int next_height = max(height[here_y][here_x], min(_map[here_y][here_x][i], height[next_y][next_x]));
            if(next_height < height[next_y][next_x]){
                height[next_y][next_x] = next_height;
                pq.push({next_height,next_y,next_x});
            }
        }
    }
    int ans = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            ans+=height[i][j];
        }
    }
    cout<<ans;
}
