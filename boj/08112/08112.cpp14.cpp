#include <bits/stdc++.h>

using namespace std;
int t,a[1010101],b[1010101];
bool check[1010101];
void dfs(int here){
    if(here == -1) return;
    dfs(a[here]);
    cout<<b[here];
}
int main(){
    ios::sync_with_stdio(0);cin.tie(nullptr);
    cin>>t;
    while(t--){
        int k;
        cin>>k;
        memset(a,0,sizeof a);
        memset(b,0,sizeof b);
        memset(check,0,sizeof check);
        a[1%k] = -1,b[1%k] = check[1%k] = 1;
        queue<int> q;
        q.push(1%k);
        bool can = 0;
        while(q.size()){
            int here = q.front();
            if(!here){
                can = 1;
                break;
            }
            q.pop();
            int na = (here*10)%k, nb = (here*10+1)%k;
            if(!check[na]){
                check[na] = 1;
                a[na] = here;
                q.push(na);
            }
            if(!check[nb]){
                check[nb] = 1;
                a[nb] = here;
                b[nb] = 1;
                q.push(nb);
            }
        }
        if(can) dfs(0);
        else cout<<"BRAK";
        cout<<'\n';
    }
}