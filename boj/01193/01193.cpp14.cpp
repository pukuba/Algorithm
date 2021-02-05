#include <bits/stdc++.h>

using namespace std;
int n,k=1,l,r;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>n;
    while(n-k > 0){
        n-=k;
        k++;
    }
    n--;
    if(k&1) l = k-n, r = 1+n;
    else l = 1+n, r = k-n;
    cout<<l<<'/'<<r<<'\n';
}