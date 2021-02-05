#include <bits/stdc++.h>

using namespace std;
int d[3000001],mod=10000;
long long n;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    d[0]=0,d[1]=d[2]=1;
    for(int i=3; i<=15000; i++) d[i]=d[i-1]+d[i-2],d[i]%=mod;
    while(1){
        cin>>n;
        if(n==-1) return 0;
        cout<<d[n%15000]<<'\n';
    }
}
