#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll tree[100005],n,m,a[100005];
void update(ll idx,ll value){
    for(; idx<=100000; idx+=(idx& -idx)) tree[idx]+=value;
}
ll sum(ll idx){
    ll ret = 0;
    for(;idx;idx-=(idx& -idx)) ret+=tree[idx];
    return ret;
}
int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        cin>>a[i];
        update(i,a[i]);
    }
    while(m--){
        ll x,y,q,p;
        cin>>x>>y>>q>>p;
        if(x>y) swap(x,y);
        cout<<sum(y)-sum(x-1)<<'\n';
        update(q,p-a[q]);
        a[q]=p;
    }
}
