#include <bits/stdc++.h>

using namespace std;
int d[1001][31][2],t,w,arr[1001];
int dfs(int time,int count,int type){
    if(time>t || count>w) return 0;
    int &ret = d[time][count][type];
    if(ret!=-1) return ret;
    int plus=0;
    if(arr[time] == type+1) plus++;
    ret=0;
    return ret=max({dfs(time+1,count,type),dfs(time,count+1,!type)})+plus;
}
int main(){
    memset(d,-1,sizeof(d));
    cin>>t>>w;
    for(int i=1; i<=t; i++) cin>>arr[i];
    int ans=0;
    cout<<dfs(1,0,0);
}
