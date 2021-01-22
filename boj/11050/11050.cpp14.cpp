#include <bits/stdc++.h>

using namespace std;
int d[22][22],n,m;
int main(){
    for(int i=1; i<=22; i++){
        d[i][1]=d[i][i]=1;
    }
    for(int i=1; i<=22; i++){
        for(int j=1; j<i; j++){
            if(d[i][j]==0) d[i][j]+=d[i-1][j-1]+d[i-1][j];
        }
    }
    cin>>n>>m;
    cout<<d[n+1][m+1];
}
