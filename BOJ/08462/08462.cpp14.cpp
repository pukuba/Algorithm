#include <bits/stdc++.h>
#define prev f
using namespace std;
using pi = pair<int,int>;
using ppi = pair<pi,int>;
vector<pi> v;
vector<ppi> w;
long long ret,ans[111111],n,m,a[111111],x,y,sqrtn,cnt[1111111];
void add(int x){
    ret -= cnt[x] * cnt[x] * x;
    cnt[x]++;
    ret += cnt[x] * cnt[x] * x;
}
void del(int x){
    ret -= cnt[x] * cnt[x] * x;
    cnt[x]--;
    ret += cnt[x] * cnt[x] * x;
}
void go(int x){
    pi prev = {0,0},now = v[w[x].second];
    if(x) prev = v[w[x-1].second];
    for(int i=prev.first-1; i>=now.first; i--) add(a[i]);
    for(int i=prev.second+1; i<=now.second; i++) add(a[i]);
    for(int i=prev.first; i<now.first; i++) del(a[i]);
    for(int i=prev.second; i>now.second; i--) del(a[i]);
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>n>>m;
    sqrtn = sqrt(n);
    for(int i=1; i<=n; i++) cin>>a[i];
    for(int i=0; i<m; i++){
        cin>>x>>y;
        v.push_back({x,y});
        w.push_back({{x/sqrtn,y},i});
    }
    sort(w.begin(),w.end());
    for(int i=0; i<w.size(); i++){
        go(i);
        ans[w[i].second] = ret;
    }
    for(int i=0; i<m; i++) cout<<ans[i]<<'\n';
}