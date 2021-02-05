#include <bits/stdc++.h>

using namespace std;
int n,ans;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>n;
    for(int i=3; i<=n; i+=3) for(int j=3; j<=n-i-3; j+=3) ans++;
    cout<<ans;
}
