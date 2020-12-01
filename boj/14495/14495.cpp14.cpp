#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll d[333]={0,1,1,1,2,3,},n;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>n;
    for(int i=5; i<=116; i++){
        d[i] = d[i-1] +  d[i-3];
    }
    cout<<d[n];
}
