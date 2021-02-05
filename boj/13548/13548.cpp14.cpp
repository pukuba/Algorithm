#include <bits/stdc++.h>
#define prev f
using namespace std;
using pi = pair<int,int>;
using pii = pair<pi,int>;
int check[111111],cnt[111111],n,a[111111],m,x,y,sqrtn,ret,ans[111111];
vector<pi> v;
vector<pii> w;
void add(int x){ ret = max(ret,++cnt[x]); check[cnt[x]]++; check[cnt[x]-1]--;}
void del(int x){
    --check[cnt[x]];
    cnt[x]--;
    ++check[cnt[x]];
    if(ret == cnt[x]+1 && !check[cnt[x]+1]) ret -= 1;
}
void go(int x){
    pi prev = {0,0}, now = v[w[x].second];
    if(x) prev = v[w[x-1].second];
    for(int i=prev.first-1; i>=now.first; i--) add(a[i]);
    for(int i=prev.second+1; i<=now.second; i++) add(a[i]);
    for(int i=prev.first; i<now.first; i++) del(a[i]);
    for(int i=prev.second; i>now.second; i--) del(a[i]);
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>n;
    sqrtn = sqrt(n);
    for(int i=1; i<=n; i++) cin>>a[i];
    cin>>m;
    for(int i=0; i<m; i++){
        cin>>x>>y;
        v.push_back({x,y});
        w.push_back({{x/sqrtn,y},i});
    }
    check[0] = n+1;
    sort(w.begin(),w.end());
    for(int i=0; i<m; i++){
        go(i);
        ans[w[i].second] = ret;
    }
    for(int i=0; i<m; i++) cout<<ans[i]<<'\n';
}