#include <bits/stdc++.h>

using namespace std;
int n,arr[14],_max,ans;
bool check[4000001];
void dfs(int sum,int i){
    if(i==n+1){
        if(sum>0) check[sum]=true;
        return ;
    }
    dfs(sum-arr[i],i+1);
    dfs(sum+arr[i],i+1);
    dfs(sum,i+1);
}
int main(){
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>arr[i];
        _max+=arr[i];
    }
    dfs(0,1);
    for(int i=1; i<=_max; i++){
        if(!check[i]) ans++;
    }
    cout<<ans;
}

