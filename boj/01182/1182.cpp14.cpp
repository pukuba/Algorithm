#include <bits/stdc++.h>

using namespace std;
int arr[21],n,m,ans;
void dfs(int go,int sum){
    sum+=arr[go];
    if(go > n) return;
    if(sum == m) ans++;
    dfs(go+1,sum-arr[go]);
    dfs(go+1,sum);
}
int main(){
    cin>>n>>m;
    for(int i=1; i<=n; i++) cin>>arr[i];
    dfs(1,0);
    cout<<ans<<'\n';
}
