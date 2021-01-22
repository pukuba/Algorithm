#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll tree[444444];
bool lazy[444444];
int n,m;
void update_lazy(int node,int start,int end){
    if(lazy[node]){
        tree[node] = (end-start+1) - tree[node];
        if(start != end){
            lazy[node*2] = lazy[node*2]?0:1;
            lazy[node*2+    1] = lazy[node*2+1]?0:1;
        }
        lazy[node] = false;
    }
}
void update_range(int node,int start,int end,int left,int right){
    update_lazy(node,start,end);
    if(start > right || end < left) return;
    if(left <= start && end <= right){
        tree[node] = (end-start+1) - tree[node];
        if(start != end){
            lazy[node*2] = lazy[node*2]?false:true;
            lazy[node*2+1] = lazy[node*2+1]?false:true;
        }
        return;
    }
    update_range(node*2,start,start+end>>1,left,right);
    update_range(node*2+1,(start+end>>1)+1,end,left,right);
    tree[node] = tree[node*2] + tree[node*2+1];
}
ll query(int node,int start,int end,int left,int right){
    update_lazy(node, start, end);
    if(right < start || end < left) return 0;
    if(left <= start && end <= right) return tree[node];
    return query(node*2,start,start+end>>1,left,right) + query(node*2+1,(start+end>>1)+1,end,left,right);
}
int main(){
    ios_base::sync_with_stdio(0),cin.tie(nullptr);
    cin>>n>>m;
    while(m--){
        int type,from,to;
        cin>>type>>from>>to;
        if(type == 1) cout<<query(1,1,n,from,to)<<'\n';
        if(type == 0) update_range(1,1,n,from,to);
    }
}
