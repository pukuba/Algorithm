#include <bits/stdc++.h>

using namespace std;
int n,arr[101010],sum,k;
void no(){
    cout<<"NO";
}
void yes(){
    cout<<"YES";
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>arr[i];
        k+= arr[i]/2;
        sum += arr[i];
    }
    sum%3 == 0 && sum/3 <= k ? yes() : no();
}