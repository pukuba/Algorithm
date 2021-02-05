#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll tree[222222],tree2[222222],n,m,a[111111];
void update(int i,int value){
    for(;i<=n;i+=(i&-i)) tree[i]+=value;
}
void update1(int i,int value){
    for(;i<=n;i+=(i&-i)) tree2[i]+=value;
}
ll sum1(int i){
    int ret = 0;
    for(;i>=1;i-=(i& -i)) ret += tree[i];
    return ret;
}
ll sum2(int i){
    int ret = 0;
    for(;i>=1;i-=(i& -i)) ret += tree2[i];
    return ret;
}
int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>a[i];
        if(a[i]%2) update(i,1);
        else update1(i,1);
    }
    cin>>m;
    while(m--){
        int type,x,y;
        cin>>type>>x>>y;
        if(type == 1){
            if(a[x]%2 == y%2) continue;
            else{
                if(a[x]%2){
                    update1(x,1);
                    update(x,-1);
                    a[x]=y;
                }
                else{
                    update1(x,-1);
                    update(x,1);
                    a[x]=y;
                }
            }
        }
        if(type == 2) cout<<sum2(y)-sum2(x-1)<<'\n';
        if(type == 3) cout<<sum1(y)-sum1(x-1)<<'\n';
    }
}
