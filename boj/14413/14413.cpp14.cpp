#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

using namespace std;
using ll = long long;
using pi = pair<int,int>;
using ppi = pair<pi,int>;
int n,m,a[505050],b[505050],c[505050],ans;
vector<pi> v;
vector<ppi> w;
vector<int> idx;
int getidx(int x){return lower_bound(idx.begin(), idx.end(), x) - idx.begin();}
void go(int x){
    pi pv = {0,0}, now = v[w[x].second];
    if(x) pv = v[w[x-1].second];
    for(int i=pv.first-1; i>=now.first; i--){
        if(!i) continue;
        ++c[a[i]];
        if(c[a[i]]==2) ans++;
        if(c[a[i]]==3) ans--;
    }
    for(int i=pv.second+1; i<=now.second; i++){
        if(!i) continue;
        ++c[a[i]];
        if(c[a[i]]==2) ans++;
        if(c[a[i]]==3) ans--;
    }
    for(int i=pv.first; i<now.first; i++){
        if(!i) continue;
        --c[a[i]];
        if(c[a[i]]==2) ans++;
        if(c[a[i]]==1) ans--;
    }
    for(int i=pv.second; i>now.second; i--){
        if(!i) continue;
        --c[a[i]];
        if(c[a[i]]==2) ans++;
        if(c[a[i]]==1) ans--;
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    int sqrtN = sqrt(n)+1;
    for(int i=1; i<=n; i++){
        cin>>a[i];
        idx.push_back(a[i]);
    }
    sort(idx.begin(),idx.end());
    idx.erase(unique(idx.begin(),idx.end()),idx.end());
    for(int i=1; i<=n; i++) a[i] = getidx(a[i]);
    for(int i=0,x,y; i<m; i++){
        cin>>x>>y;
        v.push_back({x,y});
        w.push_back({{x/sqrtN,y},i});
    }
    sort(w.begin(),w.end());
    for(int i=0; i<m; i++){
        go(i);
        b[w[i].second] = ans;
    }
    for(int i=0; i<m; i++){
        cout<<b[i]<<'\n';
    }
}