#include <bits/stdc++.h>

using namespace std;
using pi = pair<int,int>;
int n,m,cnt,hy,hx,dy[9]={1,1,1,0,0,0,-1,-1,-1},dx[9]={-1,0,1,-1,0,1,-1,0,1};
char _map[103][103];
vector<pi> v;
string s;
void gg(){
    cout<<"kraj "<<cnt<<'\n';
    exit(0);
}
void iMove(int x){
    if(_map[dy[x] + hy][dx[x] + hx] == 'R') gg();
    _map[hy][hx] = '.';
    _map[dy[x] + hy][dx[x] + hx] = 'I';
    hy += dy[x];
    hx += dx[x];
}
void rMove(){
    map<pi,int> mp;
    for(pi t : v){
        int y = t.first, x = t.second;
        _map[y][x] = '.';
        pair<int,int> ans = {1e9,1e9};
        for(int i=0; i<9; i++){
            if(i == 4) continue;
            int ny = y + dy[i], nx = x + dx[i];
            if(ans.first > (abs(hy-ny) + abs(hx-nx))){
                ans = {(abs(hy-ny) + abs(hx-nx)), i};
            }
        }
        mp[{y + dy[ans.second],x + dx[ans.second]}]++;
    }
    v.clear();
    for(pair<pi,int> t : mp){
        int y = t.first.first, x = t.first.second;
        if(_map[y][x] == 'I') gg();
        if(t.second == 1){
            v.push_back({y,x});
            _map[y][x] = 'R';
        }
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin>>_map[i][j];
            if(_map[i][j] == 'R') v.push_back({i,j});
            if(_map[i][j] == 'I'){
                hy=i;
                hx=j;
            }
        }
    }
    cin>>s;
    for(char c : s){
        ++cnt;
        iMove(c-'0'-1);
        rMove();
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cout<<_map[i][j];
        }
        cout<<'\n';
    }
}