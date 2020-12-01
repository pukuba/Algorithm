#include <bits/stdc++.h>

using namespace std;
int n,cnt=1,ans;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>n;
    while(n>=1){
        n-=cnt;
        if(cnt == 1) cnt+=5;
        else cnt+=6;
        ans++;
    }
    // 8 = 2
    cout<<ans<<'\n';
}