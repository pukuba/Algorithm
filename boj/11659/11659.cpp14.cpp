#include <bits/stdc++.h>

using namespace std;
long long tree[100001];
int n,m,arr[100001];
void update(int index,int num){
    for(;index<=n;index+=(index& -index)) tree[index]+=num;
}
long long sum(int idx){
    long long ans=0;
    for(;idx>=1;idx-=(idx& -idx)) ans+=tree[idx];
    return ans;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        cin>>arr[i];
        update(i,arr[i]);
    }
    while(m--){
        int x,y;
        cin>>x>>y;
        cout<<sum(y)-sum(x-1)<<'\n';
    }
}
