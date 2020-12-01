#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pl = pair<ll,ll>;
using plpl = pair<pl,pl>;
pl p[505050];
ll n,mintree[2020202],INF=1e9,MXN=500000,ans,idx;
deque<int> d;
bool cmp(pl a,pl b){
    if(a.first == b.first) return a.first > b.first;
    return a.first > b.first;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++) cin>>p[i].first>>p[i].second;
    sort(p+1,p+1+n,cmp);
    for(int i=1; i<=n; i++){
        if(p[i].second == 1){
            d.push_front(1);
            ans++;
        }
        else{
            ll l = 0,r = d.size()-1,idx=-1;
            while(l<=r){
                ll mid = l + r >> 1;
                if(d[mid] < p[i].second){
                    idx = mid;
                    l = mid + 1;
                }
                else r = mid - 1;
            }
            if(idx != -1) d[idx]++;
            else{
                ans++;
                d.push_front(1);
            }
        }
    }
    cout<<ans<<'\n';
}