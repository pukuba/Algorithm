#include <bits/stdc++.h>

using namespace std;
int n;
string s;
int mp[26];
stack<double> stk;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cout<<fixed;
    cout.precision(2);
    cin>>n>>s;
    for(int i=1,x; i<=n; i++){
        cin>>x;
        mp[i-1] = x;
    }
    for(char c : s){
        if(!('A'<=c && c<='Z')){
            double a = stk.top();
            stk.pop();
            double b = stk.top();
            stk.pop();
            if(c == '+') stk.push(b+a);
            if(c == '-') stk.push(b-a);
            if(c == '*') stk.push(b*a);
            if(c == '/') stk.push(b/a);
        }
        if('A'<=c && c<='Z'){
            stk.push(mp[c-'A']);
        }
    }
    cout<<stk.top();
}