#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll tree[2222222];
int n,arr[500333],m;
ll init(int node,int start,int end){
    if(start == end) return tree[node] = arr[start];
    return tree[node] = init(node*2,start,start+end>>1) + init(node*2+1,(start+end>>1)+1,end);
}
ll update(int node,int start,int end,int pos,int value){
    if(end < pos || start > pos) return tree[node];
    if(start == end) return tree[node] = value;
    return tree[node] = update(node*2,start,start+end>>1,pos,value) + update(node*2+1,(start+end>>1)+1,end,pos,value);
}
ll query(int node,int start,int end,int value){
    if(start == end) return start;
    if(tree[node*2] >= value) return query(node*2,start,start+end>>1,value);
    return query(node*2+1,(start+end>>1)+1,end,value-tree[node*2]);
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>n;
    for(int i=1; i<=n; i++) cin>>arr[i];
    init(1,1,n);
    cin>>m;
    while(m--){
        int type;
        cin>>type;
        if(type == 1){
            int pos,val;
            cin>>pos>>val;
            arr[pos] += val;
            update(1,1,n,pos,arr[pos]);
        }
        if(type == 2){
            int pos;
            cin>>pos;
            cout<<query(1,1,n,pos)<<'\n';
        }
    }
}