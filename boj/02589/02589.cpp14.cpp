#include <bits/stdc++.h>

using namespace std;
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};
struct point{
    int x,y,rank;
};
int n,m,ans=0;
int in(int a,int b){
    return (1<=a && a<=n && 1<=b && b<=m);
}
int main(){
    cin>>n>>m;
    bool check[51][51];
    int arr[51][51];
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            char c;
            scanf(" %c",&c);
            if(c=='W'){
                arr[i][j]=0;
            }
            else{
                arr[i][j]=1;
            }
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            memset(check, false, sizeof(check));
            if(arr[i][j]!=0){
                queue<point> q;
                q.push({j,i,0});
                check[i][j]=true;
                while(!q.empty()){
                    int cur_x=q.front().x;
                    int cur_y=q.front().y;
                    int cur_rank=q.front().rank;
                    ans=max(ans,cur_rank);
                    q.pop();
                    for(int i=0; i<4; i++){
                        int next_x=cur_x+dx[i];
                        int next_y=cur_y+dy[i];
                        int next_rank=cur_rank+1;
                        if(in(next_y,next_x) && arr[next_y][next_x] ==1 && check[next_y][next_x]==false){
                            check[next_y][next_x]=true;
                            q.push({next_x,next_y,next_rank});
                        }
                    }
                }
            }
        }
    }
    cout<<ans;
    
}
