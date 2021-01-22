#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int n,k,m,d[101010],a[101010],b[101010],c[101010],p[101010],tree[444444],MAX=1e5,lazy[444444];
ll ans;
void lazyUpdate(int node,int s,int e){
    if(lazy[node] != 0){
        tree[node] += (e-s+1)*lazy[node];
        if(s != e){
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
}
void update(int node,int s,int e,int l,int r,int v){
    lazyUpdate(node,s,e);
    if(r < s || e < l) return ;
    if(l <= s && e <= r) {
        tree[node] += (e-s+1) * v;
        if(s != e){
            lazy[node*2] += v;
            lazy[node*2+1] += v;
        }
        return;
    }
    update(node*2,s,s+e>>1,l,r,v); update(node*2+1,(s+e>>1)+1,e,l,r,v);
    tree[node] = tree[node*2] + tree[node*2+1];
}
ll query(int node,int s,int e,int l,int r){
    lazyUpdate(node,s,e);
    if(r < s || e < l) return 0;
    if(l <= s && e <= r) return tree[node];
    return query(node*2,s,s+e>>1,l,r) + query(node*2+1,(s+e>>1)+1,e,l,r);
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(nullptr);
	cin>>n>>m;
	cin>>a[1];
	for(int i=2; i<=m; i++){
		cin>>a[i];
		int l = min(a[i],a[i-1]),r = max(a[i],a[i-1])-1;
		update(1,1,MAX,l,r,1);
	}
	for(int i=1; i<n; i++) cin>>b[i]>>c[i]>>p[i];
	for(int i=1; i<n; i++){
		ll here = query(1,1,MAX,i,i);
		ans += min(here * b[i], here *c[i] + p[i]);
	}
	cout<<ans<<'\n';
}