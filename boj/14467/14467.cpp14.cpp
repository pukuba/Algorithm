#include <bits/stdc++.h>

using namespace std;
int n,x,y,ans;
vector<int> a[111];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>x>>y;
        a[x].push_back(y);
    }
    for(int i=1; i<=100; i++){
        for(int j=0; j<a[i].size(); j++){
            if(j == a[i].size()-1) break;
            if(a[i][j] != a[i][j+1]) ans++;
        }
    }
    cout<<ans;
}