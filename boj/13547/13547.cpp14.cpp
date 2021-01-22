#include <bits/stdc++.h>
#define prev f
using namespace std;
int n,sqrtn,a[111111],m,x,y,ans[111111],cnt[1111111],ans1;
vector<pair<int,int> > v;
vector<pair<pair<int,int>,int> > w;
void add(int x){if(++cnt[x]==1) ans1++;}
void erase(int x){if(!--cnt[x]) ans1--;}
void go(int x){
    pair<int,int> prev={0,0};
    if(x>=1) prev = v[w[x-1].second];
    pair<int,int> now = v[w[x].second];
    for(int i = prev.first-1; i>=now.first; i--) add(a[i]);
    for(int i = prev.second+1; i<=now.second; i++) add(a[i]);
    for(int i = prev.first; i<now.first; i++) erase(a[i]);
    for(int i = prev.second; i>now.second; i--) erase(a[i]);
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
    sort(w.begin(),w.end());
    for(int i=0; i<w.size(); i++){
        go(i);
        ans[w[i].second] = ans1;
    }
    for(int i=0; i<w.size(); i++) cout<<ans[i]<<'\n';
}