#include <bits/stdc++.h>

using namespace std;
string s,a,ans;
int main(){
    cin>>s>>a;
    for(int i=0; i<s.size(); i++){
        ans+=s[i];
        int combo=0;
        for(int j=0; j<a.size(); j++){
            if(ans.size()-j<0) break;
            if(ans[ans.size()-j - 1] == a[a.size()-j - 1]) combo++;
        }
        if(combo==a.size()){
            for(int j=0; j<a.size(); j++){
                ans.pop_back();
            }
        }
    }
    if(ans.size()) cout<<ans<<'\n';
    else cout<<"FRULA"<<'\n';
}
