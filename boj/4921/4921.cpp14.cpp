#include <bits/stdc++.h>

using namespace std;
string s;
int t;
bool can(int idx){
    if(idx == s.size()-1) return 1;
    if(s[idx] == '1'){
        if(s[idx+1] == '4' || s[idx+1] == '5') return can(idx+1);
        return false;
    }
    if(s[idx] == '3'){
        if(s[idx+1]=='4'||s[idx+1]=='5') return can(idx+1);
        return false;
    }
    if(s[idx] == '4'){
        if(s[idx+1]=='3' || s[idx+1]=='2') return can(idx+1);
        return false;
    }
    if(s[idx] == '5'){
        if(s[idx+1]=='8') return can(idx+1);
        return false;
    }
    if(s[idx] == '6'){
        if(s[idx+1] =='3' || s[idx+1] == '2') return can(idx+1);
        return false;
    }
    if(s[idx] == '7'){
        if(s[idx+1] == '8') return can(idx+1);
        return false;
    }
    if(s[idx] == '8'){
        if(s[idx+1] == '7' || s[idx+1] == '6') return can(idx+1);
        return false;
    }
    return false;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    while(1){
        ++t;
        cin>>s;
        if(s == "0") return 0;
        if(s.size() > 2 && s[0] == '1' && s[s.size()-1] == '2'){
            if(can(0)) cout<<t<<". "<<"VALID"<<'\n';
            else cout<<t<<". "<<"NOT\n";
        }
        else cout<<t<<". "<<"NOT\n";
    }
}