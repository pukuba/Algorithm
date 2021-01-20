#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool map[100][100];
int check[100][100];
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
int n,m;
int in(int a,int b);
int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
           int input;
           scanf("%1d",&input);
           if(input==1){
              map[i][j]=true;
         }
        }
    }
    int cur_x=0,cur_y=0;
    queue<pair<int,int> > q;
    q.push(pair<int,int>(cur_y,cur_x));
    check[cur_y][cur_x]=1;
    while(!q.empty()){
        cur_x=q.front().second;
        cur_y=q.front().first;
        q.pop();
        for(int i=0; i<4; i++){
            int next_x=cur_x+dx[i];
            int next_y=cur_y+dy[i];

            if(in(next_y,next_x) && check[next_y][next_x]==0 && map[next_y][next_x]){
                check[next_y][next_x]=check[cur_y][cur_x]+1;
                q.push(pair<int,int>(next_y,next_x));
            }
        }
    }
    cout<<check[n-1][m-1];
}
int in(int a,int b){
    return (a>=0 && a<n) && (b>=0 && m>b);
}
