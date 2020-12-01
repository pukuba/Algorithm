#include <bits/stdc++.h>

using namespace std;
int n,m,x,arr[201111],ans;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1; i<=n; i++) cin>>arr[i];
    sort(arr+1,arr+n+1);
    for(int i=1; i<=m; i++){
        cin>>x;
        if(binary_search(arr+1,arr+n+1,x)) ans++;
    } cout<<n-ans+m-ans;
}