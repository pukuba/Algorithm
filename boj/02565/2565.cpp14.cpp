#include <bits/stdc++.h>

using namespace std;
long long a,d[1000001],cnt, len;
vector<pair<int,int> > v;
int main(){
    cin>>a;
    for(int i=0; i<a; i++){
        int x,y;
        cin>>x>>y;
        v.push_back({x,y});
    }
    sort(v.begin(),v.end());
    for(int i=0; i<a; i++){
        auto lt = lower_bound(d, d+len, v[i].second);
        if(*lt == 0) len++;
        *lt = v[i].second;
    }
    cout<<a-len<<'\n';
}
