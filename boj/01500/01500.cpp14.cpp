#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll n,m,x,y,ans = 1;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cout<<fixed;
    cout.precision(0);
    cin>>n>>m;
    x = n/m; y = n%m;
    for(int i=1; i<=m; i++){
        if(y > 0){
            ans *= (x+1);
        }
        else {
            ans *= x;
        }
        y--;
    }
    cout<<ans<<'\n';
}
