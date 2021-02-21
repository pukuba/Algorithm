#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll dp[36]={1,1,2};
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    for(int i=3; i<=35; i++){
        for(int j=0; j<=i-1; j++){
            dp[i] += dp[i-1-j] * dp[j];
        }
    }
    int n;
    cin>>n;
    cout<<dp[n];
}
