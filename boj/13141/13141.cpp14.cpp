#include <bits/stdc++.h>

using namespace std;
using pi = pair<int,int>;
vector<pi> v[222];
int n,m,dist[222],inf=1e9;
double ans = 1e9;
priority_queue<pi,vector<pi>,greater<>> pq;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1; i<=m; i++){
        int a,b,c;
        cin>>a>>b>>c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    for(int i=1; i<=n; i++){
        fill(dist,dist+220,inf);
        dist[i] = 0;
        pq.push({0,i});
        while(pq.size()){
            int here = pq.top().second;
            int here_dist = pq.top().first;
            pq.pop();
            if(dist[here] != here_dist) continue;
            for(pi i : v[here]){
                int next = i.first;
                int next_weight = i.second;
                if(dist[next] > dist[here] + next_weight){
                    dist[next] = dist[here] + next_weight;
                    pq.push({dist[next],next});
                }
            }
        }
        double temp =-1;
        for(int i=1; i<=n; i++) for(pi j : v[i]) temp = max(double(dist[i]+dist[j.first]+j.second)/2,temp);
        ans = min(temp,ans);
    }
    cout.precision(1);
    cout.unsetf(ios::fixed);
    cout<<fixed<<ans<<'\n';
}
