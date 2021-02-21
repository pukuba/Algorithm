#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int n;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    while(1){
        ll ans = -1e9,tmp = -1e9;
        cin>>n;
        if(!n) break;
        for(ll i=1,x; i<=n; i++){
            cin>>x;
            tmp = max(x,tmp + x);
            ans = max(tmp,ans);
        }
        cout<<ans<<'\n';
    }
}
