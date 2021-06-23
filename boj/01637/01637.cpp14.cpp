#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;
ll s=1,e,n,ans=-1;
struct pos{ll a,c,b;};
vector<pos> v;
bool cmp(pos a,pos b){return a.a < b.a;}
ll binary(ll x){
    ll ret = 0;
    for(pos i : v){
        if(i.a > x) break;
        ll y = min(x,i.c);
        ll z = (y-i.a) / i.b;
        ret += z + 1;
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++){
        ll x,y,z;
        cin>>x>>y>>z;
        e = max(e,y);
        v.push_back({x,y,z});
    }
    sort(v.begin(),v.end(),cmp);
    while(s <= e){
        ll mid = s + e >> 1;
        if(~binary(mid)&1){
            s = mid + 1;
        } else {
            ans = mid;
            e = mid - 1;
        }
    }
    if(ans != -1){
        cout<<ans<<' '<<binary(ans) - binary(ans-1);
    } else {
        cout<<"NOTHING";
    }
}