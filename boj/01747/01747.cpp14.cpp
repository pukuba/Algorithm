#include <bits/stdc++.h>

using namespace std;
bool prime[1111115];
int n;
bool check(int l){
    string s = to_string(l);
    for(int i=0; i<s.size()/2; i++) if(s[i] != s[s.size()-1-i]) return false;
    return true;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    prime[0] = prime[1] = true;
    for(int i=2; i*i<=1111114; i++) if(!prime[i]) for(int j=i*2; j<=1111114; j+=i) prime[j] = true;
    for(int i=1; i<=1111114; i++) if(!prime[i]) if(!check(i)) prime[i] = true;
    cin>>n;
    for(int i=n;;i++) if(!prime[i]){
        cout<<i;
        return 0;
    }
}