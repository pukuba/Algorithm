#include <bits/stdc++.h>

using namespace std;
const int _max=987654321;
int d[103][1003],n,s,m,arr[103];
int dfs(int index,int vm){
    if(vm>m || 0>vm) return -_max;
    int &ret = d[index][vm];
    if(index==n) return vm;
    if(ret != -1) return ret;
    ret=0;
    return ret=max(dfs(index+1,vm+arr[index+1]),dfs(index+1,vm-arr[index+1]));
}
int main(){
    memset(d,-1,sizeof(d));
    cin>>n>>s>>m;
    for(int i=1; i<=n; i++) cin>>arr[i];
    int ans=dfs(0,s);
    if(ans==-_max) cout<<-1;
    else cout<<ans;
}
