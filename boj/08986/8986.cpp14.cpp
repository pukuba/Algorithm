#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int n,a[100111];
ll ans = 1e18;
ll f(int x,ll ret){
    for(int i=1; i<=n; i++) ret += abs(1ll*x*(i-1)-a[i]);
    return ret;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i];
    ll lo = 0,hi = a[n];
    while(hi-lo >= 3){
        ll p = (lo*2+hi)/3, q = (hi*2+lo)/3;
        if(f(p,0) <= f(q,0)) hi = q;
        else lo = p;
    }
    for(int i=lo; i<=hi; i++) ans = min(ans,f(i,0));
    cout<<ans;
}