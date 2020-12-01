#include <bits/stdc++.h>

using namespace std;
int n,m,ans;
bool can[2002][2002];
int gcd(int a,int b){return b ? gcd(b,a%b) : a;}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    for(int i=n; i<=m; i++){
        for(int j=1; j<=i; j++){
            int k = gcd(i,j);
            if(!can[i/k][j/k]) can[i/k][j/k]=1,ans++;
        }
    }
    cout<<ans<<'\n';
}