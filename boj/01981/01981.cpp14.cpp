#include <bits/stdc++.h>

using namespace std;
int _map[111][111],_min=1e9,_max,n,dx[4]={0,-1,0,1},dy[4]={1,0,-1,0},ans;
bool go[111][111],check[111][111];
bool in(int a,int b){return 1<=a && a<=n && 1<=b && b<=n;}
bool bfs(int diff){
    for(int k=_min; k<=_max; k++){
        memset(go,false,sizeof(go));
        memset(check,false,sizeof(check));
        for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) if(k+diff>=_map[i][j] && _map[i][j] >=k) go[i][j]=true;
        queue<pair<int,int> > q;
        if(go[1][1]){
            q.push({1,1});
            check[1][1] = true;
        }
        while(q.size()){
            auto [y,x] = q.front();
            q.pop();
            if(y == n && x == n) return true;
            for(int i=0; i<4; i++){
                int next_y = dy[i] + y;
                int next_x = dx[i] + x;
                if(!in(next_y,next_x) || go[next_y][next_x] == false || check[next_y][next_x]) continue;
                q.push({next_y,next_x});
                check[next_y][next_x] = true;
            }
        }
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>n;
    for(int i=1; i<=n; i++) for(int j=1; j<=n; j++){
        cin>>_map[i][j];
        _min = min(_min,_map[i][j]);
        _max = max(_max,_map[i][j]);
    }
    int s=0,e=200;
    while(s<=e){
        int mid = s+e>>1;
        if(bfs(mid)) e=mid-1;
        else s=mid+1;
    }
    cout<<e+1<<'\n';
}
