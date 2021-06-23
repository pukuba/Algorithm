#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll dp[303030],n,x=1;
vector<int> v;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    memset(dp,0x3f,sizeof(dp));
    cin>>n;
    for(int i=1; i<=n;){
        dp[i] = 1;
        v.push_back(i);
        ++x;
        i += (x * (x+1) ) / 2;
    }
    for(int i : v){
        for(int j=i; j<=n; j++){
            dp[j] = min(dp[j-i]+1,dp[j]);
        }
    }
    cout<<dp[n];
}
