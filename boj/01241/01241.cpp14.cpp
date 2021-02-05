#include <bits/stdc++.h>

using namespace std;
int n,arr[1010101],a[101010];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>a[i];
        arr[a[i]]++;
    }
    for(int i=1; i<=n; i++){
        int ans = 0,j;
        arr[a[i]]--;
        for(j=1; j*j<a[i]; j++) if(a[i]%j == 0) ans+=arr[j],ans+=arr[a[i]/j];
        if(j*j == a[i]) ans+=arr[j];
        arr[a[i]]++;
        cout<<ans<<'\n';
    }
}
