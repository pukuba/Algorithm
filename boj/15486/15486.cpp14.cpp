#include <bits/stdc++.h>

using namespace std;
int d[1500001];
int main(){
    int n;
    int day,money;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>day>>money;
        d[i+1]=max(d[i],d[i+1]);
        d[i+day]=max(d[i+day],d[i]+money);
    }
    cout<<d[n];
}
