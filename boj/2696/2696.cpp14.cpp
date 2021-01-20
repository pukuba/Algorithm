#include <bits/stdc++.h>

using namespace std;
int t,n,q;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> ans;
        priority_queue<int,vector<int>> maxpq;
        priority_queue<int,vector<int>,greater<>> minpq;
        for(int i=1; i<=n; i++){
            cin>>q;
            if(i&1) maxpq.push(q);
            else minpq.push(q);
            if(i>=2){
                int maxtop = maxpq.top(), mintop = minpq.top();
                if(maxtop > mintop){
                    maxpq.pop();minpq.pop();
                    maxpq.push(mintop);minpq.push(maxtop);
                }
            }
            if(i&1) ans.push_back(maxpq.top());
        }
        cout<<ans.size();
        for(int i=0; i<ans.size(); i++){
            if(!(i%10)) cout<<'\n';
            cout<<ans[i]<<' ';
        }
    }
}