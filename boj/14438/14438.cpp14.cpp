#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll tree[444444],inf=1e10;
int a[111111],n,m;
ll init(int node,int start,int end){
    if(start == end) return tree[node] = a[start];
    return tree[node] = min(init(node*2,start,start+end>>1),init(node*2+1,(start+end>>1)+1,end));
}
ll query(int node,int start,int end,int left,int right){
    if(right < start || end < left) return inf;
    if(left <= start && end <= right) return tree[node];
    return min(query(node*2,start,start+end>>1,left,right),query(node*2+1,(start+end>>1)+1,end,left,right));
}
ll update(int node,int start,int end,int idx,int diff){
    if(idx <start || end < idx) return tree[node];
    if(start == end) return tree[node] = diff;
    return tree[node] = min(update(node*2,start,start+end>>1,idx,diff),update(node*2+1,(start+end>>1)+1,end,idx,diff));
}
int main(){
    ios_base::sync_with_stdio(0),cin.tie(nullptr);
    cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i];
    init(1,1,n);
    cin>>m;
    while(m--){
        int type,from,to;
        cin>>type>>from>>to;
        if(type == 2) cout<<query(1,1,n,from,to)<<'\n';
        if(type == 1) update(1,1,n,from,to);
    }
}
