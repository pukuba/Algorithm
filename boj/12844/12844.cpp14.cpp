#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll tree[2222222],a[2222222],lazy[2222222],n,m,k;
ll init(int node, int start, int end){
    if(start == end) return tree[node] = a[start];
    return tree[node] = init(node*2,start,start+end>>1) ^ init(node*2+1,(start+end>>1)+1,end);
}
void update_lazy(int node, int start, int end){
    if(lazy[node] != 0){
        tree[node] ^= ((end-start+1)%2) * lazy[node];
        if(start != end){
            lazy[node*2] ^= lazy[node];
            lazy[node*2+1] ^= lazy[node];
        }
        lazy[node] = 0;
    }
}
ll update_range(int node, int start, int end, int left, int right, ll diff){
    update_lazy(node,start,end);
    if(left > end || right < start) return tree[node];
    if(left <= start && end <= right){
        tree[node] ^= ((end-start+1)%2)*diff;
        if(start != end){
            lazy[node*2] ^= diff;
            lazy[node*2+1] ^= diff;
        }
        return tree[node];
    }
    return tree[node] = update_range(node*2,start,start+end>>1,left,right,diff) ^update_range(node*2+1,(start+end>>1)+1,end,left,right,diff);
}
ll sum(int node, int start, int end, int left, int right){
    update_lazy(node, start, end);
    if(left > end || right < start) return 0;
    if(left <= start && end <= right) return tree[node];
    return sum(node*2,start,start+end>>1,left,right) ^ sum(node*2+1,(start+end>>1)+1,end,left,right);
}
int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i];
    cin>>m;
    init(1,1,n);
    for(int i=1; i<=m; i++){
        int t;
        cin>>t;
        if(t==1){
            ll s,e,v;
            cin>>s>>e>>v;
            s++;e++;
            update_range(1, 1, n, s, e, v);
        }
        if(t==2){
            ll s,e;
            cin>>s>>e;
            s++;e++;
            cout<<sum(1,1,n,s,e)<<'\n';
        }
    }
}
