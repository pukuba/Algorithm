#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int n;
bool check[1010101];
vector<ll> v;
void mk(ll x){
    v.push_back(x);
    if(x%10 == 0) return;
    int mx = x%10;
    x*=10;
    for(int k=mx-1; k>=0; k--){
        mk(x+k);
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i=0; i<=9; i++) mk(i);
    sort(v.begin(),v.end());
    cout<<(v.size() <= n ? -1 : v[n]);
}
