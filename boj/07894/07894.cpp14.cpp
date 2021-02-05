#include <bits/stdc++.h>

using namespace std;
int n,ans,x;
double d[10000003];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>n;
    for(int i=1; i<=10000003; i++){
        d[i] = d[i-1] + log10(i);
    }
    while(n--){
        cin>>x;
        cout<<int(d[x])+1<<'\n';
    }
}