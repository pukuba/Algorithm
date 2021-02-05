#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
using namespace std;
int n,q;
bitset<2002> bit[2002];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++){
        string s;
        cin>>s;
        bit[i] = bitset<2002>(s);
    }
    cin>>q;
    while(q--){
        int a,b;
        cin>>a>>b;
        cout<<(bit[a]&bit[b]).count()<<'\n';
    }
}