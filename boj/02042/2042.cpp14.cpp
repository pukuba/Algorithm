#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll tree[4444444],a[4444444],n,x,y,m,r,z,c;
ll init(int node,int start,int end){
    if(start == end) return tree[node] = a[start];
    return tree[node] = init(node*2,start,start+end>>1) + init(node*2+1,(start+end>>1)+1,end);
}
ll update(int node,int start,int end,int pos,int diff){
    if(start > pos || end < pos) return tree[node];
    if(start == end) return tree[node] = diff;
    return tree[node] = update(node*2,start,start+end>>1,pos,diff) + update(node*2+1,(start+end>>1)+1,end,pos,diff);
}
ll query(int node,int start,int end,int left,int right){
    if(start > right || end < left) return 0;
    if(left <= start && end <= right) return tree[node];
    return query(node*2, start, end+start>>1, left, right) + query(node*2+1,(start+end>>1)+1,end,left,right);
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>n>>m>>r;
    c = m + r;
    for(int i=1; i<=n; i++) cin>>a[i];
    init(1,1,n);
    while(c--){
        cin>>z>>x>>y;
        if(z == 1) update(1,1,n,x,y);
        if(z == 2) cout<<query(1,1,n,x,y)<<'\n';
    }
}
