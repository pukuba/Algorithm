#include <bits/stdc++.h>

using namespace std;
int gcd(int a,int b){return b ? gcd(b,a%b) : a;}
int a,b;
char c;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>a>>c>>b;
    cout<<a/gcd(a,b)<<':'<<b/gcd(a,b);
}