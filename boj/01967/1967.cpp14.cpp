#include <bits/stdc++.h>

using namespace std;
int n;
bool check[10001];
vector<pair<int, int> > v[10001];
pair<int,int> bfs(int start){
	int ret_node=0;
	int ret_depth=0;
	queue<pair<int,int> > q; 
	q.push({start,0});
	check[start]=true;
	while(!q.empty()){
		int cur_node=q.front().first;
		int cur_depth=q.front().second;
		q.pop();
		for(int i=0; i<v[cur_node].size(); i++){
			if(!check[v[cur_node][i].first]){
				check[v[cur_node][i].first]=true;
				if(ret_depth<v[cur_node][i].second + cur_depth){
					ret_depth=v[cur_node][i].second+cur_depth;
					ret_node=v[cur_node][i].first;
				}
				q.push({v[cur_node][i].first,v[cur_node][i].second + cur_depth});
			}
		}
	}
	return {ret_node,ret_depth};
}
int main(){
	cin>>n;
	for(int i=1; i<n; i++){
		int x,q,w;
		cin>>x>>q>>w;
		v[x].push_back({q,w});
		v[q].push_back({x,w});
	}
	pair<int,int> p1=bfs(1);
	memset(check,0,sizeof(check));
	pair<int,int> p2=bfs(p1.first);
	cout<<p2.second<<'\n';
}