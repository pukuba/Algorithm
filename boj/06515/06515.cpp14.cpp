#include <bits/stdc++.h>
#define prev f
using namespace std;
using pi = pair<int,int>;
using pii = pair<pi,int>;
vector<pi> v;
vector<pii> w;
int a[222222],cnt[222222],n,m,x,y,sqrtn,ret,check[111111],ans[111111];
void add(int x){ret = max(ret,++cnt[x]);check[cnt[x]]++;check[cnt[x]-1]--;}
void del(int x){
    check[cnt[x]]--;
    cnt[x]--;
    check[cnt[x]]++;
    if(ret == cnt[x]+1 && !check[cnt[x]+1]) ret--;
}
void go(int x){
    pi prev = {0,0},now =v[w[x].second];
    if(x) prev = v[w[x-1].second];
    for(int i=prev.first-1; i>=now.first; i--) add(a[i]+100000);
    for(int i=prev.second+1; i<=now.second; i++) add(a[i]+100000);
    for(int i=prev.first; i<now.first; i++){
        if(!i) continue;
        del(a[i]+100000);
    }
    for(int i=prev.second; i>now.second; i--){
        if(!i) continue;
        del(a[i]+100000);
    }
}
int main(){
    while(1){
        cin>>n;
        if(!n) break;
        cin>>m;
        sqrtn = sqrt(n);
        for(int i=1; i<=n; i++) cin>>a[i];
        for(int i=0; i<m; i++){
            cin>>x>>y;
            v.push_back({x,y});
            w.push_back({{x/sqrtn,y},i});
        }
        check[0] = n;
        sort(w.begin(),w.end());
        for(int i=0; i<m; i++){
            go(i);
            ans[w[i].second] = ret;
        }
        for(int i=0; i<m; i++) cout<<ans[i]<<'\n';
        memset(ans,0,sizeof ans);
        v.clear();w.clear();
        memset(a,0,sizeof a);
        memset(check,0,sizeof check);
        memset(cnt,0,sizeof cnt);
        ret = 0;
    }
}