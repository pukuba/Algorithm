#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll tree[444444],lazy[444444];
int a[111111],n,m;
ll init(int node,int start,int end){
    if(start == end) return tree[node] = a[start];
    return tree[node] = init(node*2,start,start+end>>1) + init(node*2+1,(start+end>>1)+1,end);
}
void update_lazy(int node,int start,int end){
    if(lazy[node] != 0){
        tree[node] += (end-start+1)*lazy[node];
        if(start != end){
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node]=0;
    }
}
void update_range(int node,int start,int end,int left,int right,int diff){
    update_lazy(node,start,end);
    if(start > right || end < left) return;
    if(left <= start && end <= right){
        tree[node] += (end-start+1) * diff;
        if(start != end){
            lazy[node*2] += diff;
            lazy[node*2+1] += diff;
        }
        return;
    }
    update_range(node*2,start,start+end>>1,left,right,diff);
    update_range(node*2+1,(start+end>>1)+1,end,left,right,diff);
    tree[node] = tree[node*2] + tree[node*2+1];
}
ll sum(int node,int start,int end,int here){
    update_lazy(node,start,end);
    if(start > here || end < here) return 0;
    if(here <= start && end <= here) return tree[node];
    return sum(node*2,start,start+end>>1,here) + sum(node*2+1,(start+end>>1)+1,end,here);
}
int main(){
    ios_base::sync_with_stdio(0),cin.tie(nullptr);
    cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i];
    init(1,1,n);
    cin>>m;
    while(m--){
        int type;
        cin>>type;
        if(type==1){
            int from,to,add;
            cin>>from>>to>>add;
            update_range(1, 1, n, from, to, add);
        }
        else{
            int go;
            cin>>go;
            cout<<sum(1,1,n,go)<<'\n';
        }
    }
}
