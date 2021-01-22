#include <bits/stdc++.h>

using namespace std;
int n,m,d[101][101];
bool out[101];
int dfs(int index,int coupon){
    if(coupon<0) return 1e9+7;
    if(index==n+1) return 0;
    if(d[index][coupon]!=-1) return d[index][coupon];
    d[index][coupon]=1e9+7;
    int &ret = d[index][coupon];
    if(out[index]) return ret = dfs(index+1,coupon);
    ret = min({ret,dfs(index+5,coupon+2)+37000,dfs(index+3,coupon+1)+25000,dfs(index+1,coupon)+10000,dfs(index+1,coupon-3)});
    return ret;
}
int main(){
    memset(d,-1,sizeof(d));
    cin>>n>>m;
    for(int i=0; i<m; i++){
        int x;
        cin>>x;
        out[x]=true;
    }
    cout<<dfs(1,0);
}
