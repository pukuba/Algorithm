#include <bits/stdc++.h>

using namespace std;
int n,m,arr[9][9]={9,},ans=0;
bool check[9][9];
int in(int a,int b){
    return (1 <= a && a <= n && 1 <= b && b <= m);
}
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};
struct Point{
    int y,x;
};
int main(){
    int wall=3;
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin>>arr[i][j];
            if(arr[i][j]==1) wall++;
        }
    }
    Point key[65];
    int arr_cnt=1;
    for(int i=1; i<=8; i++){
        for(int j=1; j<=8; j++){
            key[arr_cnt].y=i;
            key[arr_cnt++].x=j;
        }
    }
    for(int i=1; i<=64; i++){
        for(int j=i+1; j<=64; j++){
            for(int k=j+1; k<=64; k++){
                if(arr[key[i].y][key[i].x] == 0 && arr[key[j].y][key[j].x] == 0 && arr[key[k].y][key[k].x] == 0){
                    memset(check,false,sizeof(check));
                    arr[key[i].y][key[i].x]=1;
                    arr[key[j].y][key[j].x]=1;
                    arr[key[k].y][key[k].x]=1;
                    queue<Point> q;
                    int cnt=0;
                    for(int l1=1; l1<=n; l1++){
                        for(int l2=1; l2<=m; l2++){
                            if(arr[l1][l2]==2 && check[l1][l2]==false){
                                q.push({l1,l2});
                                check[l1][l2]=true;
                                while(!q.empty()){
                                    int cur_x=q.front().x;
                                    int cur_y=q.front().y;
                                    q.pop();
                                    cnt++;
                                    for(int ii=0; ii<4; ii++){
                                        int next_x=cur_x+dx[ii];
                                        int next_y=cur_y+dy[ii];
                                        if(in(next_y,next_x) && check[next_y][next_x]==false && arr[next_y][next_x]==0){
                                            check[next_y][next_x]=true;
                                            q.push({next_y,next_x});
                                        }
                                    }
                                }
                            }
                        }
                    }
                    int real=(wall+cnt);
                    ans=max(ans,n*m-real);
                    arr[key[i].y][key[i].x]=0;
                    arr[key[j].y][key[j].x]=0;
                    arr[key[k].y][key[k].x]=0;
                }
            }
        }
    }
    cout<<ans;
}
