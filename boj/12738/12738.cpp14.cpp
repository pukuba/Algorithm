#include <bits/stdc++.h>

using namespace std;
int d[1000001],n,len;
int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        auto lt = lower_bound(d, d+len, x);
        if(*lt == 0) len++;
        *lt=x;
    }
    cout<<len;
}
