#include <bits/stdc++.h>
#define prev f

using namespace std;
using pi = pair<int,int>;
using pii = pair<pi,int>;
vector<pi> v;
vector<pii> w;
int n,m,q,a[322222],cnt[11111],check[333333],x,y,sqrtn;
vector<int> cc[333333];
pii ret;
pi ans[11111];
void add(int x){
    cnt[x]++;
    check[cnt[x]-1]--;
    check[cnt[x]]++;
    if(ret.first.first < cnt[x]){
        ret.first.first = cnt[x];
        ret.first.second = x;
    }
}
void del(int x){
    check[cnt[x]]--;
    cnt[x]--;
    check[cnt[x]]++;
    if(ret.first.first == cnt[x]+1 && !check[cnt[x]+1]) ret.first = {ret.first.first-1,ret.first.second};
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
    sqrtn =  sqrt(n);
    for(int i=1; i<=n; i++) cin>>a[i];
    cin>>q;
    for(int i=0; i<q; i++){
        cin>>x>>y;
        v.push_back({x,y});
        w.push_back({{x/sqrtn,y},i});
    }
    sort(w.begin(),w.end());
    check[0] = n;
    for(int i=0; i<q; i++){
        ret.second = v[w[i].second].second-v[w[i].second].first+1;
        go(i);
        if(ret.second/2 < ret.first.first) ans[w[i].second] = {1,ret.first.second};
        else ans[w[i].second] = {0,0};
        if(ans[w[i].second].first){
            if(cnt[ret.first.second] <= ret.second/2){
                for(int j=1; j<=m; j++){
                    if(cnt[j]>ret.second/2){
                        ans[w[i].second].second = j;
                        ret.first.second = j;
                        break;
                    }
                }
            }
        }
    }
    for(int i=0; i<q; i++){
        if(ans[i].first)cout<<"yes"<<' '<<ans[i].second<<'\n';
        else cout<<"no\n";
    }
}