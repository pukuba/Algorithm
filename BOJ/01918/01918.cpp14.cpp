#include <bits/stdc++.h>

using namespace std;
vector<char> v;
string s;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>s;
    for(char c : s){
        if(c == '(') v.push_back(c);
        else if('Z' >= c && c >= 'A') cout<<c;
        else if(c == '/' || c == '*'){
            while(v.size() && (v.back() == '/' || v.back() == '*')){
                cout<<v.back();
                v.pop_back();
            }
            v.push_back(c);
        }
        else if(c == ')'){
            while(v.back() != '('){
                cout<<v.back();
                v.pop_back();
            }
            v.pop_back();
        }
        else{
            while(v.size() && v.back() != '('){
                cout<<v.back();
                v.pop_back();
            }
            v.push_back(c);
        }
    }
    while(v.size()){cout<<v.back();v.pop_back();}
}