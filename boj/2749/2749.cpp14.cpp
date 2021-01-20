#include <bits/stdc++.h>

using namespace std;
int d[3000001];
const int mod =1000000;
unsigned long long n;
int main(){
    ios_base::sync_with_stdio(0),cout.tie(0);
    d[0]=0,d[1]=d[2]=1;
    for(int i=2; i<=3000000; i++,d[i]=d[i-1]+d[i-2],d[i]%=mod);
    cin>>n;
    cout<<d[n%1500000];
}
