#include <bits/stdc++.h>

using namespace std;
int n,ans,cnt,t,a,b;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>t;
    while(t--){
        cin>>a>>b;
        n = b-a;
        ans = 0;
        cnt=1;
        while(n>0){
            n-=cnt;
            ans++;
            if(n<=0) break;
            n-=cnt;
            ans++;
            cnt++;
        }
        cout<<ans<<'\n';
    }
}