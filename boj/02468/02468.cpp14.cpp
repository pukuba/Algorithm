#include <bits/stdc++.h>

using namespace std;
int n;
int in(int a,int b){
    return ( 1<=a && a<=n && 1<=b  && b<=n );
}
int check[101][101];
int map_arr[101][101];
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};
int arr[101][101];
struct point{
    int y,x;
};
int main(){
    cin>>n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>map_arr[i][j];
        }
    }
    int ans1=0;
    for(int i=0; i<=100; i++){
        memset(check,false,sizeof(check));
        memset(arr,false,sizeof(arr));
        for(int j=1; j<=n; j++){
            for(int k=1; k<=n; k++){
                if(map_arr[j][k]>i) arr[j][k]=1;
                else arr[j][k]=0;
            }
        }
        queue<point> q;
        int ans2=0;
        for(int j=1; j<=n; j++){
            for(int k=1; k<=n; k++){
                if(arr[j][k]==1){
                    arr[j][k]=0;
                    ++ans2;
                    q.push({j,k});
                    check[j][k]=true;
                    ans1=max(ans1,ans2);
                    while(!q.empty()){
                        int cur_x=q.front().x;
                        int cur_y=q.front().y;
                        q.pop();
                        for(int m=0; m<4; m++){
                            int next_x=cur_x+dx[m];
                            int next_y=cur_y+dy[m];
                            if(in(next_y,next_x) && !check[next_y][next_x] && arr[next_y][next_x]==1){
                                check[next_y][next_x]=true;
                                arr[next_y][next_x]=0;
                                q.push({next_y,next_x});
                            }
                        }
                    }
                }
            }
        }
    }
    cout<<ans1<<'\n';
}
