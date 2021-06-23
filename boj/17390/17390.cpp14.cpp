#include <bits/stdc++.h>

using namespace std;
int n,q,psum[300033];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>q;
    vector<int> a(n);
    for(int&x : a) cin>>x;
    sort(a.begin(),a.end());
    for(int i=0; i<a.size(); i++){
        psum[i + 1] += psum[i] + a[i];
    }
    while(q--){
        int s,e;
        cin>>s>>e;
        cout<<psum[e] - psum[s-1]<<'\n';
    }
}