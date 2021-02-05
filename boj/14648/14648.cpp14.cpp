#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll n,t,a[1010];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>t;
    for(int i=1; i<=n; i++) cin>>a[i];
    while(t--){
        ll x,sum=0,from,to,d,c;
        cin>>x;
        if(x == 1){
            cin>>from>>to;
            for(ll i=from; i<=to; i++) sum += a[i];
            cout<<sum<<'\n';
            swap(a[from],a[to]);
        }
        if(x == 2){
            cin>>from>>to>>d>>c;
            for(;from<=to;from++) sum += a[from];
            for(;d<=c;d++) sum -= a[d];
            cout<<sum<<'\n';
        }
    }
}