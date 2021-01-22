#include <bits/stdc++.h>

using namespace std;
string s[51];
int n,ans=1e9,check[51];
int main(){
    cin>>n;
    for(int i=1; i<=n; i++) cin>>s[i];
    for(int i=0; i<s[1].size(); i++) for(int j=1; j<=n; j++) if(s[1][i] != s[j][i]) check[i]++;
    for(int i=0; i<s[1].size(); i++) cout<<(check[i] ? '?':s[1][i]);
}