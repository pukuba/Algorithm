#include <bits/stdc++.h>

using namespace std;
int n,m,k,e, _dist[20001];
#define pi pair<int,int>
vector<pi> v[20001];
bool check[20001];
const int INF=987654321;
priority_queue<pi,vector<pi>,greater<pi>> pq;
int main(){
    cin>>n>>m;
    for(int i=1; i<=m; i++){
        int a,b,c;
        cin>>a>>b>>c;
        v[a].push_back(pi(c,b));
    }
    cin>>k>>e;
    fill(_dist, _dist + 20001, INF);
    _dist[k] = 0;
    pq.push(pi(0,k));
    while(!pq.empty()){
        int here = pq.top().second;
        int dist = pq.top().first;
        pq.pop();
        if(_dist[here] != dist) continue;
        for(pi there : v[here]){
            int height = there.first;
            int next = there.second;
            if(_dist[here] + height < _dist[next]){
                _dist[next] = _dist[here] + height;
                pq.push(pi(_dist[next], next));
            }
        }
    }
    cout<<_dist[e]<<'\n';
}
