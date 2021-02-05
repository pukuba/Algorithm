#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll n,m,k,dist[10101][23],ans=1e18,inf=1e18;
struct pos{
	ll cost,here,use;
	bool operator < (const pos &a) const{
		return cost > a.cost;
	}
};
vector<pair<ll,ll> > adj[10101];
priority_queue<pos> pq;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m>>k;
	for(ll i=1,x,y,z; i<=m; i++){
		cin>>x>>y>>z;
		adj[x].push_back({z,y});
		adj[y].push_back({z,x});
	}
	for(int i=0; i<10101; i++) for(int j=0; j<23; j++) dist[i][j] = inf;
	dist[1][0] = 0;
	for(ll i=1; i<=n; i++) sort(adj[i].begin(),adj[i].end());
	pq.push({0,1,0});
	while(pq.size()){
		ll here = pq.top().here;
		ll cost = pq.top().cost;
		ll use = pq.top().use;
		pq.pop();
		if(here == n){
			ans = min(cost,ans);
			continue;
		}
		if(dist[here][use] != cost) continue;
		for(auto i : adj[here]){
			ll next_cost = i.first;
			ll next = i.second;
			bool next_use = use < k;
			if(next_use){
				if(dist[next][use+1] > dist[here][use]){
					dist[next][use + 1] = dist[here][use];
					pq.push({dist[here][use],next,use + 1});
				}
				if(dist[next][use] > dist[here][use] + next_cost){
					dist[next][use] = dist[here][use] + next_cost;
					pq.push({dist[next][use],next,use});
				}
			}
			else{
				if(dist[next][use] > dist[here][use] + next_cost){
					dist[next][use] = dist[here][use] + next_cost;
					pq.push({dist[next][use],next,use});
				}
			}
		}
	}
	cout<<ans<<'\n';
}