#include <bits/stdc++.h>

using namespace std;
string s;
int a,b;
char tmp;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>s;
    tmp = s.front();
    if(tmp == '0') a++;
    else b++;
    for(int i=1; i<s.size(); i++){
        if(tmp != s[i]){
            tmp = s[i];
            if(tmp == '0') a++;
            if(tmp == '1') b++;
        }
    }
    cout<<min(a,b);
}
