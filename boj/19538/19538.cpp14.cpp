#include <bits/stdc++.h>

using namespace std;
int n,check[222222],ans[222222],m,k;
bool c[222222];
vector<int> adj[222222];
struct p{int here,t,go;};
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	memset(ans,-1,sizeof(ans));
	for(int i=1,x; i<=n; i++){
		for(;;){
			cin>>x;
			if(!x) break;
			adj[i].push_back(x);
		}
	}
	cin>>m;
	queue<pair<int,int> > q;
	while(m--){
		cin>>k;
		q.push({k,0});
		check[k] = 1;
		c[k] = 1;
		ans[k] = 0;
	}
	while(1){
		queue<int> go;
		queue<pair<int,int> > temp;
		while(q.size()){
			int here = q.front().first;
			int t = q.front().second;
			q.pop();
			for(int i=0; i<adj[here].size(); i++){
				int next = adj[here][i];
				if(c[next]) continue;
				check[next] = check[next]+1;
				if(check[next] >= (adj[next].size()+1)/2){
					c[next] = 1;
					ans[next] = t + 1;
					temp.push({next,t+1});
					go.push(next);
				}
			}
		}
		while(go.size()){
			check[go.front()]++;
			go.pop();
		}
		while(temp.size()){
			q.push(temp.front());
			temp.pop();
		}
		if(!q.size()) break;
	}
	
	for(int i=1; i<=n; i++) cout<<ans[i]<<' ';
}