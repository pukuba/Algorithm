#include <bits/stdc++.h>

using namespace std;
int a,b,c,k,day,h;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>a>>b>>c;
    cout<<(c-a)/(a-b) + 1 + ( 0 < (c-a)%(a-b));
}
//5 3 8 6 11 9 14