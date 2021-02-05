#include <iostream>

using namespace std;
int main(){
    int a[44]={0,},ans=0;
    for(int i=1; i<=10; i++){
        int b;cin>>b;
        b%=42;
        a[b]=1;
    }
    for(int i=0; i<=43; i++){
        ans+=a[i];
    }
    cout<<ans<<'\n';
}