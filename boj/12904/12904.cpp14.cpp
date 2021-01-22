#include <bits/stdc++.h>

using namespace std;
string a,b;
set<string> sets;
queue<string> q;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>a>>b;
    sets.insert(b);
    q.push(b);
    while(q.size()){
        string k = q.front();
        q.pop();
        if(k.back() == 'A'){
            k.pop_back();
            q.push(k);
            sets.insert(k);
            k+='A';
        }
        if(k.back() == 'B'){
            k.pop_back();
            reverse(k.begin(), k.end());
            sets.insert(k);
            q.push(k);
        }
    }
    cout<<sets.count(a);
}