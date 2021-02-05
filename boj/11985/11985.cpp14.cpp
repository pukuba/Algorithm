#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll n,m,k,a[20202],d[20202][1010];
ll f(ll here,ll have,ll _min,ll _max){
    ll &ret = d[here][have];
    if(have > m) return 1e15;
    if(here > n) return k+have*(_max-_min);
    if(ret != -1) return ret;
    return ret = min(f(here+1,have+1,min(_min,a[here]),max(_max,a[here])),f(here+1,1,a[here],a[here])+k+have*(_max-_min));
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>n>>m>>k;
    memset(d,-1,sizeof(d));
    for(int i=1; i<=n; i++) cin>>a[i];
    cout<<f(1,0,1e12,-1e12);
}