#include <bits/stdc++.h>

using namespace std;
int n,m,k,J[1010][1010],I[1010][1010],O[1010][1010],sy,sx,ey,ex,cnt;
char x;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>n>>m>>k;
    for(int i=1; i<=n; i++) for(int j=1; j<=m; j++){
        cin>>x;
        if(x == 'J') J[i][j] = J[i-1][j] + J[i][j-1] - J[i-1][j-1]+ 1;
        if(x == 'I') I[i][j] = I[i-1][j] + I[i][j-1] - I[i-1][j-1]+ 1;
        if(x == 'O') O[i][j] = O[i-1][j] + O[i][j-1] - O[i-1][j-1]+ 1;
        if(!J[i][j]) J[i][j] = J[i-1][j] + J[i][j-1] - J[i-1][j-1];
        if(!I[i][j]) I[i][j] = I[i-1][j] + I[i][j-1] - I[i-1][j-1];
        if(!O[i][j]) O[i][j] = O[i-1][j] + O[i][j-1] - O[i-1][j-1];
    }
    /*
    cout<<'\n';
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++) cout<<J[i][j]<<' ';
        cout<<'\n';
    }
     */
    while(k--){
        cin>>sy>>sx>>ey>>ex;
        cout<<J[ey][ex]-J[sy-1][ex]-J[ey][sx-1]+J[sy-1][sx-1]<<' '<<O[ey][ex]-O[sy-1][ex]-O[ey][sx-1]+O[sy-1][sx-1]<<' ';
        cout<<I[ey][ex]-I[sy-1][ex]-I[ey][sx-1]+I[sy-1][sx-1]<<'\n';
    }
}