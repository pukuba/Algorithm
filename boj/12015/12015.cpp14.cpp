#include <bits/stdc++.h>

using namespace std;
long long a,d[1000001],cnt, len;
int main(){
    cin>>a;
    for(int i=0; i<a; i++){
        int x;
        cin>>x;
        auto lt = lower_bound(d, d+len, x);
        if(*lt == 0) len++;
        *lt = x;
    } 
    cout<<len<<'\n';
}
