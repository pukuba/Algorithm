#include <bits/stdc++.h>

using namespace std;
#define y1 fuckkkk
int n,k,r,x1,y1,x,y,ans,dx[4]={0,-1,0,1},dy[4]={-1,0,1,0};
bool check[111][111];
set<pair<int,int>> s[111][111];
queue<pair<int,int> > q;
vector<pair<int,int> > v;
bool in(int a,int b){return 1<=a && a<=n && 1<=b && b<=n;}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>n>>k>>r;
    for(int i=1; i<=r; i++){
        cin>>y>>x>>y1>>x1;
        s[y][x].insert({y1,x1});
        s[y1][x1].insert({y,x});
    }
    for(int i=1; i<=k; i++){
        cin>>y>>x;
        v.push_back({y,x});
    }
    for(int i=0; i<v.size(); i++){
        memset(check,false,sizeof(check));
        q.push({v[i].first,v[i].second});
        while(q.size()){
            auto[here_y,here_x] = q.front();
            q.pop();
            for(int j=0; j<4; j++){
                int next_x = here_x + dx[j];
                int next_y = here_y + dy[j];
                if(!in(next_y,next_x)) continue;
                if(!check[next_y][next_x] && !s[here_y][here_x].count({next_y,next_x})){
                    check[next_y][next_x] = true;
                    q.push({next_y,next_x});
                }
            }
        }
        for(int j=i+1; j<v.size(); j++) if(!check[v[j].first][v[j].second]) ans++;
    }
    cout<<ans;
}