#include <bits/stdc++.h>

using namespace std;
int tree[111111],n,m,a[111111];
void update(int idx,int value){
    for(;idx<=n;idx+=(idx& -idx)) tree[idx]+=value;
}
int sum(int i){
    int ret=0;
    for(;i>=1;i-=(i&-i)) ret+=tree[i];
    return ret;
}
int main(){
    ios_base::sync_with_stdio(0),cin.tie(nullptr);
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>a[i];
        if(a[i]%2) update(i,1);
    }
    cin>>m;
    while(m--){
        int type,x,y;
        cin>>type>>x>>y;
        if(type==1){
            if((a[x]%2) && !(y%2)){
                update(x,-1);
                a[x]=y;
            }
            if(!(a[x]%2) && y%2){
                update(x,1);
                a[x]=y;
            }
        }
        if(type==3) cout<<sum(y)-sum(x-1)<<'\n';
        if(type==2) cout<<((y-x)+1)-(sum(y)-sum(x-1))<<'\n';
    }
}
