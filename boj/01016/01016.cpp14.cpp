#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll _min,_max,ans;
bool check[1111111],prime[1111111];
vector<ll> p;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>_min>>_max;
    for(ll i=2; i <= sqrt(_max); i++) if(!prime[i]){
        p.push_back(i*i);
        for(ll j = i+i; j<=sqrt(_max); j+=i) prime[j]=true;
    }
    for(ll i = 0; i<p.size(); i++) for(ll j = _min%p[i]==0?_min:_min+p[i]-(_min%p[i]); j<=_max; j+=p[i]) check[j-_min+1]=true;
    for(ll i = _min; i<=_max; i++) if(!check[i-_min+1]) ans++;
    cout<<ans;
}
