#include <bits/stdc++.h>
#define prev f

using namespace std;
using pi = pair<int,int>;
using pii = pair<pi,int>;
vector<pi> v;
vector<pii> w;
pi ans[11111],can;
int n,c,m,a[311111],x,y,sqrtn,cnt[11111],check[311111],dist;
void add(int x){++check[++cnt[x]];check[cnt[x]-1]--;}
void del(int x){++check[--cnt[x]];check[cnt[x]+1]--;}
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
    cin>>n>>c;
    sqrtn = sqrt(n);
    for(int i=1; i<=n; i++) cin>>a[i];
    cin>>m;
    check[0] = n;
    for(int i=0; i<m; i++){
        cin>>x>>y;
        v.push_back({x,y});
        w.push_back({{x/sqrtn,y},i});
    }
    sort(w.begin(),w.end());
    for(int i=0; i<m; i++){
        go(i);
        can = {0,0};
        dist = v[w[i].second].second - v[w[i].second].first + 1;
        for(int j=1; j<=c; j++){
            if(can.first < cnt[j]) can = {cnt[j],j};
            if(can.first > dist) break;
        }
        if(can.first > dist>>1) ans[w[i].second] = {1,can.second};
    }
    for(int i=0; i<m; i++){
        if(ans[i].first) cout<<"yes "<<ans[i].second<<'\n';
        else cout<<"no\n";
    }
}