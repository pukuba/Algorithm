#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll tree1[444444], tree2[444444],a[111111],n,t;
ll init1(int node, int s, int e){
	if(s == e){
		return tree1[node] = a[s];
	}
	return tree1[node] = max(init1(node*2,s,s+e>>1),init1(node*2+1,(s+e>>1)+1,e));
}
ll init2(int node, int s, int e){
	if(s == e){
		return tree2[node] = a[s];
	}
	return tree2[node] = min(init2(node*2,s,s+e>>1),init2(node*2+1,(s+e>>1)+1,e));
}
ll query1(int node,int s,int e,int l,int r){
	if(s > r || e < l) return -1e9;
	if(l <= s && e <= r) return tree1[node];
	return max(query1(node*2,s,s+e>>1,l,r),query1(node*2+1,(s+e>>1)+1,e,l,r));
}
ll query2(int node,int s,int e,int l,int r){
	if(s > r || e < l) return 1e9;
	if(l <= s && e <= r) return tree2[node];
	return min(query2(node*2,s,s+e>>1,l,r),query2(node*2+1,(s+e>>1)+1,e,l,r));
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> n >> t;
	for(int i=1; i<=n; i++){
		cin>>a[i];
	}
	init1(1,1,n), init2(1,1,n);
	while(t--){
		int x,y;
		cin>>x>>y;
		cout<<query2(1,1,n,x,y)<<' '<<query1(1,1,n,x,y)<<'\n';
	}
}