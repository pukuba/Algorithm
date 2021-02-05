#include <bits/stdc++.h>

using namespace std;
int n,m,d[51][111];
pair<int,int> p[51];
int dfs(int idx,int num){
    if(num >= n) return 0;
    if(idx > m) return 1e9;
    int &ret = d[idx][num];
    if(ret != -1) return ret;
    return ret = min({dfs(idx,num+6)+p[idx].first,dfs(idx,num+1)+p[idx].second,dfs(idx+1,num)});
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    memset(d,-1,sizeof(d));
    cin>>n>>m;
    for(int i=1; i<=m; i++) cin>>p[i].first>>p[i].second;
    cout<<dfs(1,0)<<'\n';
}