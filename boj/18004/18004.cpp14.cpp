#include <bits/stdc++.h>

using namespace std;
int n,m,ans;
int main(){
    cin>>n>>m;
    if(m > n) cout<<m-n;
    else{
        while(n>m){
            if(~n&1) n/=2;
            else n+=1;
            ans++;
        }
        cout<<ans+(m-n);
    }
}


