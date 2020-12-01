#include <bits/stdc++.h>
#define prev f
using namespace std;
using pi = pair<int,int>;
using pii = pair<pi,int>;
int a[1001111],n,m,x,y,keys,cnt[1001111],sqrtn,ans[1001111],ret,c[1001111];
vector<int> idx;
vector<pi> v;
vector<pii> w;
int getidx(int x){return lower_bound(idx.begin(), idx.end(), x) - idx.begin();}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>n;
    sqrtn = sqrt(n);
    for(int i=1; i<=n; i++){
        cin>>a[i];
        c[i] = a[i];
        idx.push_back(a[i]);
    }
    sort(idx.begin(),idx.end());
    idx.erase(unique(idx.begin(),idx.end()),idx.end());
    cin>>m;
    for(int i=1; i<=n; i++) a[i] = getidx(a[i]);
    for(int i=0; i<m; i++){
        cin>>x>>y;
        v.push_back({x,y});
        w.push_back({{x/sqrtn,y},i});
    }
    sort(w.begin(),w.end());
    for(int x=0; x<m; x++){
        pi prev = {0,0},now = v[w[x].second];
        if(x) prev = v[w[x-1].second];
        for(int i=prev.first-1; i>=now.first; i--){
            if(!c[i]) continue;
            if(++cnt[a[i]] == 1) ret++;
        }
        for(int i=prev.second+1; i<=now.second; i++){
            if(!c[i]) continue;
            if(++cnt[a[i]] == 1) ret++;
        }
        for(int i=prev.first; i<now.first; i++){
            if(!c[i]) continue;
            if(!--cnt[a[i]]) ret--;
        }
        for(int i=prev.second; i>now.second; i--){
            if(!c[i]) continue;
            if(!--cnt[a[i]]) ret--;
        }
        
        ans[w[x].second] = ret;
    }
    for(int i=0; i<m; i++) cout<<ans[i]<<'\n';
}