#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<=n; i++)
using namespace std;
vector<int> adj[501];
int _time[501],d[501],arr[501],n;
main(){
	cin>>n;
	rep(i,1,n){
		int x;
		cin>>x;
		_time[i]=x;
		while(1){
			int y;
			cin>>y;
			if(y==-1) break;
			arr[i]++;
			adj[y].push_back(i);
		}
	}
	queue<int> q;
	rep(i,1,n) if(!arr[i]) q.push(i);
	while(!q.empty()){
		int here=q.front();
		q.pop();
		for(int there : adj[here]){
			if(!--arr[there]) q.push(there);
			d[there]=max(d[there],d[here]+_time[here]);
		}
	}
	rep(i,1,n) cout<<d[i]+_time[i]<<'\n';
}