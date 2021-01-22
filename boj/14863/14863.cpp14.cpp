#include <bits/stdc++.h>

using namespace std;
int n,t,d[101][100001];
pair<int,int> p[101],q[101];
int dfs(int here, int _time){
    if(here == n + 1) return 0;
    if(d[here][_time] != - 1) return d[here][_time];
    int &ret = d[here][_time];
    ret = -1e9;
    int a=-1e9,b=-1e9;
    if(_time-p[here].first >= 0) a = dfs(here+1,_time-p[here].first)+p[here].second;
    if(_time-q[here].first >= 0) b = dfs(here+1,_time-q[here].first)+q[here].second;
    return ret = max(a,b);
}
int main(){
    memset(d,-1,sizeof(d));
    cin>>n>>t;
    for(int i=1; i<=n; i++) cin>>p[i].first>>p[i].second>>q[i].first>>q[i].second;
    cout<<dfs(0,t);
}
