#include <bits/stdc++.h>

using namespace std;
double a,b;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>a>>b;
    cout<<int(abs(a/b-1)*2);
}