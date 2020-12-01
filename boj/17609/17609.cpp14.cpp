#include <bits/stdc++.h>

using namespace std;
int t;
bool check(string s){
    for(int i=0; i<s.size()/2; i++) if(s[i] != s[s.size()-1-i]) return 0;
    return 1;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int ans = 0;
        for(int i=0; i<s.size()/2; i++){
            if(ans) break;
            if(s[i] != s[s.size()-1-i]){
                string temp1 = "",temp2;
                for(int j=0; j<s.size(); j++){
                    if(j != i) temp1 += s[j];
                    if(j != s.size()-1-i) temp2 += s[j];
                }
                if(check(temp2) || check(temp1)) ans = 1;
                else ans = 2;
            }
        }
        cout<<ans<<'\n';
    }
}