#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll a,b,c=1e9+7;
__int128_t f(ll cnt){
    if(cnt == 0) return 1;
    if(cnt == 1) return a%c;
    if(cnt&1) return (__int128_t) (f(cnt-1) * a) % c;
    __int128_t ret = f(cnt/2)%c;
    return (__int128_t)((ret*ret)%c)%c;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>a>>b;
    __int128_t ans = (f(b))%c;
    cout<<ll(ans);
}