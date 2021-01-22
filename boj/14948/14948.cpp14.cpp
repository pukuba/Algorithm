#include <bits/stdc++.h>

using namespace std;
int n,m,_min=1e9,_max,_map[111][111],ans,dx[4]={0,-1,0,1},dy[4]={1,0,-1,0};
bool check[111][111][2];
bool in(int a,int b){return 1<=a && a<=n && 1<=b && b<=m;}
struct pos{int y,x,type;};
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1; i<=n; i++) for(int j=1; j<=m; j++){
        cin>>_map[i][j];
        _min = min(_min,_map[i][j]);
        _max = max(_max,_map[i][j]);
    }
    while(_min<=_max){
        int mid = _min+_max>>1;
        queue<pos> q;
        memset(check,false,sizeof check);
        if(_map[1][1] <= mid){
            q.push({1,1,0});
            check[1][1][0] = true;
        }
        while(q.size()){
            auto[y,x,t] = q.front();
            q.pop();
            for(int i=0; i<4; i++){
                int nx = dx[i] + x,ny = dy[i] + y,nnx=dx[i]*2 + x,nny = dy[i]*2 + y;
                if(!t){
                    if(in(ny,nx) && !check[ny][nx][0] && _map[ny][nx] <= mid){
                        q.push({ny,nx,0});
                        check[ny][nx][0] = 1;
                    }
                    if(in(nny,nnx) && !check[nny][nnx][1] && _map[nny][nnx] <= mid ){
                        q.push({nny,nnx,1});
                        check[nny][nnx][1] = 1;
                    }
                }
                else{
                    if(in(ny,nx) && !check[ny][nx][1] && _map[ny][nx] <= mid){
                        q.push({ny,nx,1});
                        check[ny][nx][1] = 1;
                    }
                }
            }
        }
        if(check[n][m][1] || check[n][m][0]){
            ans = mid;
            _max = mid-1;
        }
        else _min = mid+1;
    }
    cout<<ans<<'\n';
}