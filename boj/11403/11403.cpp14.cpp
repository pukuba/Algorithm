#include <bits/stdc++.h>

using namespace std;
int n;
bool check[101][101];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++) for(int j=1; j<=n; j++){
        bool x;
        cin>>x;
        if(x) check[i][j]=1;
    }
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                check[i][j] |= (check[i][k] + check[k][j] >= 2 ? 1 : 0);
            }
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++) cout<<check[i][j]<<' ';
        cout<<'\n';
    }
}
