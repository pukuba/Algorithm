#include <bits/stdc++.h>

using namespace std;
int _map[1010][1010],n,m,ans,dy[]={0,-1,0,1,1,1,-1,-1},dx[]={1,0,-1,0,1,-1,-1,1};
bool check[1010][1010];
queue<pair<int,int> > q;
bool in(int a,int b){return 1<=a && a<=n && 1<=b && b<=m;}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    for(int i=1; i<=n; i++) for(int j=1; j<=m; j++){
        char x;
        cin>>x;
        if(x == '.'){
            q.push({i,j});
            _map[i][j] = 0;
            check[i][j] = 1;
        }
        else _map[i][j] = x-'0';
    }
    while(1){
        queue<pair<int,int> > temp;
        while(q.size()){
            auto[y,x] = q.front();
            q.pop();
            for(int i=0; i<8; i++){
                int next_y = dy[i] + y, next_x = dx[i] + x;
                if(!in(next_y,next_x) || check[next_y][next_x]) continue;
                if(_map[next_y][next_x]){
                    _map[next_y][next_x]--;
                    if(!_map[next_y][next_x]){
                        temp.push({next_y,next_x});
                        check[next_y][next_x] = 1;
                    }
                }
            }
        }
        if(temp.empty()) break;
        q = temp;
        ans++;
    }
    cout<<ans;
}
