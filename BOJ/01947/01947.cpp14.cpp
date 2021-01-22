#include <bits/stdc++.h>

using namespace std;
int n,m;
using ll = long long;
// 0 1 2 9 44 265
// d[i-1] * i + d[i-2] * i = d[i]
vector<int> v;
ll d[1010101]={0,1,2,9},mod = 1e9;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    for(int i=4; i<=1000000; i++){
        d[i] = d[i-1] * i + d[i-2] * i;
        d[i]%=mod;
    }
    cin>>n;
    cout<<d[n-1];
}

