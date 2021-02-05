#include <bits/stdc++.h>

using namespace std;
int n,m;
char _map[22][22];
bool check[22][22][3];
vector<string> s;
string go_right(int y,int x){
    string ret;
    ret += _map[y][x];
    check[y][x][1] = 1;
    for(int i=x+1; i<=m; i++){
        if(check[y][i][1]) break;
        check[y][i][1] = true;
        ret += _map[y][i];
    }
    return ret;
}
string go_down(int y,int x){
    string ret;
    ret += _map[y][x];
    check[y][x][2] = 1;
    for(int i=y+1; i<=n; i++){
        if(check[i][x][2]) break;
        check[i][x][2] = true;
        ret += _map[i][x];
    }
    return ret;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1; i<=n; i++) for(int j=1; j<=m; j++){
        cin>>_map[i][j];
        if(_map[i][j] == '#') check[i][j][1] = check[i][j][2] = 1;
    }
    for(int i=1; i<=n; i++) for(int j=1; j<=m; j++){
        if(!check[i][j][1]) s.push_back(go_right(i,j));
        if(!check[i][j][2]) s.push_back(go_down(i,j));
    }
    sort(s.begin(),s.end());
    for(auto k : s){
        if(k.size() >=2){
            cout<<k<<'\n';
            return 0;
        }
    }
}