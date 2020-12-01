#include <bits/stdc++.h>

using namespace std;
int n,m,x,y,z;
typedef long long ll;
ll tree[6666],lazy[6666],_map[707][707];
void lazy_u(int node,int start,int end){
    if(lazy[node]){
        tree[node] += (end-start+1) * lazy[node];
        if(start != end){
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
}
ll update_r(int node,int start,int end,int left,int right,int diff){
    lazy_u(node,start,end);
    if(start > right || end < left) return tree[node];
    if(left <= start && end <= right){
        tree[node] += (end-start+1) * diff;
        if(start != end){
            lazy[node*2] += diff;
            lazy[node*2+1] += diff;
        }
        return tree[node];
    }
    return tree[node] = update_r(node*2,start,start+end>>1,left,right,diff) + update_r(node*2+1,(start+end>>1)+1,end,left,right,diff);
}
ll sum(int node,int start,int end,int here){
    lazy_u(node,start,end);
    if(start > here || end < here) return 0;
    if(here <= start && end <= here) return tree[node];
    return sum(node*2,start,start+end>>1,here) + sum(node*2+1,(start+end>>1)+1,end,here);
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1; i<=m; i++){
        cin>>x>>y>>z;
        update_r(1,1,n*2-1,x+1,x+y,1);
        update_r(1,1,n*2-1,x+y+1,n*2-1,2);
    }
    for(int i=1; i<=n; i++) _map[n-i+1][1] = sum(1,1,n*2-1,i);
    for(int i=1+1; i<=n; i++) _map[1][i] = sum(1,1,n*2-1,i+n-1);
    for(int i=2; i<=n; i++) for(int j=2; j<=n; j++) _map[i][j] = max({_map[i][j-1],_map[i-1][j],_map[i-1][j-1]});
    for(int i=1; i<=n; i++,cout<<"\n") for(int j=1; j<=n; j++) cout<<_map[i][j]+1<<' ';
}