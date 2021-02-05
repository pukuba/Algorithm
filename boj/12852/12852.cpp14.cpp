#include <bits/stdc++.h>

using namespace std;
int d[1000001],n;
void _find(int x){
    if(x==n) cout<<x<<'\n';
    if(x==1) return;
    if(d[x-1]+1==d[x]){
        cout<<x-1<<'\n';
        _find(x-1);
    }
    else if(x%2==0 && d[x/2]+1==d[x]){
        cout<<x/2<<'\n';
        _find(x/2);
    }
    else if(x%3==0 && d[x/3]+1==d[x]){
        cout<<x/3<<'\n';
        _find(x/3);
    }
    return ;
}
int main(){
    fill(d,d+1000001, 987654321);
    cin>>n;
    d[1]=0;
    for(int i=2; i<=n; i++){
        d[i] = d[i - 1] + 1;
        if(i % 2 == 0) d[i] = min(d[i], d[i / 2] + 1);
        if(i % 3 == 0) d[i] = min(d[i], d[i / 3] + 1);
    }
    cout<<d[n]<<'\n';
    _find(n);
}
