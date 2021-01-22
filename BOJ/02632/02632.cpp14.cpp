#include <bits/stdc++.h>

using namespace std;
int n,m,d1[2002],d2[2002],psum1[2002],psum2[2002],k,ans,cnt1[2000002],cnt2[2000002];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>k>>n>>m;
    for(int i=1; i<=n; i++){
        cin>>d1[i];
        d1[i+n]=d1[i];
        psum1[i]=psum1[i-1]+d1[i];
    }
    for(int i=n+1; i<=n*2; i++) psum1[i]=psum1[i-1]+d1[i-n];
    for(int i=1; i<=m; i++){
        cin>>d2[i];
        psum2[i]=psum2[i-1]+d2[i];
    }
    for(int i=m+1; i<=m*2; i++) psum2[i]=psum2[i-1]+d2[i-m];
    for(int i=1; i<=n; i++){
        for(int j=i; j<n+i; j++){
            long long temp = psum1[j]-psum1[j-i];
            if(i==n){
                if(temp <= k) cnt1[temp]++;
                break;
            }
            if(temp > k) continue;
            cnt1[temp]++;
        }
    }
    for(int i=1; i<=m; i++){
        for(int j=i; j<m+i; j++){
            long long temp = psum2[j]-psum2[j-i];
            if(i == m){
                if(temp <= k)cnt2[temp]++;
                break;
            }else{
                if(temp > k) continue;
                cnt2[temp]++;
            }
        }
    }
    ans += cnt1[k]; ans += cnt2[k];
    for(int i = 1; i < k; i++){
        ans += cnt1[k - i] * cnt2[i];
    }
    cout<<ans<<'\n';
}
