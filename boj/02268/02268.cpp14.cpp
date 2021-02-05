#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
ll tree[1000001],a[1000001];
void update(int idx,int value){
    while(idx<=n){
        tree[idx]+=value;
        idx+=(idx&-idx);
    }
}
ll sum(int idx){
    ll ans=0;
    while(idx){
        ans+=tree[idx];
        idx-=(idx& -idx);
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1; i<=m; i++){
        int q;cin>>q;
        if(!q){
            int x,y;
            cin>>x>>y;
            if(x>y){
                swap(x,y);
            }
            long long ans1=sum(x-1);
            long long ans2=sum(y);
            cout<<ans2-ans1<<'\n';
        }
        else{
            int x,y;
            cin>>x>>y;
            update(x,y - a[x]);
            a[x] = y;
        }
    }
}
