#include <bits/stdc++.h>

using namespace std;
int n,k,arr[101010],ans,temp;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>k;
    for(int i=1; i<=k; i++){
        cin>>arr[i];
        temp += arr[i];
    }
    ans = temp;
    for(int i=k+1; i<=n; i++){
        cin>>arr[i];
        temp -= arr[i-k];
        temp += arr[i];
        ans = max(temp,ans);
    }
    cout<<ans<<'\n';
}
