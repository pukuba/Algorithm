#include <bits/stdc++.h>

using namespace std;
int n,blue[13][13],red[13][13],b[111],ans,red_id,blue_id;
bool chess[13][13],check[111];
vector<int> adj[1111];
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
    if(y<1 || y>n || x<1 || x>n) return false;
    return true;
}
void red_go(int y,int x,int id){
    red[y][x] = id;
    if(in(y+1,x+1)) red_go(y+1,x+1,id);
}
void blue_go(int y,int x,int id){
    blue[y][x] = id;
    if(in(y+1,x-1)) blue_go(y+1,x-1,id);
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    memset(b,-1,sizeof(b));
    cin>>n;
    for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) cin>>chess[i][j];
    for(int i=1; i<=n; i++) for(int j=1; j<=n; j++){
        if(!red[i][j]) red_go(i,j,++red_id);
        if(!blue[i][j]) blue_go(i,j,++blue_id);
    }
    for(int i=1; i<=n; i++) for(int j=1; j<=n; j++){
        if(!chess[i][j]) continue;
        adj[red[i][j]].push_back(blue[i][j] + red_id);
    }
    for(int i=1; i<=red_id; i++){
        memset(check,false,sizeof(check));
        if(dfs(i)) ans++;
    }
    cout<<ans<<'\n';
}