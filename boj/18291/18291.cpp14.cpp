#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n,t,mod = 1e9+7;
ll cal(ll a){
    if(a==1) return 2;
    if((a%2)) return cal(a-1) * 2;
    ll ret = cal(a/2);
    ret%=mod;
    return (ret*ret)%mod;
}
int main(){
    cin>>t;
    while(t--){
        cin>>n;
        if(n==1 || n==2) cout<<1<<'\n';
        else cout<<cal(n-2)%mod<<'\n';
    }
}
