#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int n,x,y;
vector<ll> v[111111];
ll ans;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>x>>y;
        v[y].push_back(x);
    }
    for(int i=1; i<=n; i++) sort(v[i].begin(),v[i].end());
    for(int i=1; i<=n; i++){
        for(int j=0; j<v[i].size(); j++){
            if(j == v[i].size()-1 && v[i].size()>=2) ans += abs(v[i][j] - v[i][j-1]);
            else if(!j && v[i].size()>=2) ans += abs(v[i][j] - v[i][j+1]);
            else if(v[i].size() == 1) break;
            else ans += min(abs(v[i][j-1] - v[i][j]),abs(v[i][j] - v[i][j+1]));
        }
    }
    cout<<ans<<'\n';
}