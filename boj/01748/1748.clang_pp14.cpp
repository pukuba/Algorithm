#include <bits/stdc++.h>

using namespace std;
int n,x,ans;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>n;
    for(int i=1; i<=n; i++){
        x = i;
        while(x){
            x/=10;
            ans++;
        }
    }
    cout<<ans<<'\n';
}