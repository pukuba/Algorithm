#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n,m,k,s,e,ans=1e18;
vector<pair<ll,ll>> v;
bool check(ll mid){
    ll sum = 0,cnt = 0;
    for(int i=0; i<v.size(); i++){
        if(v[i].second <= mid){
            cnt++;
            sum += v[i].first;
        }
        if(cnt == n) break;
    }
    if(cnt < n || sum < m) return false;
    return true;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>n>>m>>k;
    for(ll i=1,x,y; i<=k; i++){
        cin>>x>>y;
        v.push_back({x,y});
    }
    sort(v.rbegin(),v.rend());
    s=1,e=1e13;
    while(s<=e){
        ll mid = s + e >> 1;
        if(check(mid)){
            e = mid-1;
            ans = min(ans,mid);
        }
        else s = mid + 1;
    }
    cout<<(ans == 1e18 ? -1 : ans);
}