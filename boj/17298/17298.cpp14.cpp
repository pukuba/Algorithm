#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

using namespace std;
using ll = long long;
using pi = pair<int,int>;
int dx[8]={0,1,0,-1,-1,1,1,-1},dy[8]={-1,0,1,0,-1,-1,1,1};
int n,a[1010101],b[1010101];
stack<int> stk;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>a[i];
    }
    stk.push(0);
    for(int i=1; i<=n; i++){
        if(!stk.size()) stk.push(i);
        while(stk.size() && a[stk.top()] < a[i]){
            b[stk.top()] = a[i];
            stk.pop();
        }
        stk.push(i);
    }
    while(stk.size()){
        b[stk.top()] = -1;
        stk.pop();
    }
    for(int i=1; i<=n; i++) cout<<b[i]<<' ';
}