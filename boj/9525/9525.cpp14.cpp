#include <bits/stdc++.h>

using namespace std;
int n,red[103][103],blue[103][103],b[15333],blue_id,red_id,ans;
bool check[15333];
char _map[103][103];
vector<int> adj[15003];
bool in(int y,int x){
    if(y < 1 || y > n || x < 1 || x > n) return false;
    return _map[y][x] == '.';
}
void make_red(int y,int x,int id){
    red[y][x] = id;
    if(in(y+1,x)) make_red(y+1,x,id);
}
void make_blue(int y,int x,int id){
    blue[y][x] = id;
    if(in(y,x+1)) make_blue(y,x+1,id);
}
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
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    memset(b,-1,sizeof(b));
    cin>>n;
    for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) cin>>_map[i][j];
    for(int i=1; i<=n; i++) for(int j=1; j<=n; j++){
        if(_map[i][j] == 'X') continue;
        if(!red[i][j]) make_red(i,j,++red_id);
        if(!blue[i][j]) make_blue(i,j,++blue_id);
    }
    for(int i=1; i<=n; i++) for(int j=1; j<=n; j++){
        if(_map[i][j] == 'X') continue;
        adj[red[i][j]].push_back(blue[i][j]+5003);
    }
    for(int i=1; i<=red_id; i++){
        memset(check,false,sizeof(check));
        if(dfs(i)) ans++;
    }
    cout<<ans;
}