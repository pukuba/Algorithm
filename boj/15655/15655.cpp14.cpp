#include <bits/stdc++.h>

using namespace std;
vector<int> v;
bool check[10];
int n,m,arr[10];
void dfs(int idx){
	if(idx==m){
		for(int i=0; i<m; i++)cout<<arr[i]<<' ';
		cout<<'\n';
		return ;
	}
	else{
		for(int i=0; i<n; i++){
			if(check[i] || v[i]<arr[idx-1]) continue;
			check[i]=true;
			arr[idx]=v[i];
			dfs(idx+1);
			check[i]=false;
		}
	}
}
int main(){
	cin>>n>>m;
	for(int i=0; i<n; i++){
		int x;
		cin>>x;
		v.push_back(x);
	}
	sort(v.begin(),v.end());
	dfs(0);
}