#include <bits/stdc++.h>

using namespace std;
long long n,t;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>t;
    while(t--){
        cin>>n;
        cout<<((n&(-n)) == n)<<'\n';
    }
}