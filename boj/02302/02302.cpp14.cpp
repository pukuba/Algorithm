#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll n,t,x,check[44],d[42]={1,1,2},ans = 1,c;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    for(ll i=3; i<=40; i++) d[i] = d[i-1] + d[i-2];
    cin>>n>>t;
    while(t--){
        cin>>x;
        check[x] = 1;
    }
    for(ll i=1; i<=n; i++){
        if(check[i]) ans *= d[c],c=0;
        else c++;
    }
    cout<<ans * d[c]<<'\n';
    // 1
    // 1 2, 2 1
    // 1 2 3, 1 3 2, 2 1 3
    // 1 2 3 4, 1 2 4 3, 2 1 3 4, 2 1 4 3, 1 3 2 4
    
}