#include <bits/stdc++.h>

using namespace std;
long long n,arr[101],d[101][21];
long long ans;
long long dfs(int index,int num){
    if(0>num || 20<num) return 0;
    if(index==n-1){
        if(num==arr[n]){
            return 1;
        }
        return 0;
    }
    long long &ret = d[index][num];
    if(ret!=-1) return ret;
    ret=0;
    return ret=dfs(index+1,num+arr[index+1])+dfs(index+1,num-arr[index+1]);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(d,-1,sizeof(d));
    cin>>n;
    for(int i=1; i<=n; i++) cin>>arr[i];
    cout<<dfs(1,arr[1])<<'\n';
}
