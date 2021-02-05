#include <bits/stdc++.h>

using namespace std;
int n,m,tree[2222222],lazy[2222222],a[555555],t,s,e,k;
int init(int node,int s,int e){
    if(s == e) return tree[node] = a[s];
    return tree[node] = init(node*2,s,s+e>>1) ^ init(node*2+1,(s+e>>1)+1,e);
}
void update_lazy(int node,int s,int e){
    if(lazy[node] != 0){
        tree[node] ^= ((e-s+1)%2) * lazy[node];
        if(s != e){
            lazy[node*2] ^= lazy[node];
            lazy[node*2+1] ^= lazy[node];
        }
        lazy[node] = 0;
    }
}
int update_range(int node,int s,int e,int l,int r,int diff){
    update_lazy(node,s,e);
    if(s > r || e < l) return tree[node];
    if(l <= s && e <= r){
        tree[node] ^= ((e-s+1)%2) * diff;
        if(s!=e){
            lazy[node*2+1] ^= diff;
            lazy[node*2] ^= diff;
        }
        return tree[node];
    }
    return tree[node] = update_range(node*2,s,s+e>>1,l,r,diff) ^ update_range(node*2+1,(s+e>>1)+1,e,l,r,diff);
}
int query(int node,int s,int e,int h){
    update_lazy(node,s,e);
    if(s > h || e < h) return 0;
    if(s == e) return tree[node];
    return query(node*2,s,s+e>>1,h) + query(node*2+1,(s+e>>1)+1,e,h);
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i];
    init(1,1,n);
    cin>>m;
    while(m--){
        cin>>t;
        if(t == 1){
            cin>>s>>e>>k;
            if(s>e) swap(s,e);
            update_range(1,1,n,s+1,e+1,k);
        }
        else{
            cin>>s;
            cout<<query(1,1,n,s+1)<<'\n';
        }
    }
}