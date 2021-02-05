#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define max_n 200001
int n, value;
ll ret=1;
vector<ll> tree_cnt(200001, 0), tree_value(200001, 0);
void update(vector<ll> &tree,int idx,int value){
    int _idx = idx;
    while(_idx<=200001){
        tree[_idx]+=value;
        _idx+=(_idx& -_idx);
    }
}
ll sum(vector<ll> &tree,int idx){
    ll ans=0;
    int _idx = idx;
    while(_idx>=1){
        ans+=tree[_idx];
        _idx-=(_idx& -_idx);
    }
    return ans;
}
ll sum2(int from, int to,vector<ll> &tree){
    if(from <= to){
        return sum(tree,to) - sum(tree,from-1);
    }
    return 0;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>> value; value++;
        if(i != 1){
            ll left = sum2(1,value-1,tree_cnt)*(value)-(sum2(1,value-1,tree_value));
            ll right=sum2(value + 1, max_n ,tree_value) - value * sum2(value + 1, max_n,tree_cnt);
            ret *= (left + right) % 1000000007;
            ret %= 1000000007;
        }
        update(tree_value,value,value);
        update(tree_cnt,value,1);
    }
    cout<<ret<<'\n';
}
