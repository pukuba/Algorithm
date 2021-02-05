#include <bits/stdc++.h>

using namespace std;
long long n,a[4001],b[4001],c[4001],d[4001],cnt;
vector<int> v1,v2;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0; i< n; i++) cin>>a[i]>>b[i]>>c[i]>>d[i];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            v1.push_back(a[i] + b[j]);
            v2.push_back(c[i] + d[j]);
        }
    }
    sort(v1.begin(),v1.end());
    for(int i=0; i< v1.size(); i++){
        int a = lower_bound(v1.begin(), v1.end(), v2[i]*-1) - v1.begin();
        int b = upper_bound(v1.begin(), v1.end(), v2[i]*-1) - v1.begin();
        //cout<<b<<' '<<a<<'\n';
        cnt += (b-a);
    }
    cout<<cnt<<'\n';
}
