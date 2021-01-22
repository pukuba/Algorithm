#include <iostream>
#include <cstring>

using namespace std;
int arr[51][51];
bool check[51][51];
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};
int x,y,enemy;
int in(int a,int b){
    return(0<=a && a<=x && 0<=b && b<=y);
}
void dfs(int n,int m){
    check[n][m]=true;
    for(int i=0; i<4; i++){
        int next_x=m+dx[i];
        int next_y=n+dy[i];
        if(in(next_x,next_y)&&arr[next_y][next_x]==1 && check[next_y][next_x]==false){
            check[next_y][next_x]=true;
            dfs(next_y,next_x);
        }
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int cnt=0;
        memset(check,false,sizeof(check));
        memset(arr,false,sizeof(arr));
        cin>>x>>y>>enemy;
        for(int i=0; i<enemy; i++){
            int cur_x,cur_y;
            cin>>cur_x>>cur_y;
            arr[cur_y][cur_x]=1;
        }
        for(int i=0; i<y; i++){
            for(int j=0; j<x; j++){
                if(arr[i][j]==1 && check[i][j]==false){
                    dfs(i,j);
                    cnt++;
                }
            }
        }
        cout<<cnt<<'\n';
    }
}
