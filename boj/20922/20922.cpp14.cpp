#include <bits/stdc++.h>

using namespace std;
int n,m,check[101010],ans,len;
vector<int> v;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    v.resize(n);
    for(int&x : v) cin>>x;
    int s=0,e=0;
    while(s<=e && e != n){
        if(check[v[e]] < m){
            check[v[e]]++;
            ++len;
            ans = max(len,ans);
            e++;
        }
        else{
            --len;
            check[v[s]]--;
            s++;
        }
    }
    cout<<ans;
}
