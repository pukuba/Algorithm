#include <bits/stdc++.h>

using namespace std;
priority_queue<int,vector<int>,less<>> pq;
int n,ans,x,temp;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>n;
    while(n--){
        cin>>x;
        pq.push(x);
    }
    temp = pq.top();
    pq.pop();
    while(pq.size()){
        ans += temp * pq.top();
        temp = pq.top() + temp;
        pq.pop();
        pq.push(temp);
        if(pq.size() == 1) break;
        if(pq.size() >= 2){
            temp = pq.top();
            pq.pop();
        }
    }
    cout<<ans<<'\n';
}
