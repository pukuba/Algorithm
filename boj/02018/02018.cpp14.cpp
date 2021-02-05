#include <bits/stdc++.h>

using namespace std;
int n,sum[5050],ans,k;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    int l = 1, r = 1;
    while(l<=r && r<=n+1){
        if(k < n){
            k += r;
            r++;
        }
        else if(k > n){
            k -= l;
            l++;
        }
        else{
            ans++;
            k += r;
            r++;
        }
    }
    cout<<ans<<'\n';
}
