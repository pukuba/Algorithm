#include <bits/stdc++.h>

using namespace std;
int n,d[10001111]={0,1,2,3,5,8};
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>n;
    for(int i=6; i<=10000011; i++){
        d[i]=d[i-1]+d[i-2];
        d[i]%=10;
    }
    cout<<d[n];
}