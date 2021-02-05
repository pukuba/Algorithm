#include <bits/stdc++.h>

using namespace std;
int n,m,k,red[303][303],blue[303][303],red_id,blue_id,ans,b[55555];
set<int> adj[55555];
bool chess[303][303],check[55555];
bool in(int y,int x){return 1<= y && y<=n && 1<=x && x<=m;}
void red_go(int y,int x,int id){
    red[y][x] = id;
    if(in(y,x)) red_go(y+1,x,id);
}
void blue_go(int y,int x,int id){
    blue[y][x] = id;
    if(in(y,x+1)) blue_go(y,x+1,id);
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
    memset(chess,true,sizeof(chess));
    memset(b,-1,sizeof(b));
    cin>>n>>m>>k;
    for(int i=1; i<=k; i++){
        int f,s;
        cin>>f>>s;
        chess[f][s] = false;
    }
    for(int i=1; i<=n; i++) for(int j=1; j<=m; j++){
        if(chess[i][j]){
            if(!red[i][j]) red_go(i,j,++red_id);
            if(!blue[i][j]) blue_go(i,j,++blue_id);
        }
    }
    for(int i=1; i<=n; i++) for(int j=1; j<=m; j++){
        if(chess[i][j]) adj[red[i][j]].insert(red_id + blue[i][j]);
    }
    for(int i=1; i<=red_id; i++){
        memset(check,false,sizeof(check));
        if(dfs(i)) ans++;
    }
    cout<<ans;
}