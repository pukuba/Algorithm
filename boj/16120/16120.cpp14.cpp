#include <bits/stdc++.h>

using namespace std;
string s,k;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>s;
    for(int i=0; i<s.size(); i++){
        k+=s[i];
        if(k.size()>=3) if(k[k.size()-1]=='P' && k[k.size()-2]=='A' && k[k.size()-3]=='P') for(int j=0; j<3; j++) k.pop_back();
        if(!k.size()){
            cout<<"NP";
            return 0;
        }
    }
    if(k == "P") cout<<"PPAP";
    else cout<<"NP";
}