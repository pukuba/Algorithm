#include <bits/stdc++.h>

using namespace std;
int n,m,s,e,dist[1010];
vector<pair<int,int> > adj[1010];
struct pos{
	int cost,now;
	vector<int> step;
	bool operator < (const pos &a) const{
		return cost > a.cost;
	}
};
priority_queue<pos> pq;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	memset(dist,0x3f,sizeof dist);
	for(int i=1,x,y,z; i<=m; i++){
		cin>>x>>y>>z;
		adj[x].push_back({z,y});
	}
	for(int i=1; i<=n; i++) sort(adj[i].begin(),adj[i].end());
	cin>>s>>e;
	dist[s] = 0;
	vector<int> v;
	v.push_back(s);
	pq.push({0,s,v});
	while(pq.size()){
		int here = pq.top().now;
		int cost = pq.top().cost;
		vector<int> step = pq.top().step;
		if(here == e){
			cout<<cost<<'\n'<<step.size()<<'\n';
			for(int i : step) cout<<i<<' '; 
			return 0;
		}
		pq.pop();
		if(dist[here] != cost) continue;
		for(auto i : adj[here]){
			int next_cost = i.first;
			int next = i.second;
			if(dist[next] > dist[here] + next_cost){
				dist[next] = dist[here] + next_cost;
				step.push_back(next);
				pq.push({dist[next],next,step});
				step.pop_back();
			}
		}
	}
}