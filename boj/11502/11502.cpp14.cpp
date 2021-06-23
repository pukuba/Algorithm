#include <bits/stdc++.h>
#define pb(x) push_back(x)

using namespace std;
int t;
bool prime[1010];
vector<int> v,ans[1000];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    for(int i=2; i<=1000; i++){
        if(!prime[i]){
            v.push_back(i);
            for(int j=i+i; j<=1000; j+=i){
                prime[j] = true;
            }
        }
    }
    for(int i=1; i<=999; i+=2){
        bool flg = false;
        for(int p1 : v){
            if(flg) break;
            for(int p2 : v){
                if(flg) break;
                for(int p3 : v){
                    if(flg) break;
                    if(p1 + p2 + p3 == i){
                        ans[i].pb(p1);
                        ans[i].pb(p2);
                        ans[i].pb(p3);
                        flg = true;
                    }
                }
            }
        }
        sort(ans[i].begin(),ans[i].end());
    }
    cin>>t;
    while(t--){
        int x;
        cin>>x;
        for(int i : ans[x]){
            cout<<i<<' ';
        } cout<<'\n';
    }
}