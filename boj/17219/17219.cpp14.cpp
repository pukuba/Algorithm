#include <bits/stdc++.h>

using namespace std;
map<string,string> _map;
int n,m;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0; i<n; i++){
        string s1,s2;
        cin>>s1>>s2;
        _map[s1]=s2;
    }
    for(int i=0; i<m; i++){
        string s1;
        cin>>s1;
        cout<<_map[s1]<<'\n';
    }
}
