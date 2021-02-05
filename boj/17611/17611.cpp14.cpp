#include <bits/stdc++.h>

using namespace std;
int n,inf=500002;
typedef long long ll;
ll ans;
vector<pair<int,int> > v;
void update_lazy(vector<ll> &tree,vector<ll> &lazy,int node,int start,int end){
    if(lazy[node]){
        tree[node] += (end-start+1) * lazy[node];
        if(start != end){
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
}
ll update_range(vector<ll> &tree,vector<ll> &lazy,int node,int start,int end,int left,int right){
    update_lazy(tree,lazy,node,start,end);
    if(start > right || end < left) return tree[node];
    if(left <= start && end <= right){
        lazy[node]++;
        return tree[node];
    }
    return tree[node] = update_range(tree,lazy,node*2,start,start+end>>1,left,right) + update_range(tree,lazy,node*2+1,(start+end>>1)+1,end,left,right);
}
ll query(vector<ll> &tree,vector<ll> &lazy,int node,int start,int end,int left,int right){
    update_lazy(tree,lazy,node,start,end);
    if(start > right || end < left) return 0;
    if(left <= start && end <= right) return tree[node];
    return query(tree,lazy,node*2,start,start+end>>1,left,right) + query(tree,lazy,node*2+1,(start+end>>1)+1,end,left,right);
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    vector<ll> tree_x(4444444),tree_y(4444444),lazy_x(4444444),lazy_y(4444444);
    cin>>n;
    for(int i=1; i<=n; i++){
        int x,y;
        cin>>x>>y;
        v.push_back({x,y});
    }
    v.push_back(v[0]);
    for(int i=1; i<=n; i++){
        if(v[i].first != v[i-1].first) update_range(tree_x,lazy_x,1,0,inf*2-1,min(v[i].first,v[i-1].first)+1+inf,max(v[i].first,v[i-1].first)+inf);
        
        if(v[i].second !=v[i-1].second)
            update_range(tree_y,lazy_y,1,0,inf*2-1,min(v[i].second,v[i-1].second)+1+inf,max(v[i].second,v[i-1].second)+inf);
    }
    for(int i=-inf; i<inf; i++) ans = max({ans,query(tree_x,lazy_x,1,0,inf*2-1,i+inf,i+inf),query(tree_y,lazy_y,1,0,inf*2-1,i+inf,i+inf)});
    cout<<ans;
}
