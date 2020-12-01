#include <bits/stdc++.h>

using namespace std;
int a[17],s,n,ans;
bool can[3333333];
void f(int here,int sum){
    if(here == n) {
        //cout<<sum<<'\n';
        if(sum > 0) can[sum] = 1;
        return;
    }
    f(here+1,sum+a[here+1]);
    f(here+1,sum);
    f(here+1,sum-a[here+1]);
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i],s+=a[i];
    f(0,0);
    for(int i=1; i<=s; i++) ans += !can[i];
    cout<<ans<<'\n';
}