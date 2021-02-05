#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
using pi = pair<int,int>;
using ppi = pair<ll,pi>;
int n,arr[111111];
ppi make(ll a,int b,int c){return {a,{b,c}};}
ppi f(int from,int to){
    if(from + 1 == to) return make((ll)arr[from] * arr[from],from,from);
    int mid = from+to>>1;
    ppi ret = max(f(from,mid),f(mid,to));
    int l = mid, r = mid, _min = arr[mid];
    ll sum = arr[mid];
    while(r - l + 1 < to - from){
        int left_go = -1, right_go = -1;
        if(from < l) left_go = arr[l-1];
        if(r < to-1) right_go = arr[r+1];
        if(left_go >= right_go){
            l--;
            sum+=arr[l];
            _min = min(_min,arr[l]);
        }
        else{
            r++;
            sum+=arr[r];
            _min = min(_min,arr[r]);
        }
        ret = max(make((ll)sum*_min,l,r),ret);
    }
    return ret;
}
int main(){
    ios_base::sync_with_stdio(0),cin.tie(nullptr);
    cin>>n;for(int i=1; i<=n; i++) cin>>arr[i];
    ppi ans = f(1,n+1);
    cout<<ans.first<<'\n'<<ans.second.first<<' '<<ans.second.second;
}
