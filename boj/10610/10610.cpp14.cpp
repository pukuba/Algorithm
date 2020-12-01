#include <bits/stdc++.h>

using namespace std;
string s;
int check;
bool cmp(char a,char b){return a>b;}
int main(){
    cin>>s;
    sort(s.begin(),s.end(),cmp);
    for(int i=0; i<s.size(); i++) check+=s[i]-'0';
    if(!(check%3) && s[s.size()-1]=='0') cout<<s;
    else cout<<-1;
}
