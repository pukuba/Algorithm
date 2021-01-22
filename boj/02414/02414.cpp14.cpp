#include <bits/stdc++.h>

using namespace std;
int n,m,red[55][55],blue[55][55],red_id,blue_id,b[5555],ans;
char _map[55][55];
vector<int> adj[5555];
bool check[5555];
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
bool in(int y,int x){
    if(y < 1 || y > n || x < 1 || x > m) return false;
    return _map[y][x] == '*';
}
void red_go(int y,int x,int id){
    red[y][x] = id;
    if(in(y+1,x)) red_go(y+1,x,id);
}
void blue_go(int y,int x,int id){
    blue[y][x] = id;
    if(in(y,x+1)) blue_go(y,x+1,id);
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    memset(b,-1,sizeof(b));
    cin>>n>>m;
    for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) cin>>_map[i][j];
    for(int i=1; i<=n; i++) for(int j=1; j<=m; j++){
        if(_map[i][j] == '*'){
            if(!red[i][j]) red_go(i,j,++red_id);
            if(!blue[i][j]) blue_go(i,j,++blue_id);
        }
    }
    for(int i=1; i<=n; i++) for(int j=1; j<=m; j++){
        if(_map[i][j] == '*') adj[red[i][j]].push_back(blue[i][j] + red_id);
    }
    for(int i=1; i<=red_id; i++){
        memset(check,false,sizeof(check));
        if(dfs(i)) ans++;
    }
    cout<<ans;
}