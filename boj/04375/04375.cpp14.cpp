#include <bits/stdc++.h>

using namespace std;
int n;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    while(cin>>n){
        int here = 1, cnt = 1;
        here%=n;
        while(here){
            here = here * 10 + 1;
            here %= n;
            ++cnt;
        }
        cout<<cnt<<'\n';
    }
}
