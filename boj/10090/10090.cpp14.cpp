#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll tree[4444444],arr[1111111],ans,n;
ll update(int node,int s,int e,int pos){
	if(s > pos || e < pos) return tree[node];
	if(s == e) return tree[node] = 1;
	return tree[node] = update(node*2,s,s+e>>1,pos) + update(node*2+1,(s+e>>1)+1,e,pos);
}
ll qry(int node,int s,int e,int l,int r){
	if(s > r || e < l) return 0;
	if(l <= s && e <= r) return tree[node];
	return qry(node*2,s,s+e>>1,l,r) + qry(node*2+1,(s+e>>1)+1,e,l,r);
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(nullptr);
	cin>>n;
	for(int i=1; i<=n; i++) cin>>arr[i];
	for(int i=1; i<=n; i++){
		ans += qry(1,1,n,arr[i],n);
		update(1,1,n,arr[i]);
	}
	cout<<ans<<'\n';
}