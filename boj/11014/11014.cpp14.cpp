#include <bits/stdc++.h>

using namespace std;
int n,m,t,id[88][88],id_value,dx[6]={-1,-1,1,1,1,-1},dy[6]={-1,0,0,-1,1,1},ans,b[8888];
char _map[88][88];
bool check[8888];
vector<int> adj[8888];
bool dfs(int here){
    check[here] = true;
    for(int next : adj[here]){
        if(b[next] == -1 || !check[b[next]] && dfs(b[next])){
            b[next] = here;
            return true;
        }
    }
    return false;
}
void add_id(int y,int x){
    if(_map[y][x] == 'x') return;
    id[y][x] = ++id_value;
}
bool in(int y,int x){return 1<=y && y<=n && 1<=x && x<=m;}
void edge_p(int y,int x){
    if(_map[y][x] == 'x') return;
    for(int i=0; i<6; i++){
        int next_x = x + dx[i];
        int next_y = y + dy[i];
        if(!in(next_y,next_x)) continue;
        if(_map[next_y][next_x] == 'x') continue;
        adj[id[y][x]].push_back(id[next_y][next_x]);
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>t;
    while(t--){
        id_value = ans = 0;
        memset(_map,false,sizeof(_map));
        memset(id,false,sizeof(id));
        memset(b,-1,sizeof(b));
        for(int i=0; i<=8887; i++) adj[i].clear();
        cin>>n>>m;
        for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) cin>>_map[i][j];
        for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) add_id(i,j);
        for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) edge_p(i,j);
        for(int i=1; i<=n; i++) for(int j=1; j<=m; j+=2){
            memset(check,false,sizeof(check));
            if(_map[i][j] == 'x') continue;
            if(dfs(id[i][j])) ans++;
        }
        cout<<id_value-ans<<'\n';
    }
}