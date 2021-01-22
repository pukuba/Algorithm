#include <bits/stdc++.h>

using namespace std;
int x,y,n,m,t,yt,xt;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>m>>n>>x>>y>>t;
    x+=t;y+=t;
    xt = x/m; yt  = y/n;
    x%=m; y%=n;
    if(xt&1) cout<<m-x<<' ';
    else cout<<x<<' ';
    if(yt&1) cout<<n-y<<' ';
    else cout<<y<<' ';
}