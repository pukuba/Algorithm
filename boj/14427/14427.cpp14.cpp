#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int n,m,a[111111];
pair<ll,ll> tree[444444];
pair<ll,ll> init(int node,int start,int end){
	if(start == end) return tree[node] = {a[start],start}; 
	return tree[node] = min(init(node*2,start,start+end>>1),init(node*2+1,(start+end>>1)+1,end));
}
void update(int node,int start,int end,int pos,int diff){
	if(start > pos || end < pos) return;
	if(pos <= start && end <= pos){
		tree[node] = {diff,pos};
		return;
	}
	update(node*2,start,start+end>>1,pos,diff);
	update(node*2+1,(start+end>>1)+1,end,pos,diff);
	tree[node] = min(tree[node*2],tree[node*2+1]);
}
pair<ll,ll> query(int node,int start,int end){
	if(start > n || end < 1) return {1e8,1e8};
	if(1 <= start && end <= n) return tree[node];
	return min(query(node*2,start,end),query(node*2+1,start,end));
}
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	cin>>n;
	for(int i=1; i<=n; i++) cin>>a[i];
	init(1,1,n);	
	cin>>m;
	while(m--){
		int type;
		cin>>type;
		if(type == 1){
			int idx, value;
			cin>>idx>>value;
			update(1,1,n,idx,value);
		}	
		if(type == 2) cout<<query(1,1,n).second<<'\n';
	}
}