#include <bits/stdc++.h>

using namespace std;
int d[10001];
int main(){
    fill(d,d + 10001, 987654321);
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    d[0] = 0;
    for(int i=0; i<n; i++){
        for(int j=a[i]; j<=m; j++){
            if(d[j - a[i]] == 987654321)continue;
            d[j] = min(d[j],d[j - a[i]]+1);
        }
    }
    if(d[m] == 987654321) cout << -1 << "\n";
    else cout<<d[m]<<'\n';
}
