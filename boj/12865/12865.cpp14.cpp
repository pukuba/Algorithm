#include <bits/stdc++.h>

using namespace std;
int d[100001],n,m;
int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        int x,y;
        cin>>x>>y;
        for(int j=m; j>=1; j--){
            if(x<=j) d[j]=max(d[j],d[j-x]+y);
        }
    }
    cout<<d[m]<<'\n';
}
