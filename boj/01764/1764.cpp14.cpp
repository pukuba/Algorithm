#include <bits/stdc++.h>

using namespace std;
map<string,int> _map1;
map<string,int> _map2;
vector<string> v,save;
int n,m,ans;
int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        v.push_back(s);
        _map1[s]=1;
    }
    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        _map2[s]=1;
    }
    for(int i=0; i<v.size(); i++){
        if(_map1[v[i]]==_map2[v[i]]&&_map1[v[i]]==1){
            save.push_back(v[i]);
            ans++;
        }
    }
    sort(save.begin(),save.end());
    cout<<ans<<'\n';
    for(auto i : save) cout<<i<<'\n';
}
