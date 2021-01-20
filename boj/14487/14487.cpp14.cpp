#include <bits/stdc++.h>

using namespace std;
int ans,_max,n;
int main(){
    cin>>n;
    while(n--){
        int x;
        cin>>x;
        ans+=x;
        _max=max(_max,x);
    }
    cout<<ans-_max<<'\n';
}
