#include <bits/stdc++.h>
 
using namespace std;
int ary[1001][1001][2],arr[1001][1001];
int n,m;
int ans=987654321;
bool check;
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};
struct Point{
    int x,y,door;
};
int in(int a,int b){
    return (1<=a && a<=n && 1<=b && b<=m);
}
int main(){
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            scanf("%1d",&arr[i][j]);
        }
    }
    queue<Point> q;
    q.push({1,1,0});
    while(!q.empty()){
        int cur_x=q.front().x;
        int cur_y=q.front().y;
        int cur_door=q.front().door;
        q.pop();
        if(cur_x==m && cur_y==n){
            ans=ary[cur_y][cur_x][cur_door];
            break;
        }
        for(int i=0; i<4; i++){
            int next_x=cur_x+dx[i];
            int next_y=cur_y+dy[i];
            if(in(next_y,next_x) && !ary[next_y][next_x][cur_door]){
                if(arr[next_y][next_x]==0){
                    ary[next_y][next_x][cur_door]=ary[cur_y][cur_x][cur_door]+1;
                    q.push({next_x,next_y,cur_door});
                }
                else if(arr[next_y][next_x]==1){
                    if(cur_door!=1){
                        ary[next_y][next_x][cur_door+1]=ary[cur_y][cur_x][cur_door]+1;
                        q.push({next_x,next_y,cur_door+1});
                    }
                }
            }
        }
    }
    if(ans==987654321){
        cout<<"-1";
        return 0;
    }
    cout<<ans+1<<'\n';
    return 0;
}
