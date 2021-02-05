#include <bits/stdc++.h>

using namespace std;
string s;
bool check(int k){
    for(int i=0; i<((s.size()-k)/2); i++) if(s[i] != s[s.size()-1-i-k]) return false;
    return true;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>s;
    if(!check(0)) cout<<s.size();
    else if(!check(1)) cout<<s.size()-1;
    else cout<<-1;
}