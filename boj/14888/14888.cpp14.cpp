#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int n,a[22],t[4];
ll _min=2e9,_max=-2e9; //+ - * /
void go(ll sum,int idx){
    if(idx > n){
        _min = min(sum,_min);
        _max = max(sum,_max);
        return;
    }
    for(int i=0; i<4; i++){
        if(t[i]){
            t[i]-=1;
            if(i == 0) go(sum+a[idx],idx+1);
            if(i == 1) go(sum-a[idx],idx+1);
            if(i == 2) go(sum*a[idx],idx+1);
            if(i == 3) go(sum/a[idx],idx+1);
            t[i]+=1;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i];
    for(int i=0; i<4; i++) cin>>t[i];
    go(a[1],2);
    cout<<_max<<'\n'<<_min<<'\n';
}