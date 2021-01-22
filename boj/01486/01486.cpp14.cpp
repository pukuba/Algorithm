#include <bits/stdc++.h>

using namespace std;
char _map[30][30];
int n,m,t,d,inf=1e9,ans=0,dx[4]={0,1,0,-1},dy[4]={-1,0,1,0};
using pi = pair<int,int>;
using pip = pair<int,pi>;
priority_queue<pip,vector<pip>,greater<>> pq;
pip make(int a,int b,int c){return {a,{b,c}};}
int dist[30][30],_dist[30][30];
int turn(char c){
    if('A'<=c && c<='Z') return c-65;
    return c-71;
}
bool in(int a,int b){return 1<=a && a<=n && 1<=b && b<=m;}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    fill(&dist[0][0],&dist[28][28],inf);
    cin>>n>>m>>t>>d;
    for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) cin>>_map[i][j];
    pq.push(make(0,1,1));
    dist[1][1]=0;
    ans = max(ans,turn(_map[1][1]));
    while(!pq.empty()){
        int cur_dist = pq.top().first;
        int cur_y = pq.top().second.first;
        int cur_x = pq.top().second.second;
        pq.pop();
        if(dist[cur_y][cur_x] != cur_dist) continue;
        for(int i=0; i<4; i++){
            int next_x = dx[i] + cur_x;
            int next_y = dy[i] + cur_y;
            if(!in(next_y,next_x)) continue;
            int next_weight = turn(_map[cur_y][cur_x]) >= turn(_map[next_y][next_x]) ? 1 : pow(turn(_map[next_y][next_x])-turn(_map[cur_y][cur_x]),2);
            if(abs(turn(_map[cur_y][cur_x])-turn(_map[next_y][next_x])) > t) continue;
            if(dist[cur_y][cur_x] + next_weight > d) continue;
            if(dist[next_y][next_x] > dist[cur_y][cur_x] + next_weight){
                dist[next_y][next_x] = dist[cur_y][cur_x] + next_weight;
                pq.push(make(dist[next_y][next_x],next_y,next_x));
            }
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(dist[i][j]!=inf){
                fill(&_dist[0][0],&_dist[28][28],inf);
                _dist[i][j] = 0;
                pq.push(make(0,i,j));
                while(!pq.empty()){
                    int cur_dist = pq.top().first;
                    int cur_y = pq.top().second.first;
                    int cur_x = pq.top().second.second;
                    pq.pop();
                    if(_dist[cur_y][cur_x] != cur_dist) continue;
                    for(int k=0; k<4; k++){
                        int next_x = dx[k] + cur_x;
                        int next_y = dy[k] + cur_y;
                        if(!in(next_y,next_x)) continue;
                        int next_weight = turn(_map[cur_y][cur_x]) >= turn(_map[next_y][next_x]) ? 1 : pow(turn(_map[next_y][next_x])-turn(_map[cur_y][cur_x]),2);
                        if(abs(turn(_map[cur_y][cur_x])-turn(_map[next_y][next_x])) > t) continue;
                        if(_dist[cur_y][cur_x] + next_weight > d) continue;
                        if(_dist[next_y][next_x] > _dist[cur_y][cur_x] + next_weight){
                            _dist[next_y][next_x] = _dist[cur_y][cur_x] + next_weight;
                            pq.push(make(_dist[next_y][next_x],next_y,next_x));
                        }
                    }
                }
            }
            if(dist[i][j] + _dist[1][1] <= d) ans = max(ans,turn(_map[i][j]));
        }
    }
    cout<<ans;
}
