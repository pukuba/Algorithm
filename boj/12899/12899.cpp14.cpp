#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")
#pragma GCC target("avx,avx2,fma")
using namespace std;
using ll = long long;
ll tree[8888888],n,t,MAX = 2e6;
ll update(int node,int s,int e,int pos,int v){
    if(s > pos || e < pos) return tree[node];
    if(s == e) return tree[node] += v;
    return tree[node] = update(node*2,s,s+e>>1,pos,v) + update(node*2+1,(s+e>>1)+1,e,pos,v);
}
ll query(int node,int s,int e,int k){
    if(s == e) return s;
    if(tree[node*2] >= k) return query(node*2,s,s+e>>1,k);
    return query(node*2+1,(s+e>>1)+1,e,k-tree[node*2]);
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>t;
    while(t--){
        int type,x;
        cin>>type>>x;
        if(type == 1) update(1,1,MAX,x,1);
        else{
            ll here = query(1,1,MAX,x);
            cout<<here<<'\n';
            update(1,1,MAX,here,-1);
        }
    }
}