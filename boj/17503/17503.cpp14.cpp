#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n,m,k,s,e,ans=1e18;
vector<pair<ll,ll>> v;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>n>>m>>k;
    for(ll i=1,x,y; i<=k; i++){
        cin>>x>>y;
        v.push_back({y,x});
    }
    sort(v.begin(),v.end());
    s=1,e=1e13;
    while(s<=e){
        ll mid = s + e >> 1,can = 0,t = 0,go = 0;
        vector<ll> temp;
        for(int i=0; i<v.size(); i++){
            if(v[i].first <= mid) temp.push_back(v[i].second);
            else break;
        }
        sort(temp.rbegin(),temp.rend());
        if(temp.size() >= n){
            go = 1;
            for(int i=0; i<n; i++) can += temp[i];
        }
        if(can >= m && go){
            ans = min(ans,mid);
            e = mid - 1;
        }
        else s = mid + 1;
    }
    cout<<(ans == 1e18 ? -1 : ans);
}