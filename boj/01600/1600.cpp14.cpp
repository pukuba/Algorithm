#include <bits/stdc++.h>

using namespace std;
struct point{
    int k,y,x;
};
int k,n,m,arr[31][201][201],dx[4]={-1,0,1,0},dy[4]={0,-1,0,1},mx[8]={-2,-1,1,2,2,1,-1,-2},my[8]={-1,-2,-2,-1,1,2,2,1};
bool _map[201][201];
bool in(int a,int b){
    return (1<=a && a<=m && 1<=b && b<=n);
}
int main(){
    memset(arr,-1,sizeof(arr));
    cin>>k>>n>>m;
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            cin>>_map[i][j];
        }
    }
    queue<point> q;
    q.push({0,1,1});
    arr[0][1][1]=0;
    while(!q.empty()){
        int cur_k=q.front().k;
        int cur_x=q.front().x;
        int cur_y=q.front().y;
        q.pop();
        if(cur_x==n && cur_y==m){
            cout<<arr[cur_k][cur_y][cur_x]<<'\n';
            return 0;
        }
        if(cur_k<k){
            for(int i=0; i<8; i++){
                int next_x=cur_x+mx[i];
                int next_y=cur_y+my[i];
                int next_k=cur_k+1;
                if(in(next_y,next_x) && arr[next_k][next_y][next_x]==-1 && !_map[next_y][next_x]){
                    arr[next_k][next_y][next_x]=arr[cur_k][cur_y][cur_x]+1;
                    q.push({next_k,next_y,next_x});
                }
            }
        }
        for(int i=0; i<4; i++){
            int next_y=cur_y+dy[i];
            int next_x=cur_x+dx[i];
            if(in(next_y,next_x) && arr[cur_k][next_y][next_x]==-1 && !_map[next_y][next_x]){
                arr[cur_k][next_y][next_x]=arr[cur_k][cur_y][cur_x]+1;
                q.push({cur_k,next_y,next_x});
            }
        }
    }
    cout<<"-1\n";
}

