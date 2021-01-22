#include <bits/stdc++.h>

using namespace std;
int d[1111]={1,1,2},mod=10007,n;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    for(int i=3; i<=1000; i++) d[i] = d[i-1] + d[i-2] % mod;
    cin>>n;
    cout<<d[n]%mod;
}