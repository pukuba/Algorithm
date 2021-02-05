#include <bits/stdc++.h>

using namespace std;
int n;
vector<string> v;
set<char> s;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i=0; i<n; i++){
        string x;
        cin>>x;
        s.insert(x[0]);
    }
    if(s.size() > 1) cout<<0;
    else cout<<1;
}
