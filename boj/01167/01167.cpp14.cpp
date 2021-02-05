#include <bits/stdc++.h>

using namespace std;
int n;
bool check[100001];
vector<pair<int,int> > v[100001];
pair<int, int> bfs(int s,int size){
	int dis=0;
	int tv=0;
	queue<pair<int,int> > q;
	q.push({s,0});
	check[s]=true;
	while(!q.empty()){
		pair<int,int> cur_v=q.front();
		q.pop();
		for(int i=0; i<v[cur_v.first].size(); i++){
			if(check[v[cur_v.first][i].first] == false){
				check[v[cur_v.first][i].first] = true;
				if(dis<cur_v.second + v[cur_v.first][i].second){
					dis=cur_v.second + v[cur_v.first][i].second;
					tv=v[cur_v.first][i].first;
				}
				q.push({v[cur_v.first][i].first,cur_v.second+v[cur_v.first][i].second});
			}
		}
	}
	return {dis,tv};
}
int main(){
	cin>>n;
	for(int i=1; i<=n; i++){
		int x;
		cin>>x;
		while(1){
			int _a,_b;
			cin>>_a;
			if(_a==-1) break;
			cin>>_b;
			v[x].push_back({_a,_b});
		}
	}
	pair<int,int> fir=bfs(1,n);
	memset(check,0,sizeof(check));
	pair<int,int> sec=bfs(fir.second,n);
	cout<<sec.first<<'\n';
}