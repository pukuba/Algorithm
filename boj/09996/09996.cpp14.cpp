#include <bits/stdc++.h>

using namespace std;
int t;
string reg;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>t>>reg;
    while(t--){
        string a;
        cin>>a;
        bool front = false, back = true;
        int idx = 0 ,rgIdx = 0;
        for(int i=0; i<a.size(); i++){
            if(reg[i] == '*'){
                rgIdx = i+1;
                idx = i;
                front = true;
                break;
            }
            if(reg[i] != a[i]){
                front = false;
                break;
            }
        }
        if(!front){
            cout<<"NE\n";
            continue;
        }
        int sz = a.size() - 1;
        for(int i=reg.size()-1; i>=rgIdx; i--){
            if(a[sz] != reg[i]){
                back = false;
                break;
            }
            sz--;
            if(i==rgIdx) sz++;
        }
        if(idx <= sz && back && front){
            cout<<"DA\n";
        } else {
            cout<<"NE\n";
        }
    }
}