#include <bits/stdc++.h>

using namespace std;
string s;
vector<string> beat;
vector<int> ans;
int go(string s){
    int ret = 0;
    if(s.size() >= 3){
        if(s[0] == '1') ret += 4;
        if(s[1] == '1') ret += 2;
        if(s[2] == '1') ret += 1;
    }
    else if(s.size() >= 2){
        if(s[0] == '1') ret += 2;
        if(s[1] == '1') ret += 1;
    }
    else if(s.size() >= 1){
        if(s[0] == '1') ret += 1;
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>s;
    reverse(s.begin(),s.end());
    for(int i=0; i<s.size(); i+=3){
        string tmp = "";
        for(int j=i; j<i+3; j++){
            if(j >= s.size()) break;
            tmp += s[j];
        }
        reverse(tmp.begin(),tmp.end());
        beat.push_back(tmp);
    }
    reverse(beat.begin(),beat.end());
    for(string s : beat){
        ans.push_back(go(s));
    }
    for(int i : ans) cout<<i;
}