#include <bits/stdc++.h>

using namespace std;
priority_queue<int,vector<int>,less<int>> pq;
int n,cnt;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    while(n--){
        int x;
        cin>>x;
        pq.push(x);
        if(!x){
            cout<<pq.top()<<'\n';
            pq.pop();
        }
    }
}
