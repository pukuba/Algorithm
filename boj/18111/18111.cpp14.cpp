#include <bits/stdc++.h>
using ll = long long;
using namespace std;
ll n,m,k,arr[505][505];
struct p{
    ll t,h;
    bool operator < (const p &a) const{
        if(t == a.t){
            return h > a.h;
        }
        return t < a.t;
    }
};
vector<p> ans;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m>>k;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin>>arr[i][j];
        }
    }
    for(int h=0; h<=256; h++){
        ll tmp = 0, ret = 0;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(arr[i][j] >= h){
                    ret += (arr[i][j] - h) * 2;
                    tmp -= (arr[i][j] - h);
                }
                else{
                    ret += (h - arr[i][j]);
                    tmp += h - arr[i][j];
                }
            }
        }
        if(tmp <= k){
            ans.push_back({ret,h});
        }
    }
    sort(ans.begin(),ans.end());
    cout<<ans.front().t<<' '<<ans.front().h<<'\n';
}
