#include <bits/stdc++.h>

using namespace std;
int n,m,d,_map[16][16],tmp[16][16],ans,res;
vector<tuple<int,int,int> > v;
void nxt(){
    for(int i=n; i>=1; i--){
        for(int j=1; j<=m; j++){
            tmp[i+1][j] = tmp[i][j];
            tmp[i][j] = 0;
        }
    }
}
void doit(int a,int b,int c){
    bool flg = false;
    for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) flg |= tmp[i][j];
    if(!flg) return;
    pair<int,pair<int,int> > p[3];
    for(int i=0; i<3; i++) p[i] = {1e9,{1e9,1e9}};
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(tmp[i][j]){
                if(abs(i-(n+1)) + abs(j-a) <= d){
                    p[0] = min(p[0],{abs(i-(n+1)) + abs(j-a),{j,i}});
                }
                if(abs(i-(n+1)) + abs(j-b) <= d){
                    p[1] = min(p[1],{abs(i-(n+1)) + abs(j-b),{j,i}});
                }
                if(abs(i-(n+1)) + abs(j-c) <= d){
                    p[2] = min(p[2],{abs(i-(n+1)) + abs(j-c),{j,i}});
                }
            }
        }
    }
    for(int i=0; i<3; i++){
        if(p[i].first != 1e9 && tmp[p[i].second.second][p[i].second.first]){
            res++;
            tmp[p[i].second.second][p[i].second.first] = 0;
        }
    }
    nxt();
    doit(a,b,c);
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m>>d;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin>>_map[i][j];
        }
    }
    for(int i=1; i<=m; i++){
        for(int j=i+1; j<=m; j++){
            for(int k=j+1; k<=m; k++){
                v.push_back({i,j,k});
            }
        }
    }
    for(auto[i,j,k] : v){
        for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) tmp[i][j] = _map[i][j];
        res = 0;
        doit(i,j,k);
        ans = max(res,ans);
    }
    cout<<ans<<'\n';
}