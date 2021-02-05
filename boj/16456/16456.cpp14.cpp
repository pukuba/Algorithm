#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll d[51111]={0,1,1,2,3,4},mod = 1e9+9,n;
// 0 1 1 2 2 4
// 1 1 1 / 1 2 -1 / 2 -1 2
// 1 1 1 1 1 / 1 2 -1 2 1 / 1 1 2 -1 2 / 2 -1 2 1 1 / 1 1 1 2 -1 / 2 -1 2 2 -1
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    for(int i=5; i<=50044; i++){
        d[i] = d[i-3] + d[i-1];
        d[i]%=mod;
    }
    cin>>n;
    cout<<d[n]%mod;
}