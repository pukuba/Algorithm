#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll n,m,p,q,dist[4][808],inf = 1e18;
vector<pair<ll,ll> > v[808];
struct pos{
	ll cost,here;
	bool operator < (const pos &a) const{
		return a.cost > cost;
	}
};
void go(int s,int k){
	priority_queue<pos> pq;
	for(int i=0; i<808; i++) dist[s][i] = inf;
	dist[s][k] = 0;
	pq.push({0,k});
	while(pq.size()){
		ll here = pq.top().here;
		ll cost = pq.top().cost;
		pq.pop();
		if(dist[s][here] != cost) continue;
		for(auto i : v[here]){
			ll next = i.second;
			ll next_cost = i.first;
			if(dist[s][next] > dist[s][here] + next_cost){
				dist[s][next] = dist[s][here] + next_cost;
				pq.push({dist[s][next],next});
			}
		} 
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(int i=1,x,y,z; i<=m; i++){
		cin>>x>>y>>z;
		v[x].push_back({z,y});
		v[y].push_back({z,x});
	}
	for(int i=1; i<=n; i++) sort(v[i].begin(),v[i].end());
	cin>>p>>q;
	go(1,1);go(2,p);go(3,q);
	ll ans = min(dist[1][p] + dist[2][q] +dist[3][n],dist[1][q] + dist[3][p] + dist[2][n]);
	cout<<(ans > 1e12 ? -1 : ans); 
}