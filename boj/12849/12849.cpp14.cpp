#include <bits/stdc++.h>

using namespace std;
long long n,d[9][100001],mod= 1e9+7;
long long dfs(int idx,int k){
    if(d[idx][k]!=-1) return d[idx][k];
    if(k==n && idx==0) return 1;
    if(k==n) return 0;
    d[idx][k]=0;
    long long ans=0;
    if(idx==0){
        ans+=dfs(1,k+1)+dfs(2,k+1);
        ans%=mod;
    }
    if(idx==1){
        ans+=dfs(2,k+1)+dfs(3,k+1)+dfs(0,k+1);
        ans%=mod;
    }
    if(idx==2){
        ans+=dfs(0,k+1)+dfs(1,k+1)+dfs(3,k+1)+dfs(4,k+1);
        ans%=mod;
    }
    if(idx==3){
        ans+=dfs(1,k+1)+dfs(2,k+1)+dfs(4,k+1)+dfs(5,k+1);
        ans%=mod;
    }
    if(idx==4){
        ans+=dfs(2,k+1)+dfs(3,k+1)+dfs(5,k+1)+dfs(7,k+1);
        ans%=mod;
    }
    if(idx==5){
        ans+=dfs(3,k+1)+dfs(4,k+1)+dfs(6,k+1);
        ans%=mod;
    }
    if(idx==6){
        ans+=dfs(5,k+1)+dfs(7,k+1);
        ans%=mod;
    }
    if(idx==7){
        ans+=dfs(4,k+1)+dfs(6,k+1);
        ans%=mod;
    }
    return d[idx][k]=ans;
}
int main(){
    cin>>n;
    memset(d,-1,sizeof(d));
    cout<<dfs(0,0);
}
