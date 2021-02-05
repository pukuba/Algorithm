#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll a,b,c,cnt;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    while(1){
        cin>>a>>b>>c;
        if(!a) break;
        ll ans = 0;
        if(c%b == 0) ans = (c/b)*a;
        else ans = ((c/b)*a) + min(c%b,a);
        cout<<"Case "<<++cnt<<": "<<ans<<'\n';
    }
}