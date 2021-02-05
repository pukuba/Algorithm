#include <bits/stdc++.h>

using namespace std;
int n,m,k,dx[4]={-1,0,1,0},dy[4]={0,-1,0,1},arr[1001][1001];
bool bfs[2][11][1001][1001];
bool in(int a,int b){
    return (1<=a && a<=n && 1<=b && b<=m);
}
struct point{
    int y,x,wall,status,cnt;
};
int main(){
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            scanf("%1d",&arr[i][j]);
        }
    }
    queue<point> q;
    q.push({1,1,0,0,0});
    bfs[0][0][1][1]=0;
    while(!q.empty()){
        int cur_x=q.front().x;
        int cur_y=q.front().y;
        int cur_status=q.front().status;
        int cur_wall=q.front().wall;
        int cur_cnt=q.front().cnt;
        int next_status;
        if(cur_status==1) next_status=0;
        if(cur_status==0) next_status=1;
        if(cur_y == n && cur_x == m){
            cout<<cur_cnt+1<<'\n';
            return 0;
        }
        q.pop();
        for(int i=0; i<4; i++){
            int next_x=cur_x+dx[i];
            int next_y=cur_y+dy[i];
            if(in(next_y,next_x) ){
                if(arr[next_y][next_x]==1 && cur_status==0 && cur_wall<k && !bfs[next_status][cur_wall+1][next_y][next_x]){
                    bfs[next_status][cur_wall+1][next_y][next_x]=1;
                    q.push({next_y,next_x,cur_wall+1,next_status,cur_cnt+1});
                }
                else if(arr[next_y][next_x]==1 && cur_wall<k && cur_status==1 && !bfs[next_status][cur_wall][cur_y][cur_x]){
                    bfs[next_status][cur_wall][cur_y][cur_x]=1;
                    q.push({cur_y,cur_x,cur_wall,next_status,cur_cnt+1});
                }
                else if(arr[next_y][next_x]==0 && !bfs[next_status][cur_wall][next_y][next_x]){
                    bfs[next_status][cur_wall][next_y][next_x]=1;
                    q.push({next_y,next_x,cur_wall,next_status,cur_cnt+1});
                }
            }
        }
    }
    cout<<-1<<'\n';
    return 0;
}