#include <bits/stdc++.h>

using namespace std;
int n,sum,m;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>n;
    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        m = max(m,x);
        sum += x;
    }
    cout<<sum-m;
}