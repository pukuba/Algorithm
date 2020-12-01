#include <bits/stdc++.h>

using namespace std;
int n,m,d[1004][1004];
pair<int,int> p[1004];
int dfs(int idx,int police1,int police2){
    int &ret = d[police1][police2],cal1=0,cal2=0;
    int cal = 0;
    if(police1 == idx) cal=1;
    else cal=2;
    if(idx == m) return ret = 0;
    if(ret != -1) return ret;
    ret = 0;
    if(!police1) cal1 = abs(p[idx+1].first - 1) + abs(p[idx+1].second - 1);
    else cal1 = abs(p[idx+1].first - p[police1].first) + abs(p[idx+1].second - p[police1].second);
    if(!police2) cal2 = abs(p[idx+1].first - n) + abs(p[idx+1].second - n);
    else cal2 = abs(p[idx+1].first - p[police2].first) + abs(p[idx+1].second - p[police2].second);
    return ret = min(dfs(idx+1,idx+1,police2)+cal1,dfs(idx+1,police1,idx+1)+cal2);
}
void _prev(int idx,int police1,int police2){
    if(idx == m) return ;
    int next = max(police1,police2)+1;
    int go1,go2,cal1,cal2;
    if(!police1) go1 = abs(1-p[next].first) + abs(1-p[next].second);
    else go1 = abs(p[police1].first - p[next].first) + abs(p[police1].second - p[next].second);
    cal1 = d[next][police2] + go1;
    if(!police2) go2 = abs(n-p[next].first) + abs(n-p[next].second);
    else go2 = abs(p[police2].first-p[next].first) + abs(p[police2].second-p[next].second);
    cal2 = d[police1][next] + go2;
    if(cal1 > cal2){
        cout<<2<<'\n';
        _prev(idx+1,police1,next);
    }
    else{
        cout<<1<<'\n';
        _prev(idx+1,next,police2);
    }
}
int main(){
    memset(d,-1,sizeof(d));
    cin>>n>>m;
    for(int i=1; i<=m; i++) cin>>p[i].first>>p[i].second;
    cout<<dfs(0,0,0)<<'\n';
    _prev(0,0,0);
}
