#include <bits/stdc++.h>
using ull = unsigned long long;
using namespace std;
vector<string> v;
ull n,temp=1,t=0,cnt,p;
string s;
bool cmp(string a,string b){
    if(a.size() != b.size()) return a.size()<b.size();
    for(int k = 0; k<a.size(); k++){
        if(a[k] == b[k]) continue;
        return a < b;
    }
    return a<b;
}
ull gcd(ull a,ull b){return b ? gcd(b,a%b) : a; }
void go(string s){
    if(s.size() > 4) return;
    v.push_back(s);
    for(int i=0; i<=9; i++) go(s + to_string(i));
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>s;
    for(int i=0; i<s.size(); i++){
        if(s[i]=='0') continue;
        temp = ((temp * (s[i]-'0')) / gcd(temp,ull(s[i]-'0')));
    }
    p = stoull(s);
    if(!(p%temp)){
        cout<<p;
        return 0;
    }
    for(int i=0; i<=9; i++) go(to_string(i));
    sort(v.begin(),v.end(),cmp);
    while(1){
        string keep = s + v[cnt];
        cnt++;
        if(!(stoull(keep) % temp)){
            cout<<keep<<'\n';
            return 0;
        }
    }
}