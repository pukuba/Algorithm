#include <bits/stdc++.h>

using namespace std;
int n,m,sx,sy,ex,ey,dx[4]={0,-1,0,1},dy[4]={1,0,-1,0},ans;
char _map[333][333];
bool check[333][333];
bool in(int a,int b){return 1<=a && a<=n && 1<=b && b<=m;}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>n>>m>>sy>>sx>>ey>>ex;
    for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) cin>>_map[i][j];
    while(1){
        memset(check,false,sizeof(check));
        ans++;
        queue<pair<int,int> > q;
        q.push({sy,sx});
        check[sy][sx] = true;
        while(q.size()){
            auto[y,x] = q.front();
            q.pop();
            for(int i=0; i<4; i++){
                int next_y = dy[i] + y;
                int next_x = dx[i] + x;
                if(!in(next_y,next_x)) continue;
                if(check[next_y][next_x]) continue;
                check[next_y][next_x] = true;
                if(_map[next_y][next_x] == '1'){
                    _map[next_y][next_x] = '0';
                }
                else if(_map[next_y][next_x] == '0'){
                    q.push({next_y,next_x});
                }
                else if(_map[next_y][next_x] == '#'){
                    cout<<ans<<'\n';
                    return 0;
                }
            }
        }
    }
}