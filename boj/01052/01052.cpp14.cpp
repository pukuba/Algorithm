#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll n,k;
ll ans = 1e9;
bool can(int x){
    int y = 1,real = n + x,ret = 0;
    for(;y<=real;y*=2);
    while(real){
        if(real >= y){
            real -= y;
            ret++;
        }
        y /= 2;
    }
    return ret <= k;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>k;
    for(ll i=0; i<=8388608; i++){
        if(can(i)){
            ans = min(ans,i);
        }
    }
    if(can(0)) ans = min(ans,1ll*0);
    cout<<(ans == 1e9 ? -1 : ans) <<'\n';
}