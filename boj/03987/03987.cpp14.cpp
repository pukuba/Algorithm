#include <bits/stdc++.h>

using namespace std;
int n,m,r,c, dx[4]={0,-1,0,1},dy[4]={1,0,-1,0};
pair<int,int> ans;
char _map[505][505];
bool check[505][505][6];
string s="DLUR";
int ns(char c, int v){
    if(c == '/'){
        if(v == 1) return 2;
        if(v == 2) return 1;
        if(v == 3) return 4;
        if(v == 4) return 3;
    }
    if(v == 1) return 4;
    if(v == 2) return 3;
    if(v == 3) return 2;
    return 1;
}
bool in(int a,int b){return 1<=a && a<=n && 1<=b && b<=m;}
int dfs(int y,int x,int v){
    int tmp = 0;
    while(1){
        if(!in(y,x)) return tmp;
        if(check[y][x][v]){
            return 1e9;
        }
        check[y][x][v] = 1;
        if(_map[y][x] == 'C'){
            return tmp;
        }
        if(_map[y][x] == '/' || _map[y][x] == '\\'){
            int dis = ns(_map[y][x], v);
            tmp++;
            y += dy[dis-1];
            x += dx[dis-1];
            v = dis;
        }
        else{
            y += dy[v-1];
            x += dx[v-1];
            tmp++;
        }
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin>>_map[i][j];
        }
    }
    cin>>r>>c;
    for(int i=1; i<=4; i++){
        memset(check, 0, sizeof(check));
        ans = max(ans,{dfs(r,c,i),i});
    }
    if(ans.first >= 1000000){
        cout<<s[ans.second-1]<<'\n'<<"Voyager";
    } else {
        cout<<s[ans.second-1]<<'\n'<<ans.first;
    }
}