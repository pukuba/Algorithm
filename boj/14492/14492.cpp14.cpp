#include <bits/stdc++.h>

using namespace std;
int n,ans,a[303][303],b[303][303],c[303][303];
int main(){
    cin>>n;
    for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) cin>>a[i][j];
    for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) cin>>b[i][j];
    for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) for(int k=1; k<=n; k++) c[i][j] |= (a[i][k] & b[k][j]);
    for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) ans += c[i][j];
    cout<<ans;
}