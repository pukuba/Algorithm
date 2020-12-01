#include <bits/stdc++.h>

using namespace std;
int d[1004][1004],_map[1004][1004],n,m;
bool in(int a,int b){
    return 1<=a && a<=n && 1<=b && b<=m;
}
int main(){
    cin>>n>>m;
    for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) cin>>_map[i][j];
    d[1][1]=_map[1][1];
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            d[i+1][j]=max(d[i+1][j],d[i][j]+_map[i+1][j]);
            d[i][j+1]=max(d[i][j+1],d[i][j]+_map[i][j+1]);
        }
    }
    cout<<d[n][m]<<'\n';
}

