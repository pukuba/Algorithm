#include <bits/stdc++.h>

using namespace std;
int n,m,ans,_max;
vector<int> a,b;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>n>>m;
    for(int i=0,x; i<n; i++){
        cin>>x;
        if(x>0) a.push_back(x);
        if(x<0) b.push_back(x);
    }
    sort(a.rbegin(),a.rend());
    sort(b.begin(),b.end());
    for(int i=0; i<a.size(); i+=m){
        ans += a[i] << 1;
        _max = max(_max,a[i]);
    }
    for(int i=0; i<b.size(); i+=m){
        ans += abs(b[i]) << 1;
        _max = max(_max,abs(b[i]));
    }
    cout<<ans-_max<<'\n';
}
