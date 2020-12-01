#include <bits/stdc++.h>

using namespace std;
int pf[322222],n,m,x,line,ans,last;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>n>>m;
    line = last = n;
    for(int i=0; i<n; i++){
        cin>>pf[i+1];
        pf[i+1] = !i ? pf[i+1] : min(pf[i+1],pf[i]);
    }
    for(int i=1; i<=m; i++){
        cin>>x;
        bool can = false;
        for(;line>=1;line--){
            if(pf[line]>=x){
                last = line;
                line--;
                can = true;
                break;
            }
        }
        if(!can) ans++;
    }
    if(ans) cout<<0;
    else cout<<last;
}