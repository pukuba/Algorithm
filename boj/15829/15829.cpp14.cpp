#include <bits/stdc++.h>

using namespace std;
long long const mod =1234567891;
long long ans,n;
long long cal(string s,int idx){
    return (s[idx]-'a'+1)*pow(31,idx);
}
int main(){
    cin>>n;
    string s1;
    cin>>s1;
    for(int i=0; i<n; i++){
        ans+=cal(s1,i);
        ans%=mod;
    }cout<<ans<<'\n';
}
