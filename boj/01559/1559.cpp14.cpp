#include <bits/stdc++.h>

using namespace std;
int n,m,_map[101][101],item[101][101],dist[101][101][1<<8],k,x,y,dx[4]={0,1,0,-1},dy[4]={-1,0,1,0},key,ans;
bool in(int a,int b){return 1<=a && a<=n && 1<=b && b<=m;}
struct p{int weight,y,x,items;};
struct cmp{
    bool operator()(p a,p b){return a.weight > b.weight;}
};
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
        memset(dist,0x3f,sizeof(dist));
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
        priority_queue<p,vector<p>,cmp> pq;
        pq.push({0,1,1,0});
        dist[1][1][0] = 0;
        while(pq.size()){
            auto[cur_weight,here_y,here_x,cnt] = pq.top();
            pq.pop();
            if(dist[here_y][here_x][cnt] != cur_weight) continue;
            if(here_y == n && here_x == m && cnt == (1<<key)-1){
                cout<<dist[here_y][here_x][cnt]<<'\n';
                break;
            }
            for(int i=0; i<4; i++){
                int next_x = dx[i] + here_x;
                int next_y = dy[i] + here_y;
                int next_cnt = cnt;
                if(!in(next_y,next_x)) continue;
                if(item[here_y][here_x]) next_cnt |= 1<<(item[here_y][here_x]-1);
                int next_plus = turn_p((_map[here_y][here_x]+dist[here_y][here_x][cnt])%4,i);
                int next_dist = next_plus + 1 + dist[here_y][here_x][cnt];
                if(dist[next_y][next_x][next_cnt] > next_dist){
                    dist[next_y][next_x][next_cnt] = next_dist;
                    pq.push({next_dist,next_y,next_x,next_cnt});
                }
            }
        }
    }
}