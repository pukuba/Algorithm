#include <bits/stdc++.h>

using namespace std;
int n,id,b[2222],a[2222],ans,fir;
vector<int> odd,even,adj[2222],prt;
bool prime[2222],check[2222],fir_odd,fir_even;
bool dfs(int here){
    check[here] = true;
    for(int next : adj[here]){
        if(next == 99999) continue;
        if(b[next] == -1 || !check[b[next]] && dfs(b[next])){
            a[here] = next;
            b[next] = here;
            return true;
        }
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>n;
    if(n&1){
        cout<<-1;
        return 0;
    }
    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        if(x&1) odd.push_back(x);
        else even.push_back(x);
        if(i == 1) fir = x;
    }
    prime[0] = prime[1] = true;
    for(int i=2; i*i<=2111; i++) if(!prime[i]) for(int j=i+i; j<=2111; j+=i) prime[j] = true;
    for(int i : odd) for(int j : even) if(!prime[i+j]) adj[i].push_back(j);
    for(int t=1; t<=50; t++){
        memset(b,-1,sizeof(b));
        memset(a,-1,sizeof(a));
        ans = 0;
        for(int i : odd){
            if(i == 99999) continue;
            memset(check,false,sizeof(check));
            if(dfs(i)) ans++;
        }
        if(ans == n/2){
            if(a[fir] == -1){
                prt.push_back(b[fir]);
                for(int i=0; i<adj[b[fir]].size(); i++) if(adj[b[fir]][i] == fir) adj[b[fir]][i] = 99999;
            }
            if(b[fir] == -1){
                prt.push_back(a[fir]);
                for(int i=0; i<adj[fir].size(); i++) if(adj[fir][i] == a[fir]) adj[fir][i] = 99999;
            }
        }
    }
    sort(prt.begin(),prt.end());
    if(prt.size()) for(int i : prt) cout<<i<<' ';
    else cout<<-1;
}