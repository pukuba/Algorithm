#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll a[1111],n,c,ans,cnt;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i];
    cin>>c;
    for(int i=1; i<=n; i++){
        cnt = 0;
        if(a[i]) cnt = a[i]/c + ((a[i]%c) > 0);
        ans += cnt * c;
    }
    cout<<ans;
}