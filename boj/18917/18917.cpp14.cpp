#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll sum,xor_sum,t,x,y;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>t;
    while(t--){
        cin>>x;
        if(x==1){
            cin>>y;
            sum += y;
            xor_sum ^= y;
        }
        if(x==2){
            cin>>y;
            sum -= y;
            xor_sum ^= y;
        }
        if(x==3) cout<<sum<<'\n';
        if(x==4) cout<<xor_sum<<'\n';
    }
}