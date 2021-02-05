#include <iostream>

using namespace std;
int main(){
    int tc,ans=0;
    cin>>tc;
    while(tc--){
        int a,b;
        cin>>a>>b;
        if(a>b){
            ans+=b;
            continue;
        }
        ans+=b%a;
    }
    cout<<ans<<'\n';
}