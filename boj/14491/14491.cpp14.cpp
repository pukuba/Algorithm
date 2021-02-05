#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,cnt=1,ans=0;
    cin>>n;
    while(n){
        ans+=(n%9)*cnt;
        cnt*=10;
        n/=9;
    }
    cout<<ans<<'\n';
}
