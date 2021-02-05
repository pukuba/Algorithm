#include <bits/stdc++.h>

using namespace std;
using pi = pair<int,int>;
int n,m,k;
priority_queue<int,vector<int>,less<int>> dist[1010];
priority_queue<pi,vector<pi>,greater<pi>> pq;
vector<pair<int,int> > v[1010];
int f(int i){
    while(dist[i].size() >= 2) dist[i].pop();
    return dist[i].top();
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>n>>m>>k;
    for(int i=1,x,y,z; i<=m; i++){
        cin>>x>>y>>z;
        v[x].push_back({z,y});
    }
    for(int i=1; i<=n; i++) sort(v[i].begin(),v[i].end());
    dist[1].push(0);
    pq.push({0,1});
    while(pq.size()){
        auto[cost,here] = pq.top();
        pq.pop();
        for(pi next : v[here]){
            int next_cost = cost + next.first;
            int next_v = next.second;
            if(dist[next_v].size() == k && dist[next_v].top() > next_cost){
                dist[next_v].pop();
                dist[next_v].push(next_cost);
                pq.push({next_cost,next_v});
            }
            else if(dist[next_v].size() < k){
                dist[next_v].push(next_cost);
                pq.push({next_cost,next_v});
            }
        }
    }
    for(int i=1; i<=n; i++) cout<<(dist[i].size() == k ? dist[i].top() : -1)<<'\n';
}
