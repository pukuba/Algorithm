#include <bits/stdc++.h>

using namespace std;
int n,id,arr[1111111];
vector<int> v;
map<int,int> m;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>arr[i];
        v.push_back(arr[i]);
    }
    sort(v.begin(),v.end());
    for(int i=0; i<v.size(); i++){
        if(m[v[i]]) continue;
        else m[v[i]] = ++id;
    }
    for(int i=1; i<=n; i++) cout<<m[arr[i]]-1<<' ';
}