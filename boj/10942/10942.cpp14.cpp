#include <bits/stdc++.h>

using namespace std;
bool d[2004][2004];
int n,arr[2004];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>arr[i];
    }
    
    for(int i=1; i<2001; i++) d[i][i]=1;
    for(int i=1; i<2001; i++){
        if(arr[i]==arr[i+1]) d[i][i+1]=1;
    }
    for(int i=1; i<2001; i++){
        if(arr[i]==arr[i+2]) d[i][i+2]=1;
    }
    for(int i=2; i<2001; i++){
        for(int j=1; j< 2001 - i; j++){
            if(arr[j]==arr[j+i] && d[j+1][j+i-1]==1) d[j][j + i]=1;
        }
    }
    int t;
    cin>>t;
    while(t--){
        int s,e;
        cin>>s>>e;
        cout<<d[s][e]<<'\n';
    }
}
