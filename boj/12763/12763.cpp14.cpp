#include <bits/stdc++.h>

using namespace std;
struct point{int to,money,_time;};
int n,t,m,l,inf=1e8,ans=1e8;
pair<int,int> dist[111];
vector<point> v[111];
int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    for(int i=1; i<=100; i++) dist[i]={inf,inf};
    cin>>n>>t>>m>>l;
    for(int i=1; i<=l; i++){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        v[a].push_back({b,d,c});
        v[b].push_back({a,d,c});
    }
    queue<point> q;
    dist[1]={0,0};
    q.push({1,0,0});
    while(!q.empty()){
        int here = q.front().to;
        int here_money = q.front().money;
        int here_time = q.front()._time;
        q.pop();
        if(here == n){
            ans = min(ans,here_money);
            continue;
        }
        for(point go : v[here]){
            int next_go = go.to;
            int next_time = go._time;
            int next_cost = go.money;
            if(next_time + here_time > t) continue;
            if(next_cost + here_money > m) continue;
            if(dist[next_go].first > here_money + next_cost || dist[next_go].second > here_time + next_time){
                dist[next_go].first = here_money + next_cost;
                dist[next_go].second = here_time + next_time;
                q.push({next_go,dist[next_go].first,dist[next_go].second});
            }
        }
    }
    if(ans!=1e8) cout<<ans;
    else cout<<-1<<'\n';
}
