#include <bits/stdc++.h>

using namespace std;
using pi = pair<int,int>;
int n,m,dx[4]={0,1,0,-1},dy[4]={1,0,-1,0},ans;
bool check[105][105];
set<pi> st,visit;
map<pi,vector<pi>> mp;
bool in(int a,int b){return 1<=a && a<=n && 1<=b && b<=m;}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    for(int i=1,s,e,x,y; i<=m; i++){
        cin>>s>>e>>x>>y;
        mp[{s,e}].push_back({x,y});
    }
    st.insert({1,1});
    queue<pi> q;
    q.push({1,1});
    check[1][1] = 1;
    while(q.size()){
        pi here = q.front();
        int tmp = st.size();
        if(!visit.count(here)){
            visit.count(here);
            if(mp[here].size()){
                for(pi a : mp[here]){
                    st.insert(a);
                }
            }
        }
        if(st.size() != tmp){
            memset(check, 0, sizeof check);
        }
        q.pop();
        for(int i=0; i<4; i++){
            int ny = here.first + dy[i], nx = here.second + dx[i];
            if(!in(ny,nx)) continue;
            if(st.count({ny,nx}) && check[ny][nx] == 0){
                q.push({ny,nx});
                check[ny][nx] = 1;
            }
        }
    }
//    for(int i=1; i<=n; i++){
//        for(int j=1; j<=n; j++){
//            ans += check[i][j];
//        }
//    }
    cout<<st.size()<<'\n';
}
