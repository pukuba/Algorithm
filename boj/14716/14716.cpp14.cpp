#include "bits/stdc++.h"

using namespace std;
short dx[8]={0,1,0,-1,1,1,-1,-1},dy[8]={1,0,-1,0,-1,1,1,-1},n,m,ans;
bool _map[251][251];
queue<pair<short,short> >  q;
bool in(int a,int b){ return 1<=a && a<=n && 1<=b && b<=m; }
int main(){
    cin>>n>>m;
    for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) cin>>_map[i][j];
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(_map[i][j]){
                q.push({i,j});
                _map[i][j]=1;
                ans++;
                while(!q.empty()){
                    auto[y,x] = q.front();
                    q.pop();
                    for(int k=0; k<8; k++){
                        int nx=x+dx[k];
                        int ny=y+dy[k];
                        if(!in(ny,nx)) continue;
                        if(_map[ny][nx]) q.push({ny,nx}),_map[ny][nx]=0;
                    }
                }
            }
        }
    }
    cout<<ans;
}
