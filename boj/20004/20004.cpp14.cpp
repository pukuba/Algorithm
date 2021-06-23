
#include <bits/stdc++.h>

using namespace std;
int n;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++){
        int flg = 0;
        for(int j=1; j<=i; j++){
            for(int k=j; k<=30; k+=i+1){
                if(k == 30) ++flg;
            }
        }
        if(!flg) cout<<i<<'\n';
    }
}