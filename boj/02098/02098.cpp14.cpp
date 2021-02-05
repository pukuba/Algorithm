#include <bits/stdc++.h>

using namespace std;
int n,d[17][1<<17],_map[17][17],inf=1e9;
int dfs(int here,int check){
    int &ret = d[here][check];
    if(ret != -1) return ret;
    if(check == (1<<n)-1){
        if(_map[here][1] != 0) return _map[here][1];
    }
    ret = inf;
    for(int i=1; i<=n; i++){
        if(check&(1<<(i-1)) || _map[here][i]==0) continue;
        ret = min(ret,dfs(i,check | (1<<(i-1)))+_map[here][i]);
    }
    return ret;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    memset(d,-1,sizeof(d));
    cin>>n;
    for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) cin>>_map[i][j];
    cout<<dfs(1,1);
}
