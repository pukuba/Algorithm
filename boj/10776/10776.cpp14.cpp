#include <bits/stdc++.h>

using namespace std;
using pi = pair<int,int>;
using pip = pair<int,pi>;
int dist[2111][2111],inf=1e9,s,e,k,n,m,ans=1e9;
struct point{int to,t,h;};
struct ppq{
    int _time,here,_life;
    bool operator < (ppq const &a) const{
        return _time<a._time;
    }
};
vector<point> v[2111];
priority_queue<ppq> pq;
pip make(int a,int b,int c){return {a,{b,c}};}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    fill(&dist[0][0],&dist[2109][2109],inf);
    cin>>k>>n>>m;
    for(int i=1; i<=m; i++){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        v[a].push_back({b,c,d});
        v[b].push_back({a,c,d});
    } cin>>s>>e;
    dist[s][k]=0;
    pq.push({0,s,k});
    while(!pq.empty()){
        int here = pq.top().here;
        int here_time = -pq.top()._time;
        int here_hp = pq.top()._life;
        pq.pop();
        if(here == e){
            cout<<here_time;
            return 0;
        }
        if(dist[here][here_hp] < here_time) continue;
        for(point i : v[here]){
            auto[next,need_time,need_hp] = i;
            if(here_hp-need_hp < 1) continue;
            if(dist[here][here_hp] + need_time < dist[next][here_hp-need_hp]){
                dist[next][here_hp-need_hp] = dist[here][here_hp] + need_time;
                pq.push({-(dist[next][here_hp-need_hp]),next,here_hp-need_hp});
            }
        }
    }
    cout<<-1;
}
