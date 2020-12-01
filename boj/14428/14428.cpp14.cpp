#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
pair<ll,ll> tree[444444];
int a[111111],n,m;
pair<ll,ll> init(int node,int start,int end){
    if(start == end) return tree[node] = {a[start],start};
    return tree[node] = min(init(node*2,start,start+end>>1),init(node*2+1,(start+end>>1)+1,end));
}
pair<ll,ll> query(int node,int start,int end,int left,int right){
    if(right < start || end < left) return {1e9,1e9};
    if(left <= start && end <= right) return tree[node];
    return min(query(node*2,start,start+end>>1,left,right),query(node*2+1,(start+end>>1)+1,end,left,right));
}
void update(int node,int start,int end,int pos,int diff){
    if(pos < start || end < pos) return;
    if(pos <= start && end <= pos){
        tree[node] = {diff,pos};
        return;
    }
    update(node*2,start,start+end>>1,pos,diff);
    update(node*2+1,(start+end>>1)+1,end,pos,diff);
    tree[node] = min(tree[node*2],tree[node*2+1]);
}
int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i];
    init(1,1,n);
    cin>>m;
    while(m--){
        int type,from,to;
        cin>>type>>from>>to;
        if(type == 1) update(1,1,n,from,to);
        if(type == 2) cout<<query(1,1,n,from,to).second<<'\n';
    }
}
