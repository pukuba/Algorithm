#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll n,x,d[66][66];
ll f(string s){
    if(s.size() == x) return 1;
    ll &ret = d[s.size()][s.size() ? s.back() : 0];
    if(ret != -1) return ret;
    ret = 0;
    if(!s.size()) for(char i='0'; i<='9'; i++) ret += f(s+i);
    if(s.size()) for(char i=s.back(); i<='9'; i++) ret += f(s+i);
    return ret;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>x;
        memset(d,-1,sizeof(d));
        cout<<f("")<<'\n';
    }
}
