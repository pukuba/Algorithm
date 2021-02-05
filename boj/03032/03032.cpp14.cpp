#include <bits/stdc++.h>

using namespace std;
int d[104][104],arr[104],n,x,sum,ans;
int f(int s,int e,int r){
    if(r == n-1) return 0;
    if(d[s][e] != -1) return d[s][e];
    int ns = s==1 ? n : s-1,ne = e==n ? 1 : e+1;
    if(r&1) return d[s][e] = max(f(s,ne,r+1)+arr[ne],f(ns,e,r+1)+arr[ns]);
    return d[s][e] = min(f(s,ne,r+1),f(ns,e,r+1));
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    memset(d,-1,sizeof(d));
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>x;
        if(x&1) arr[i]++,sum++;
    }
    for(int i=1; i<=n; i++) ans += f(i,i,0)+arr[i] > sum/2;
    cout<<ans;
}