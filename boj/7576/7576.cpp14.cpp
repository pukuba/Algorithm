#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};
struct point{
    int x,y,time;
};
int n,m;
int in(int a,int b){
    return(1<=a && a<= n && 1<=b && b<=m );
}

int main(){
    cin>>n>>m;
    int arr[m+1][n+1];
    memset(arr,false,sizeof(arr));
    queue<point> q;
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            cin>>arr[i][j];
            if(arr[i][j]==1){
                q.push({j,i,1});
            }
        }
    }
    while(!q.empty()){
        int cur_x=q.front().x;
        int cur_y=q.front().y;
        int cur_time=q.front().time;
        q.pop();
        for(int i=0; i<4; i++){
            int next_x=cur_x+dx[i];
            int next_y=cur_y+dy[i];
            int next_time=cur_time+1;
            if(in(next_x,next_y) && arr[next_y][next_x]!=-1 && arr[next_y][next_x]==0){
                arr[next_y][next_x] = next_time;
                q.push({next_x,next_y,next_time});
            }
        }
    }
    int ans=0;
    bool check=false;
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(arr[i][j]==0) check=true;
            ans=max(ans,arr[i][j]);
        }
    }
    (check)?cout<<"-1":cout<<ans-1;
}
