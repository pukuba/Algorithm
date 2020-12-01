#include <bits/stdc++.h>

using namespace std;
int n,m,k,d[102][1<<14],x,y,z,crystal[103],id,ans;
bool check[102][1<<14];
vector<pair<int,int> > adj[102];
queue<pair<int,int> > q;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>n>>m>>k;
    while(k--){
        cin>>x;
        crystal[x] = ++id;
    }
    for(int i=1; i<=m; i++){
        cin>>x>>y>>z;
        adj[x].push_back({y,z});
        adj[y].push_back({x,z});
    }
    adj[0].push_back({1,222});adj[1].push_back({0,222});
    q.push({0,0});
    check[0][0] = true;
    while(q.size()){
        auto[here,cry_cnt] = q.front();
        q.pop();
        if(here == 0) ans = max(ans,__builtin_popcount(cry_cnt));
        for(auto info : adj[here]){
            int next = info.first;
            int weight = info.second;
            if(crystal[next]){
                if(cry_cnt & 1<<(crystal[next] - 1)){
                    if(!check[next][cry_cnt] && weight >= __builtin_popcount(cry_cnt)){
                        check[next][cry_cnt] = true;
                        q.push({next,cry_cnt});
                    }
                }
                else{
                    if(!check[next][cry_cnt] && weight >= __builtin_popcount(cry_cnt)){
                        check[next][cry_cnt] = true;
                        q.push({next,cry_cnt});
                    }
                    if(!check[next][cry_cnt | (1<<(crystal[next]-1))] && weight >= __builtin_popcount(cry_cnt | (1<<(crystal[next]-1)))){
                        check[next][cry_cnt | (1<<(crystal[next]-1))] = true;
                        q.push({next,cry_cnt | (1<<(crystal[next]-1))});
                    }
                }
            }
            else{
                if(!check[next][cry_cnt] && weight >= __builtin_popcount(cry_cnt)){
                    check[next][cry_cnt] = true;
                    q.push({next,cry_cnt});
                }
            }
        }
    }
    cout<<ans;
}