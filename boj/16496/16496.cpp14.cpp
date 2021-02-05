#include <bits/stdc++.h>

using namespace std;
int n;
vector<string> v;
bool cmp(string a,string b){
    return a+b > b+a;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++){
        string s;
        cin>>s;
        v.push_back(s);
    }
    sort(v.begin(),v.end(),cmp);
    for(int i=0; i<v.size(); i++){
        if(!i && v[i][0] == '0'){
            cout<<0;
            return 0;
        }
        cout<<v[i];
    }
}
