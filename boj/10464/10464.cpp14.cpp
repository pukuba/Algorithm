#include <bits/stdc++.h>

using namespace std;
int t,s,e,ret,from;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>t;
    while(t--){
        cin>>s>>e;
        ret = 0;
        for(;s<=e; s++){
            ret^=s;
            if(s&1) break;
        }
        from = s++;
        int cnt = (e-from)%4;
        while(cnt--){
            ret^=(e-(cnt));
        }cout<<ret<<'\n';
    }
}