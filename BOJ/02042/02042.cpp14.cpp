#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
ll n,q1,q2;
ll tree[1000001],a[1000001];
ll sum(ll to){
    ll ret = 0;
    while(to > 0){
        ret += tree[to];
        to -= (to & -to);
    }
    return ret;
}
void update(ll idx, ll value){
    while(idx <= n){
        tree[idx] += value;
        idx += (idx & -idx);
    }
    return;
}
int main() {
    cin>>n>>q1>>q2;
    memset(tree, 0, sizeof(tree));
    for(ll i=1; i<=n; i++){
        cin>>a[i];
        update(i, a[i]);
    }
    for(ll i = 1; i <= q1+q2; i++){
        ll b,c,d;
        cin >> b >> c >> d;
        if(b == 1){
            update(c, d - a[c]);
            a[c] = d; 
        }
        else cout << sum(d) - sum(c - 1) << "\n";
    }
    return 0;
}


