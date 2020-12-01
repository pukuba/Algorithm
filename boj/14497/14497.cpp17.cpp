#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<=n; i++)
int check[301][301];
char _map[301][301];
int n,m,s_x,s_y,e_x,e_y,dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
using namespace std;
bool in(int a,int b){
    return (1<=a && a<=n && 1<=b && b<=m);
}
int main(){
    cin>>n>>m>>s_y>>s_x>>e_y>>e_x;
    rep(i,1,n) rep(j,1,m) cin>>_map[i][j];
    queue<pair<int,int> > q;
    queue<pair<int,int> > temp;
    q.push({s_y,s_x});
    check[s_y][s_x]=1;
    int cnt = 1;
    while(_map[e_y][e_x]!='0'){
        while(!q.empty()){
            auto [y,x] = q.front();
            q.pop();
            rep(i,0,3) {
                int next_x=x+dx[i];
                int next_y=y+dy[i];
                if(in(next_y,next_x) && !check[next_y][next_x] && _map[next_y][next_x]=='0'){
                    check[next_y][next_x] = cnt;
                    q.push({next_y,next_x});
                }
                if(in(next_y,next_x) && !check[next_y][next_x] && _map[next_y][next_x]=='#'){
                    cout<<cnt<<'\n';
                    return 0;
                }
                if(in(next_y,next_x) && !check[next_y][next_x] && _map[next_y][next_x]=='1'){
                    check[next_y][next_x] = cnt;
                    _map[next_y][next_x]='0';
                    temp.push({next_y,next_x});
                }
            }
        }
        q=temp;
        while(!temp.empty()) temp.pop();
        cnt++;
    }
    rep(i,1,n){
        rep(j,1,m){
            cout<<check[i][j]<<' ';
        }
        cout<<'\n';
    }
    cout<<check[e_y][e_x]<<'\n';
}
