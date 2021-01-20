#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll a[222],n,ans,b[222];
vector<ll> adj[222];
bool check[444];
ll gcd(ll i,ll j){return j ? gcd(j,i%j) : i;}
bool dfs(int here){
    check[here] = true;
    for(int next : adj[here]){
        if(b[next] == -1 || !check[b[next]] && dfs(b[next])){
            b[next] = here;
            return true;
        }
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i];
    for(int i=1; i<=n; i++) a[i] = pow(a[i],2);
    for(int i=1; i<=n; i++) for(int j=1; j<=n; j++){
        if(j == i) continue;
        if(gcd(sqrt(a[i]),sqrt(a[j])) != 1) continue;
        ll test = sqrt(a[i] + a[j]);
        if(test - sqrt(a[i] + a[j]) == 0) adj[i].push_back(j);
    }
    memset(b,-1,sizeof(b));
    for(int i=1; i<=n; i++){
        memset(check,false,sizeof(check));
        if(dfs(i)) ans++;
    }
    cout<<ans/2<<'\n';
}