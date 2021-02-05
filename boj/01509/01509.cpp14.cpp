#include <bits/stdc++.h>

using namespace std;
int d[2555][2555],x,y,ans,b[2555],inf;
string s;
int f(int here){
    if(b[here]!=inf) return b[here];
    if(s.size() <= here) return b[here] = 0;
    for(int i=here; i<s.size(); i++) if(d[here][i]) b[here] = min(b[here],1+f(i+1));
    return b[here];
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>s;
    memset(b,0x3f,sizeof(b));
    inf = b[1];
    for(int i=0; i<s.size(); i++) d[i][i] = 1;
    for(int i=0; i<s.size()-1; i++) d[i][i+1] = s[i] == s[i+1] ? 1 : 0;
    for(int i=1; i<s.size(); i++) for(int j=0; j<s.size()-i; j++) if(!(s[j]-s[j+i+1]) && d[j+1][j+i]) d[j][j+i+1] = 1;
    cout<<f(0);
}