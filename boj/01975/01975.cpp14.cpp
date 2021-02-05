#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll t,n;
ll ans[1010];
stack<int> stk;
void f(int x,int j){
    if(x){
        f(x/j,j);
        stk.push(x%j);
        //cout<<x%j;
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>t;
    for(int i=1; i<=1000; i++){
        for(int j=2; j<=1000; j++){
            f(i,j);
            while(stk.size() && stk.top() == 0){
                stk.pop();
                ans[i]++;
            }
            //cout<<'\n';
            while(stk.size()) stk.pop();
        }
    }
    while(t--){
        cin>>n;
        cout<<ans[n]<<'\n';
    }
}