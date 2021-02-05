#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int arr[1010101],t,a,b;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    arr[0] = 1;
    for(int i=1; i<=1000000; i++){
        int x = i;
        while(x){
            if(x%10 == 0) arr[i]++;
            x/=10;
        }
        arr[i] += arr[i-1];
    }
    cin>>t;
    while(t--){
        cin>>a>>b;
        if(a == 0) cout<<arr[b]<<'\n';
        else cout<<arr[b]-arr[a-1]<<'\n';
    }
}
