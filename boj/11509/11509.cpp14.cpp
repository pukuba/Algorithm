#include <bits/stdc++.h>

using namespace std;
int a[1010101],n,ans;
map<int,int> mp;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>a[i];
    }
    for(int i=1; i<=n; i++){
        if(mp[a[i]]){
            mp[a[i]]--;
            mp[a[i]-1]++;
        }
        else{
            ans++;
            mp[a[i]-1]++;
        }
    }
    cout<<ans<<'\n';
}