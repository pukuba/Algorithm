#include <bits/stdc++.h>

using namespace std;
string s,temp;
int ans,check;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>s;
    for(char c : s){
        if(c == '+' || c == '-'){
            ans += check ? -stoi(temp) : stoi(temp);
            check |= c == '-';
            temp = "";
        }
        else temp += c;
    }
    cout<<ans + (check ? -stoi(temp) : stoi(temp))<<'\n';
}
