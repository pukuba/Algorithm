#include <bits/stdc++.h>

using namespace std;
int n,d[1111111]={1,1},mod=15746;// 1 ,
// 2
// 3 001,100,111
// 5
// 8 00111 10011 11001 00001 10000 00100 11111 11100
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>n;
    for(int i=2; i<=n; i++) d[i] = (d[i-1] + d[i-2]) % 15746;
    cout<<d[n];
}