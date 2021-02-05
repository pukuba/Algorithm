#include <bits/stdc++.h>

using namespace std;
int gcd(int a,int b){return b ? gcd(b,a%b) : a;}
int n,m;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    cout<<(n+m - gcd(n,m));
}