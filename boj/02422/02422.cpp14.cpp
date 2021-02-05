#include <bits/stdc++.h>

using namespace std;
int n,m,ans;
vector<int> v[202];
int go(int i,int j,int k){
	bool i_j = binary_search(v[i].begin(),v[i].end(),j);
	bool i_k = binary_search(v[i].begin(),v[i].end(),k);
	bool j_k = binary_search(v[j].begin(),v[j].end(),k);
	if(!i_j && !i_k && !j_k) return 1;
	return 0;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(int i=1; i<=m; i++){
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for(int i=1; i<=n; i++) sort(v[i].begin(),v[i].end());
	for(int i=1; i<=n; i++){
		for(int j=i+1; j<=n; j++){
			for(int k=j+1; k<=n; k++){
				ans += go(i,j,k);
			}
		}
	}
	cout<<ans<<'\n';
}