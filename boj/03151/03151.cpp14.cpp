#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int n;
ll ans;
vector<int> v;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    v.resize(n);
    for(int&x:v) cin>>x;
    sort(v.begin(),v.end());
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            int sum = v[i] + v[j];
            int l = lower_bound(v.begin() + j + 1, v.end(),sum*-1) - v.begin();
            int r = upper_bound(v.begin() + j + 1, v.end(),sum*-1) - v.begin();
            ans += (r-l);
        }
    }
    cout<<ans<<'\n';
}