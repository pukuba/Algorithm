#include <bits/stdc++.h>

using namespace std;
int a,b,c,u;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>a>>b>>c;
    u=c-b;
    if(u>0) cout<<a/u + 1;
    else cout<<-1;
}