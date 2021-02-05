#include <bits/stdc++.h>

using namespace std;
int n,m,x,ans1;
map<int,int> a;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        cin>>x;
        a.insert({x,i});
    }
    for(int i=1; i<=m; i++){
        cin>>x;
        if(a[x] > 0) ans1++;
    } cout<<n-ans1+m-ans1;
}