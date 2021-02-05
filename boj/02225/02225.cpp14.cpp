#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll n,k,mod=1e9;
ll d[222][222];
ll f(ll here,ll cnt){
    if(cnt > k) return 0;
    if(here == n) return 1;
    if(here > n) return 0;
    if(d[here][cnt] != -1) return d[here][cnt];
    d[here][cnt] = 0;
    for(int i=0; i<=n; i++){
        d[here][cnt] += f(here+i,cnt+1) % mod;
        d[here][cnt] %= mod;
    }
    return d[here][cnt]%mod;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    memset(d,-1,sizeof(d));
    cin>>n>>k;
    cout<<f(0,0);
}
