#include <bits/stdc++.h>

using namespace std;
int n,m,_map[101][101],item[101][101],dist[101][101][1<<8],k,x,y,dx[4]={0,1,0,-1},dy[4]={-1,0,1,0},key,ans;
bool in(int a,int b){return 1<=a && a<=n && 1<=b && b<=m;}
int turn_p(int a,int b){
    if(a==b) return 0;
    if(a<b) return b-a;
    return b-(a-4);
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    while(cin>>n>>m){
        if(n==m && n==0) break;
        key = 0;ans=1e9;
        for(int i=1; i<=100; i++) for(int j=1; j<=100; j++) for(int k=0; k<(1<<8); k++) dist[i][j][k] = 1e9;
        memset(_map,false,sizeof(_map));
        memset(item,false,sizeof(item));
        for(int i=1; i<=n; i++) for(int j=1; j<=m; j++){
            char c;
            cin>>c;
            if(c == 'N') _map[i][j] = 0;
            if(c == 'E') _map[i][j] = 1;
            if(c == 'S') _map[i][j] = 2;
            if(c == 'W') _map[i][j] = 3;
        }
        cin>>k;
        for(int i=1; i<=k; i++){
            cin>>y>>x;
            item[y][x] = ++key;
        }
        queue<tuple<int,int,int> > q;
        q.push({1,1,0});
        dist[1][1][0] = 0;
        while(q.size()){
            auto[here_y,here_x,cnt] = q.front();
            q.pop();
            if(here_y == n && here_x == m && cnt == (1<<key)-1){
                ans = dist[here_y][here_x][cnt];
                continue;
            }
            for(int i=0; i<4; i++){
                int next_x = dx[i] + here_x;
                int next_y = dy[i] + here_y;
                int next_cnt = cnt;
                if(!in(next_y,next_x)) continue;
                if(item[here_y][here_x]) next_cnt |= 1<<(item[here_y][here_x]-1);
                if(next_cnt != cnt && dist[here_y][here_x][next_cnt] > dist[here_y][here_x][cnt]) dist[here_y][here_x][next_cnt] = dist[here_y][here_x][cnt];
                int next_plus = (_map[here_y][here_x]+dist[here_y][here_x][cnt])%4;
                next_plus = turn_p(next_plus, i);
                if(dist[next_y][next_x][next_cnt] > dist[here_y][here_x][cnt] + next_plus + 1){
                    dist[next_y][next_x][next_cnt] =dist[here_y][here_x][cnt] + next_plus + 1;
                    q.push({next_y,next_x,next_cnt});
                }
            }
        }
        cout<<ans<<'\n';
    }
}