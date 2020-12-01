#include <bits/stdc++.h>

using namespace std;
int board[777][777],n,m,x,y,z,temp[1444];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>n>>m;
    while(m--){
        cin>>x>>y>>z;
        for(int j=x; j<x+y; j++) temp[j]++;
        for(int i=x+y; i<n*2-1; i++) temp[i]+=2;
    }
    for(int i=0; i<n*2-1; i++){
        if(i<n) board[n-i][1] = temp[i];
        else board[1][i-n+2] = temp[i];
    }
    for(int i=2; i<=n; i++) for(int j=2; j<=n; j++) board[i][j] = max({board[i-1][j-1],board[i][j-1],board[i-1][j]});
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++) cout<<board[i][j]+1<<' ';
        cout<<'\n';
    }
}

//123