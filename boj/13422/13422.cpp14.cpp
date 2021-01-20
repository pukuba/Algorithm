#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int t,n,m,a[202020],k;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>t;
    while(t--){
        memset(a, 0, sizeof(a));
        ll ans = 0, temp = 0;
        cin>>n>>m>>k;
        for(int i=1; i<=n; i++) cin>>a[i];
        for(int i=n+1; i<=n*2; i++) a[i] = a[i-n];
        for(int i=1; i<=m; i++) temp += a[i];
        if(temp < k) ans ++;
        if(n!=m){
            for(int i=m+1; i<=m+n-1; i++){
                temp -= a[i-m];
                temp += a[i];
                if(temp < k) ans++;
            }
        }
        cout<<ans<<'\n';
    }
}
