#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n,k,_max=100001,_min=1,ret;
bool check(ll a){
    ll res=0;
    for(ll i=1; i<=n; i++){
        res += min(n, a / i);
    }
    return res >= k;
}
int main(){
    cin>>n>>k;
    ll lo = 1;
    ll hi = n * n;
    ll mid = (lo + hi) / 2;
    while(lo <= hi){
        mid = (lo + hi)/ 2;
        if(check(mid)){
            hi=mid-1;
            ret = mid;
        }
        else lo=mid+1;
    }
    cout << ret << "\n";
}
