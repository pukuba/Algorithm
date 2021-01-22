#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int n,m;
ll tree[1000001];
void update(int idx,int value){
    for(int i=idx; i<=n; i+=(i& -i)) tree[i]+=value;
}
ll sum(int idx){
    ll ret = 0;
    for(int i=idx; i>=1; i-=(i& - i)) ret += tree[i];
    return ret;
}
int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin>>n>>m;
    while(m--){
        int a,b,c;
        cin>>a>>b>>c;
        if(a==1) update(b,c);
        if(a==2) cout<<sum(c)-sum(b-1)<<'\n';
    }
}
