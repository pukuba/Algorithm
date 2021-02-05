#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n,a[11111];
ll ans;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>n;
    for(int i=1,x; i<=n; i++){
        cin>>x;
        a[x]++;
    }
    for(ll i=1; i<=10000; i++){
        if(a[i]){
            if(a[i] >= 1) ans += i*i*((a[i]-1) * a[i])/2;
            for(ll j=i+1; j<=10000; j++){
                if(!a[j]) continue;
                ans += i*a[i]*j*a[j];
            }
        }
    }
    cout<<ans<<'\n';
}