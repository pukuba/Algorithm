#include <bits/stdc++.h>

using namespace std;
int t,arr[20001],ans;
bool check[20001];
vector<int> v[20001];
void dfs(int node){
	check[node]=true;
	for(auto go : v[node]){
		if(arr[go]%2 == arr[node]%2 ) ans++;
		if(!check[go]) dfs(go);
	}
	return ;
}
int main(){
	cin>>t;
	while(t--){
		for(int i=0; i<=20000; i++) v[i].clear();
		memset(arr,false,sizeof(arr));
		memset(check,false,sizeof(check));
		ans=0;
		int vertex,edge;
		cin>>vertex>>edge;
		for(int i=1; i<=edge; i++){
			int x,y;
			cin>>x>>y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		queue<pair<int,int> > q;
		for(int i=1; i<=vertex; i++){
			if(!check[i]){
				int cnt=1;
				q.push({i,cnt});
				arr[i]=cnt;
				while(!q.empty()){
					int here=q.front().first;
					int key=q.front().second;
					q.pop();
					for(int i=0; i<v[here].size(); i++){
						int next_x=v[here][i];
						if(!check[next_x]){
							check[next_x]=true;
							q.push({next_x,key+1});
							arr[next_x]=key+1;
						}
					}
				}
			}
		}
		memset(check,false,sizeof(check));
		for(int i=1; i<=vertex; i++) if(!check[i]) dfs(i);
		printf("%s\n",ans>0?"NO":"YES");
	}
}