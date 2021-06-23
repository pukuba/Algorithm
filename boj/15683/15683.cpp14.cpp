#include <bits/stdc++.h>

using namespace std;
int n,m,_map[11][11],tmp[11][11], id=1,ans;
map<int,pair<int,int> > mp;
vector<vector<int> > v;
bool in(int a,int b){return 1<=a && a<=n && 1<=b && b<=m;}
void up(int y,int x){
    if(tmp[y][x] == 6) return;
    tmp[y][x] = 7;
    if(in(y-1,x)) up(y-1,x);
}
void left(int y,int x){
    if(tmp[y][x] == 6) return;
    tmp[y][x] = 7;
    if(in(y,x-1)) left(y,x-1);
}
void down(int y,int x){
    if(tmp[y][x] == 6) return;
    tmp[y][x] = 7;
    if(in(y+1,x)) down(y+1,x);
}
void right(int y,int x){
    if(tmp[y][x] == 6) return;
    tmp[y][x] = 7;
    if(in(y,x+1)) right(y,x+1);
}
int cal(){
    int ret=0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            ret += tmp[i][j] == 0;
        }
    }
    return ret;
}
void dfs(vector<int> vec){
    if(vec.size() == id-1){
        v.push_back(vec);
        return;
    }
    vec.push_back(1);
    dfs(vec);
    vec.pop_back();
    vec.push_back(2);
    dfs(vec);
    vec.pop_back();
    vec.push_back(3);
    dfs(vec);
    vec.pop_back();
    vec.push_back(4);
    dfs(vec);
    return;
}
void cp(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            tmp[i][j] = _map[i][j];
        }
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin>>_map[i][j];
            if(1 <= _map[i][j] && _map[i][j] <= 5){
                mp[id] = {i,j};
                id++;
            }
            if(!_map[i][j]) ans++;
        }
    }
    dfs({});
    for(int i=0; i<v.size(); i++){
        cp();
        for(int j=0; j<v[i].size(); j++){
            int y = mp[j+1].first, x = mp[j+1].second;
            int cctv = _map[y][x], pos = v[i][j];
            if(cctv == 5) up(y,x),down(y,x),left(y,x),right(y,x);
            if(cctv == 1){
                if(pos == 1) right(y,x);
                if(pos == 2) down(y,x);
                if(pos == 3) left(y,x);
                if(pos == 4) up(y,x);
            }
            if(cctv == 2){
                if(pos == 1 || pos == 3) left(y,x),right(y,x);
                if(pos == 2 || pos == 4) up(y,x),down(y,x);
            }
            if(cctv == 3){
                if(pos==1) up(y,x),right(y,x);
                if(pos==2) right(y,x),down(y,x);
                if(pos==3) down(y,x),left(y,x);
                if(pos==4) left(y,x),up(y,x);
            }
            if(cctv == 4){
                if(pos==1) left(y,x),up(y,x),right(y,x);
                if(pos==2) right(y,x),down(y,x),up(y,x);
                if(pos==3) down(y,x),left(y,x),right(y,x);
                if(pos==4) left(y,x),up(y,x),down(y,x);
            }
        }
        ans = min(ans,cal());
    }
    cout<<ans<<'\n';
}