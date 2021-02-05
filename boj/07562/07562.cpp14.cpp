#include <bits/stdc++.h>

using namespace std;
struct Point{
    int x,y,cnt;
};
int dx[8]={-2,-1,1,2,2,1,-1,-2};
int dy[8]={-1,-2,-2,-1,1,2,2,1};
bool check[301][301];
int main(){
    int t;
    cin>>t;
    while(t--){
        memset(check,false,sizeof(check));
        int l,n,m,end_n,end_m;
        queue<Point> q;
        cin>>l>>n>>m;
        q.push({n,m,0});
        check[m][n]=true;
        cin>>end_n>>end_m;
        while(!q.empty()){
            int cur_x=q.front().x;
            int cur_y=q.front().y;
            int cur_cnt=q.front().cnt;
            q.pop();
            if(cur_x==end_n && cur_y==end_m){
                cout<<cur_cnt<<'\n';
                break;
            }
            for(int i=0; i<8; i++){
                int next_x=cur_x+dx[i];
                int next_y=cur_y+dy[i];
                int next_cnt=cur_cnt+1;
                if(0 <= next_x && next_x <= l-1 && 0 <= next_y && next_y <= l-1 && check[next_y][next_x]==false){
                    check[next_y][next_x]=true;
                    q.push({next_x,next_y,next_cnt});
                }
            }
        }
    }
    return 0;
}
