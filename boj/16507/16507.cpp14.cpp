#include <bits/stdc++.h>

using namespace std;
int n,m,q,psum[1010][1010];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m>>q;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin>>psum[i][j];
            psum[i][j] += psum[i-1][j] + psum[i][j-1] - psum[i-1][j-1];
        }
    }
    while(q--){
        int sy,sx,ey,ex;
        cin>>sy>>sx>>ey>>ex;
        int sz = (ey - sy + 1) * (ex - sx + 1);
        cout<<(psum[ey][ex]-psum[sy-1][ex]-psum[ey][sx-1]+psum[sy-1][sx-1]) / sz<<'\n';
    }
}